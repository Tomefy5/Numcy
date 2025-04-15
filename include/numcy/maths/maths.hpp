#pragma once

#include "../array/array.hpp"

namespace numcy {
    float sum(const array<float>& arr);
    float sum(const array<int>& arr);
    float sum(const array<double>& arr);
}

#include "maths.tpp"