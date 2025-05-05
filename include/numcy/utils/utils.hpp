#pragma once

#include "../core/array.hpp"
#include <vector>

namespace numcy  {
    template <typename T>
    array<T> fill_with_number(const std::vector<size_t>& shape, T number);
    array<float> zeros(const std::vector<size_t>& shape);
    array<float> ones(const std::vector<size_t>& shape);
    template <typename T>
    array<T> add(const array<T> nd_arr,const array<T> other);
    template <typename T>
    array<T> sub(const array<T> nd_arr,const array<T> other);
    template <typename T>
    array<T> mul(const array<T> nd_arr,const array<T> other);
    template <typename T>
    array<T> div(const array<T> nd_arr,const array<T> other);
}


#include "utils.tpp"