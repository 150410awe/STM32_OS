#pragma once

/**
 * interval - 数学区间
 */

#include "internal/foundation_type.h"

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
    /**
     * contains - 判断值是否在区间内
     * @param value 值
     * @return 是否在区间内 在 true，不在 false
     */
    constexpr bool contains(const T& value) const {
        return start <= value && value <= end;
    }
};

using int_interval = interval<max_int_t>;
using float_interval = interval<float>;