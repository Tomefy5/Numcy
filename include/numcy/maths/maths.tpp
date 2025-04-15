#include "../array/array.hpp"

namespace numcy {

    // sum function and its overloads
    float sum(const array<float>& arr) {
        float sum_val = 0;
        for(size_t i = 0; i < arr.data_.size(); i++) {
            sum_val += arr.data_[i];
        }
        return sum_val;
    }

    float sum(const array<double>& arr) {
        float sum_val = 0;
        for(size_t i = 0; i < arr.data_.size(); i++) {
            sum_val += arr.data_[i];
        }
        return sum_val;
    }

    float sum(const array<int>& arr) {
        float sum_val = 0;
        for(size_t i = 0; i < arr.data_.size(); i++) {
            sum_val += arr.data_[i];
        }
        return sum_val;
    }
}