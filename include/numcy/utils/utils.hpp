#pragma once

#include "../array/array.hpp"
#include <vector>

namespace numcy  {
    template <typename T>
    array<T> fill_with_number(const std::vector<size_t>& shape, T number);
    array<float> zeros(const std::vector<size_t>& shape);
    array<float> ones(const std::vector<size_t>& shape);
}


#include "utils.tpp"