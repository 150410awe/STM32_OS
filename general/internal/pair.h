#pragma once

#include "foundation_type.h"

namespace general {
    template<typename T, typename U>
    struct pair {
        T first;
        U second;
        pair(T first, U second) : first{ first }, second{ second } {}
        pair() = default;
    };
}