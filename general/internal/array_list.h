#pragma once

#include "array.h"
#include "foundation_type.h"
#include "array_queue.h"

namespace general {
    template<typename T, size_t N>
    struct array_list {
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using size_type = size_t;
        using pointer = T*;
        using const_pointer = const T*;
        
        array<T, N> data;
        size_t count = 0;
        array<size_t, N> list_table;     // 使用 size_t 替代 subscript_t
        general::array_queue<size_t, N> free_queue;

        array_list() {
            // 初始化空闲队列
            for (size_t i = 0; i < N; ++i) 
                free_queue.push(i);
        }
        
        /**
         * push_back - 在列表末尾添加元素
         */
        bool push_back(const T& value) {
            if (full()) 
                return false;
            
            // 检查空闲队列是否为空
            if (free_queue.empty())
                return false;
                
            size_t index{ free_queue.front() };
            free_queue.pop();
            
            data[index] = value;
            list_table[count] = index;
            count++;
            
            return true;
        }
        
        /**
         * pop_back - 删除列表末尾元素
         */
        bool pop_back() {
            if (empty()) 
                return false;
            
            size_t index { list_table[count - 1] };
            free_queue.push(index);
            count--;
            return true;
        }
        
        /**
         * insert - 在指定位置插入元素
         */
        bool insert(size_t position, const T& value) {
            if (full() || position > count) 
                return false;
            
            if (position == count) 
                return push_back(value);
            
            if (free_queue.empty())
                return false;
                
            size_t new_index { free_queue.front() };
            free_queue.pop();
            
            // 移动逻辑索引
            for (size_t i = count; i > position; --i) 
                list_table[i] = list_table[i - 1];
            
            data[new_index] = value;
            list_table[position] = new_index;
            count++;
            
            return true;
        }
        
        /**
         * erase - 删除指定位置的元素
         */
        bool erase(size_t position) {
            if (empty() || position >= count) 
                return false;
            
            if (position == count - 1) 
                return pop_back();
            
            
            size_t index { list_table[position] };
            free_queue.push(index);
            
            for (size_t i = position; i < count - 1; ++i) 
                list_table[i] = list_table[i + 1];
            
            count--;
            return true;
        }
        
        /**
         * operator[] - 访问指定位置的元素
         */
        T& operator[](size_t position) {
            return data[list_table[position]];
        }
        
        /**
         * operator[] - const版本
         */
        const T& operator[](size_t position) const {
            return data[list_table[position]];
        }
        
        /**
         * at - 带边界检查的访问
         */
        T& at(size_t position) {
            if (position >= count) 
                return operator[](0); // error
            return operator[](position);
        }
        
        /**
         * at - const版本
         */
        const T& at(size_t position) const {
            if (position >= count) 
                return operator[](0); // error
            return operator[](position);
        }
        
        /**
         * size - 返回元素个数
         */
        size_t size() const {
            return count;
        }
        
        /**
         * empty - 检查是否为空
         */
        bool empty() const {
            return count == 0;
        }
        
        /**
         * clear - 清空列表
         */
        void clear() {
            for (size_t i = 0; i < count; ++i)
                free_queue.push(list_table[i]);
            count = 0;
        }
        
        /**
         * front - 访问第一个元素
         */
        T& front() {
            if (empty())
            // 先这样
                return operator[](0); // error 

            return operator[](0);
        }
        
        /**
         * front - const版本
         */
        const T& front() const {
            if (empty()) 
            // 先这样
                return operator[](0); // error
            return operator[](0);
        }
        
        /**
         * back - 访问最后一个元素
         */
        T& back() {
            if (empty()) 
            // 先这样
                return operator[](0); // error    
            return operator[](count - 1);
        }
        
        /**
         * back - const版本
         */
        const T& back() const {
            if (empty()) 
            // 先这样
                return operator[](0); // error    
            return operator[](count - 1);
        }

        bool full() const {
            return count >= N;
        }

        // 正确的迭代器实现
        class iterator {
        public:
            iterator(array_list* l, size_t p) : list(l), pos(p) {}
            
            T& operator*() { return (*list)[pos]; }
            T* operator->() { return &(*list)[pos]; }
            
            iterator& operator++() {
                pos++;
                return *this;
            }
            
            iterator operator++(int) {
                iterator tmp{ *this };
                pos++;
                return tmp;
            }
            
            bool operator==(const iterator& other) const {
                return list == other.list && pos == other.pos;
            }
            
            bool operator!=(const iterator& other) const {
                return !(*this == other);
            }
            
            size_t get_pos() const {
                return pos;
            }
        private:
            array_list* list;
            size_t pos;
        };
        
        iterator begin() {
            return iterator { this, 0 };
        }
        
        iterator end() {
            return iterator { this, count };
        }
    };
}