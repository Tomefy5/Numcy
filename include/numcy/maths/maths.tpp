#pragma once
#include "../core/array.hpp"
#include <cmath>
#include <optional>

namespace numcy {

// Trigos and other maths

template <typename M> array<M> sin(array<M> arr) {
  array<M> result;
  result.shape_ = arr.shape_;
  result.ndim = arr.ndim;
  result.size = arr.size;
  result.strides_ = arr.strides_;

  result.data_.resize(arr.data_.size());

  for (size_t i = 0; i < arr.data_.size(); i++) {
    if (arr.data_[i] > 1 || arr.data_[i] < -1) {
      std::cerr << "Angle's value must be between 1 and -1" << std::endl;
      exit(EXIT_FAILURE);
    }
    result.data_[i] = std::sin(arr.data_[i]);
  }

  return result;
}

template <typename M> array<M> cos(array<M> arr) {
  array<M> result;
  result.shape_ = arr.shape_;
  result.ndim = arr.ndim;
  result.size = arr.size;
  result.strides_ = arr.strides_;

  result.data_.resize(arr.data_.size());

  for (size_t i = 0; i < arr.data_.size(); i++) {
    if (arr.data_[i] > 1 || arr.data_[i] < -1) {
      std::cerr << "Angle's value must be between 1 and -1" << std::endl;
      exit(EXIT_FAILURE);
    }
    result.data_[i] = std::cos(arr.data_[i]);
  }

  return result;
}

template <typename M> array<M> tan(array<M> arr) {
  array<M> result;
  result.shape_ = arr.shape_;
  result.ndim = arr.ndim;
  result.size = arr.size;
  result.strides_ = arr.strides_;

  result.data_.resize(arr.data_.size());

  for (size_t i = 0; i < arr.data_.size(); i++) {
    if (arr.data_[i] > 1 || arr.data_[i] < -1) {
      std::cerr << "Angle's value must be between 1 and -1" << std::endl;
      exit(EXIT_FAILURE);
    }
    result.data_[i] = std::tan(arr.data_[i]);
  }

  return result;
}

template <typename M> array<M> exp(array<M> arr) {
  array<M> result;
  result.shape_ = arr.shape_;
  result.ndim = arr.ndim;
  result.size = arr.size;
  result.strides_ = arr.strides_;

  result.data_.resize(arr.data_.size());

  for (size_t i = 0; i < arr.data_.size(); i++) {
    result.data_[i] = std::exp(arr.data_[i]);
  }

  return result;
}

template <typename M> array<M> log(array<M> arr) {
  array<M> result;
  result.shape_ = arr.shape_;
  result.ndim = arr.ndim;
  result.size = arr.size;
  result.strides_ = arr.strides_;

  result.data_.resize(arr.data_.size());

  for (size_t i = 0; i < arr.data_.size(); i++) {
    result.data_[i] = std::log(arr.data_[i]);
  }

  return result;
}

template <typename M> array<M> abs(array<M> arr) {
  array<M> result;
  result.shape_ = arr.shape_;
  result.ndim = arr.ndim;
  result.size = arr.size;
  result.strides_ = arr.strides_;

  result.data_.resize(arr.data_.size());

  for (size_t i = 0; i < arr.data_.size(); i++) {
    result.data_[i] = std::abs(arr.data_[i]);
  }

  return result;
}

template <typename M> array<M> pow(array<M> arr, double exponent) {
  array<M> result;
  result.shape_ = arr.shape_;
  result.ndim = arr.ndim;
  result.size = arr.size;
  result.strides_ = arr.strides_;

  result.data_.resize(arr.data_.size());

  for (size_t i = 0; i < arr.data_.size(); i++) {
    result.data_[i] = std::pow(arr.data_[i], exponent);
  }

  return result;
}

template <typename M> array<M> sqrt(array<M> arr) {
  array<M> result;
  result.shape_ = arr.shape_;
  result.ndim = arr.ndim;
  result.size = arr.size;
  result.strides_ = arr.strides_;

  result.data_.resize(arr.data_.size());

  for (size_t i = 0; i < arr.data_.size(); i++) {
    result.data_[i] = std::sqrt(arr.data_[i]);
  }

  return result;
}

template <typename M> array<M> square(array<M> arr) {
  array<M> result;
  result.shape_ = arr.shape_;
  result.ndim = arr.ndim;
  result.size = arr.size;
  result.strides_ = arr.strides_;

  result.data_.resize(arr.data_.size());

  for (size_t i = 0; i < arr.data_.size(); i++) {
    result.data_[i] = arr.data_[i] * arr.data_[i];
  }

  return result;
}

template <typename M> array<int> round(array<M> arr) {
  array<int> result;
  result.shape_ = arr.shape_;
  result.ndim = arr.ndim;
  result.size = arr.size;
  result.strides_ = arr.strides_;

  result.data_.resize(arr.data_.size());

  for (size_t i = 0; i < arr.data_.size(); i++) {
    int b_sup = (int)(arr.data_[i] + 1);
    int b_inf = (int)arr.data_[i];
    if (std::abs(b_sup - arr.data_[i]) > std::abs(b_inf - arr.data_[i])) {
      result.data_[i] = b_inf;
    } else {
      result.data_[i] = b_sup;
    }
  }

  return result;
}

template <typename M> array<int> floor(array<M> arr) {
  array<int> result;
  result.shape_ = arr.shape_;
  result.ndim = arr.ndim;
  result.size = arr.size;
  result.strides_ = arr.strides_;

  result.data_.resize(arr.data_.size());

  for (size_t i = 0; i < arr.data_.size(); i++) {
    result.data_[i] = static_cast<int>(arr.data_[i]);
  }

  return result;
}

template <typename M> array<int> ceil(array<M> arr) {
  array<int> result;
  result.shape_ = arr.shape_;
  result.ndim = arr.ndim;
  result.size = arr.size;
  result.strides_ = arr.strides_;

  result.data_.resize(arr.data_.size());

  for (size_t i = 0; i < arr.data_.size(); i++) {
    result.data_[i] = static_cast<int>(arr.data_[i] + 1);
  }

  return result;
}

} // namespace numcy