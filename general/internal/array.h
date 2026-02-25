#pragma once

#include "foundation_type.h"

namespace general {
    template<typename T, size_t N>
    struct array {
        T data[N];

        constexpr T& operator[](size_t index) {
            if (index >= N) 
                return data[0]; // error

            return data[index];
        }
        constexpr const T& operator[](size_t index) const {
            if (index >= N) 
                return data[0]; // error

            return data[index];
        }
        constexpr size_t size() const {
            return N;
        }
        constexpr T* begin() {
            return data;
        }
        constexpr const T* begin() const {
            return data;
        }
        constexpr T* end() {
            return data + N;
        }
        constexpr const T* end() const {
            return data + N;
        }
    };
}