#pragma once

#include "array.h"
#include "foundation_type.h"


namespace general {
    template<typename T, size_t N>
    struct array_queue {
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using size_type = size_t;
        using pointer = T*;
        using const_pointer = const T*;
        
        array<T, N> data;
        size_t count = 0;
        subscript_t head = 0;
        subscript_t tail = 0;
        
        /**
         * push - 在队尾添加元素
         */
        bool push(const T& value) {
            if (full()) 
                return false; // 队列已满
            
            data[tail] = value;
            tail = (tail + 1) % N;
            count++;
            
            return true;
        }

        /**
         * pop - 从队头移除元素
         */
        void pop() {
            if (empty()) 
                return; // 队列为空
            
            head = (head + 1) % N;
            count--;
        }
        
        /**
         * front - 访问队头元素
         */
        T& front() {
            return data[head];
        }
        
        /**
         * front - const版本
         */
        const T& front() const {
            return data[head];
        }
        
        /**
         * back - 访问队尾元素
         */
        T& back() {
            subscript_t back_index = (tail == 0) ? (N - 1) : (tail - 1);
            return data[back_index];
        }
        
        /**
         * back - const版本
         */
        const T& back() const {
            subscript_t back_index = (tail == 0) ? (N - 1) : (tail - 1);
            return data[back_index];
        }
        
        /**
         * empty - 检查是否为空
         */
        bool empty() const {
            return count == 0;
        }
        
        /**
         * full - 检查是否已满
         */
        bool full() const {
            return count >= N;
        }
        
        /**
         * size - 返回元素个数
         */
        size_t size() const {
            return count;
        }
        
        /**
         * max_size - 返回最大容量
         */
        size_t max_size() const {
            return N;
        }
        
        /**
         * clear - 清空队列
         */
        void clear() {
            count = 0;
            head = 0;
            tail = 0;
        }
    };
    
}