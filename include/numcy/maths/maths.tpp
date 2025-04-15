#include "../array/array.hpp"

namespace numcy {
    float sum(const array<float>& arr) {
        float sum_val = 0;
        for(size_t i = 0; i < arr.data_.size(); i++) {
            sum_val += arr.data_[i];
        }
        return sum_val;
    }
}