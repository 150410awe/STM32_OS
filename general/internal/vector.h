#pragma once

#include "foundation_type.h"
#include "type_traits.h"
#include "../../kernel_include/memory/call.h"

namespace general {
    using namespace kernel::call;
    template <typename T>
    struct vector {
        T* data;
        u32 size;
        u32 capacity;
        
        vector() : data(nullptr), size(0), capacity(0) {}
        vector(size_t capacity) : data(static_cast<T*>(malloc(capacity * sizeof(T)))), size(0), capacity(capacity) { }
        T& operator[](u32 index) { return data[index]; }
        const T& operator[](u32 index) const { return data[index]; }

        ~vector() { free(data); }

        void push_back(const T& value) {
            if (size >= capacity)
                reserve(capacity * 2 + 1);
            data[size] = value;
            ++size;
        }

        void reserve(size_t new_capacity) {
            if (new_capacity > capacity) {
                T* new_data = static_cast<T*>(malloc(new_capacity * sizeof(T)));
                for (u32 i = 0; i < size; ++i)
                    new_data[i] = data[i];
                free(data);
                data = new_data;
            }
            else if (new_capacity < capacity) 
                for (u32 i = size; i < capacity; ++i)
                    data[i].~T();
            
            capacity = new_capacity;
        }

        void delete_data(subscript_t index) {
            if (index < size) {
                data[index].~T();
                for (u32 i = index; i < size - 1; ++i)
                    data[i] = data[i + 1];
                --size;
            }
        }

        void clear() {
            for (u32 i = 0; i < size; ++i)
                data[i].~T();
            size = 0;
        }
    };
}