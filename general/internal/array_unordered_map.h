#pragma once

#include "pair.h"
#include "array.h"

namespace general {
    /**
     * array_unordered_map - 基于数组的无序映射容器, key 类型为 max_int_t. 
     * 这就是怎么设计的. 只支持 max_int_t 类型的键.
     */
    template<typename T, size_t capacity>
    struct array_unordered_map {
        using key_type = max_int_t;      // 固定为 max_int_t 类型的键
        using mapped_type = T;           // 值类型
        using value_type = pair<key_type, mapped_type>;
        using reference = value_type&;
        using const_reference = const value_type&;
        using size_type = size_t;
        using pointer = value_type*;
        using const_pointer = const value_type*;
        
        // 使用特殊值表示空槽（假设 max_int_t 可以表示比实际键范围更大的值）
        static constexpr key_type EMPTY_KEY = max_int_t(~0);  // 全1的位模式
        static constexpr key_type TOMBSTONE = max_int_t(~1);  // 用于标记已删除
        
        array<value_type, capacity> data;
        size_type count = 0;
        
        // 简单的迭代器实现
        class iterator {
            array_unordered_map* map;
            size_type pos;
            
        public:
            iterator(array_unordered_map* m, size_type p) : map(m), pos(p) {}
            
            value_type& operator*() { return map->data[pos]; }
            value_type* operator->() { return &map->data[pos]; }
            
            iterator& operator++() {
                // 跳到下一个有效元素（不是 EMPTY_KEY 也不是 TOMBSTONE）
                do 
                    pos++;
                while (pos < capacity && 
                        (map->data[pos].first == map->EMPTY_KEY || 
                         map->data[pos].first == map->TOMBSTONE));
                return *this;
            }
            
            bool operator!=(const iterator& other) const {
                return pos != other.pos;
            }
            bool operator==(const iterator& other) const {
                return pos == other.pos;
            }
        };
        
        iterator begin() {
            for (size_type i = 0; i < capacity; ++i) 
                if (data[i].first != EMPTY_KEY && data[i].first != TOMBSTONE) 
                    return iterator{ this, i };
                
            return end();
        }
        
        iterator end() {
            return iterator{ this, capacity };
        }

        array_unordered_map() {
            // 初始化所有槽为空
            for (size_type i = 0; i < capacity; ++i) 
                data[i].first = EMPTY_KEY;
        }
        
        /**
         * hash_function - 专为 max_int_t 设计的哈希函数
         * 处理负数键的情况
         */
        size_type hash_function(const key_type k) const {
            // 确保处理负数键
            size_type h{ static_cast<size_type>(k >= 0 ? k : -k) };
            return h % capacity;
        }
        
        /**
         * find - 查找键对应的指针
         */
        iterator find(const key_type k) {
            size_type index{ hash_function(k) };
            size_type start{ index };
            
            do {
                if (data[index].first == k) 
                    return iterator{ this, index };
                
                // 遇到 EMPTY_KEY 说明后面不可能有该键（线性探测的终止条件）
                if (data[index].first == EMPTY_KEY) 
                    return end();
                
                index = (index + 1) % capacity;
            } while (index != start);
            
            return end();
        }
        
        /**
         * find - const版本
         */
        iterator find(const key_type k) const {
            size_type index{ hash_function(k) };
            size_type start{ index };
            
            do {
                if (data[index].first == k) 
                    return iterator{ this, index };
                
                if (data[index].first == EMPTY_KEY) 
                    return end();
                
                index = (index + 1) % capacity;
            } while (index != start);
            
            return end();
        }
        
        /**
         * emplace - 插入键值对
         */
        bool emplace(const key_type k, const T& v) {
            if (full()) 
                return false;
            
            // 检查键是否已存在
            if (find(k) != end()) 
                return false;
            
            
            size_type index{ hash_function(k) };
            
            // 寻找空位置（EMPTY_KEY 或 TOMBSTONE）
            while (data[index].first != EMPTY_KEY && 
                   data[index].first != TOMBSTONE) 
                index = (index + 1) % capacity;
            
            data[index] = {k, v};
            count++;
            return true;
        }
        
        /**
         * erase - 删除键值对
         */
        bool erase(const key_type k) {
            iterator found = find(k);
            if (found == end()) 
                return false;
            
            
            // 使用 TOMBSTONE 标记删除，保留占位但标记为无效
            found->first = TOMBSTONE;
            count--;
            return true;
        }
        
        bool erase(const value_type& p) {
            return erase(p.first);
        }
        
        /**
         * operator[] - 访问或插入键值对
         */
        T& operator[](const key_type k) {
            iterator found = find(k);
            if (found != end()) 
                return *end();

            return *found;
        }
        
        /**
         * size - 返回元素个数
         */
        size_type size() const {
            return count;
        }
        
        /**
         * empty - 检查是否为空
         */
        bool empty() const {
            return count == 0;
        }
        
        /**
         * max_size - 返回最大容量
         */
        size_type max_size() const {
            return capacity;
        }
        
        /**
         * full - 检查是否已满
         */
        bool full() const {
            return count >= capacity;
        }
        
        /**
         * clear - 清空哈希表
         */
        void clear() {
            for (size_type i = 0; i < capacity; ++i) 
                data[i].first = EMPTY_KEY;
            
            count = 0;
        }
        
    };
}