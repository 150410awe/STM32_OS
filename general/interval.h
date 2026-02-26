#pragma once

/**
 * interval - 数学区间
 */

#include "internal/foundation_type.h"

namespace general {
/**
 * interval - 数学区间
 * @note 全闭区间
 */
template<typename T>
struct interval {
    T start;
    T end;
    /**
     * interval - 构造函数
     * @param start 区间开始
     * @param end 区间结束
     */
    constexpr interval(T start, T end) : start(start), end(end) {}
    constexpr interval() {}
    /**
     * contains - 判断值是否在区间内
     * @param value 值
     * @return 是否在区间内 在 true，不在 false
     */
    constexpr bool contains(const T& value) const {
        return start <= value && value <= end;
    }
    constexpr interval(const interval& set_interval) = default;
    constexpr interval(interval&& set_interval) = default;
    constexpr interval& operator=(const interval& set_interval) = default;
    constexpr interval& operator=(interval&& set_interval) = default;
};
}

using int_interval = general::interval<max_int_t>;
using uint_interval = general::interval<max_uint_t>;
using float_interval = general::interval<float>;