#include <iostream>

#include "../core/array.hpp"
#include <vector>

namespace numcy {
template <typename T>
array<T> fill_with_number(const std::vector<size_t> &shape, T number) {
  array<T> arr;

  // set shape
  arr.shape_ = shape;

  // Compute data size
  size_t data_size = 1;
  for (auto dim : shape) {
    data_size *= dim;
  }

  // fill with 0
  arr.data_.assign(data_size, T(number));

  // determinate dim
  arr.ndim = shape.size();

  // determinate strides
  size_t stride = 1;
  arr.strides_.resize(shape.size());
  for (int i = (arr.shape_.size() - 1); i >= 0; i--) {
    arr.strides_.insert(arr.strides_.begin(), stride);
    stride *= arr.shape_[i];
  }

  return arr;
}

array<float> zeros(const std::vector<size_t> &shape) {
  array<float> array_zeros = fill_with_number(shape, 0.0f);
  return array_zeros;
}

array<float> ones(const std::vector<size_t> &shape) {
  array<float> array_ones = fill_with_number(shape, 1.0f);
  return array_ones;
}

// elementary operations
template <typename T>
array<T> add(const array<T> nd_arr, const array<T> other) {
  if (nd_arr.shape_ != other.shape_) {
    std::cerr << "Error: must have the same shape" << std::endl;
    exit(EXIT_FAILURE);
  }

  array<T> result;

  result.data_.resize(nd_arr.data_.size());
  result.shape_ = nd_arr.shape_;
  result.ndim = nd_arr.ndim;
  result.strides_ = nd_arr.strides_;

  for (int i = 0; i < nd_arr.data_.size(); i++) {
    result.data_[i] = nd_arr.data_[i] + other.data_[i];
  }

  return result;
}
template <typename T>
array<T> sub(const array<T> nd_arr, const array<T> other) {
  if (nd_arr.shape_ != other.shape_) {
    std::cerr << "Error: must have the same shape" << std::endl;
    exit(EXIT_FAILURE);
  }

  array<T> result;

  result.data_.resize(nd_arr.data_.size());
  result.shape_ = nd_arr.shape_;
  result.ndim = nd_arr.ndim;
  result.strides_ = nd_arr.strides_;

  for (int i = 0; i < nd_arr.data_.size(); i++) {
    result.data_[i] = nd_arr.data_[i] - other.data_[i];
  }

  return result;
}
template <typename T>
array<T> mul(const array<T> nd_arr, const array<T> other) {
  if (nd_arr.shape_ != other.shape_) {
    std::cerr << "Error: must have the same shape" << std::endl;
    exit(EXIT_FAILURE);
  }

  array<T> result;

  result.data_.resize(nd_arr.data_.size());
  result.shape_ = nd_arr.shape_;
  result.ndim = nd_arr.ndim;
  result.strides_ = nd_arr.strides_;

  for (int i = 0; i < nd_arr.data_.size(); i++) {
    result.data_[i] = nd_arr.data_[i] * other.data_[i];
  }

  return result;
}
template <typename T>
array<T> div(const array<T> nd_arr, const array<T> other) {
  if (nd_arr.shape_ != other.shape_) {
    std::cerr << "Error: must have the same shape" << std::endl;
    exit(EXIT_FAILURE);
  }

  array<T> result;

  result.data_.resize(nd_arr.data_.size());
  result.shape_ = nd_arr.shape_;
  result.ndim = nd_arr.ndim;
  result.strides_ = nd_arr.strides_;

  for (int i = 0; i < nd_arr.data_.size(); i++) {
    result.data_[i] = nd_arr.data_[i] / other.data_[i];
  }

  return result;
}
} // namespace numcy