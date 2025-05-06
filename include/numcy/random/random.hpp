#pragma once

#include "../core/array.hpp"
#include <vector>

namespace numcy::random {
    numcy::array<float> rand(std::vector<size_t> shape);
    numcy::array<float> randn(std::vector<size_t> shape);
    numcy::array<float> randint(int low, int high, std::vector<size_t> shape);
}

#include "random.tpp"