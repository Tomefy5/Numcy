#include "../array/array.hpp"
#include <cmath>

namespace numcy {

// sum function and its overloads
float sum(const array<float> &arr) {
  float sum_val = 0;
  for (size_t i = 0; i < arr.data_.size(); i++) {
    sum_val += arr.data_[i];
  }
  return sum_val;
}

float sum(const array<double> &arr) {
  float sum_val = 0;
  for (size_t i = 0; i < arr.data_.size(); i++) {
    sum_val += arr.data_[i];
  }
  return sum_val;
}

float sum(const array<int> &arr) {
  float sum_val = 0;
  for (size_t i = 0; i < arr.data_.size(); i++) {
    sum_val += arr.data_[i];
  }
  return sum_val;
}

// mean function and its overloads
float mean(const array<float> &arr) { return sum(arr) / arr.data_.size(); }
float mean(const array<double> &arr) { return sum(arr) / arr.data_.size(); }
float mean(const array<int> &arr) { return sum(arr) / arr.data_.size(); }

// min functions and its overloads
float min(const array<float> &arr) {
  float min = arr.data_[0]; // initialize by the first element of data
  for (size_t i = 1; i < arr.data_.size(); i++) {
    if (min > arr.data_[i])
      min = arr.data_[i];
  }
  return min;
}

double min(const array<double> &arr) {
  double min = arr.data_[0]; // initialize by the first element of data
  for (size_t i = 1; i < arr.data_.size(); i++) {
    if (min > arr.data_[i])
      min = arr.data_[i];
  }
  return min;
}

int min(const array<int> &arr) {
  int min = arr.data_[0]; // initialize by the first element of data
  for (size_t i = 1; i < arr.data_.size(); i++) {
    if (min > arr.data_[i])
      min = arr.data_[i];
  }
  return min;
}

// max functions and its overloads
float max(const array<float> &arr) {
  float max = arr.data_[0]; // initialize by the first element of data
  for (size_t i = 1; i < arr.data_.size(); i++) {
    if (max < arr.data_[i])
      max = arr.data_[i];
  }
  return max;
}

double max(const array<double> &arr) {
  double max = arr.data_[0]; // initialize by the first element of data
  for (size_t i = 1; i < arr.data_.size(); i++) {
    if (max < arr.data_[i])
      max = arr.data_[i];
  }
  return max;
}

int max(const array<int> &arr) {
  int max = arr.data_[0]; // initialize by the first element of data
  for (size_t i = 1; i < arr.data_.size(); i++) {
    if (max < arr.data_[i])
      max = arr.data_[i];
  }
  return max;
}


// argmin functions and its overloads
size_t argmin(const array<float> &arr) {
  size_t id_min = 0;
  for (size_t i = 1; i < arr.data_.size(); i++) {
    if (arr.data_[id_min] > arr.data_[i])
      id_min = i;
  }
  return id_min;
}

size_t argmin(const array<double> &arr) {
  size_t id_min = 0;
  for (size_t i = 1; i < arr.data_.size(); i++) {
    if (arr.data_[id_min] > arr.data_[i])
      id_min = i;
  }
  return id_min;
}

size_t argmin(const array<int> &arr) {
  size_t id_min = 0;
  for (size_t i = 1; i < arr.data_.size(); i++) {
    if (arr.data_[id_min] > arr.data_[i])
      id_min = i;
  }
  return id_min;
}

// argmax functions and its overloads
size_t argmax(const array<float> &arr) {
  size_t id_min = 0;
  for (size_t i = 1; i < arr.data_.size(); i++) {
    if (arr.data_[id_min] < arr.data_[i])
      id_min = i;
  }
  return id_min;
}

size_t argmax(const array<double> &arr) {
  size_t id_min = 0;
  for (size_t i = 1; i < arr.data_.size(); i++) {
    if (arr.data_[id_min] < arr.data_[i])
      id_min = i;
  }
  return id_min;
}

size_t argmax(const array<int> &arr) {
  size_t id_min = 0;
  for (size_t i = 1; i < arr.data_.size(); i++) {
    if (arr.data_[id_min] < arr.data_[i])
      id_min = i;
  }
  return id_min;
}


// Trigos and other maths

template <typename M>
array<M> sin(array<M> arr) {
  array<M> result;
  result.shape_ = arr.shape_;
  result.ndim = arr.ndim;
  result.size = arr.size;
  result.strides_ = arr.strides_;

  result.data_.resize(arr.data_.size());

  for(size_t i = 0; i < arr.data_.size(); i++) {
    if(arr.data_[i] > 1 || arr.data_[i] < -1) {
      std::cerr << "Angle's value must be between 1 and -1" << std::endl;
      exit(EXIT_FAILURE);
    }
    result.data_[i] = std::sin(arr.data_[i]);
  }

  return result;

}

template <typename M>
array<M> cos(array<M> arr) {
  array<M> result;
  result.shape_ = arr.shape_;
  result.ndim = arr.ndim;
  result.size = arr.size;
  result.strides_ = arr.strides_;

  result.data_.resize(arr.data_.size());

  for(size_t i = 0; i < arr.data_.size(); i++) {
    if(arr.data_[i] > 1 || arr.data_[i] < -1) {
      std::cerr << "Angle's value must be between 1 and -1" << std::endl;
      exit(EXIT_FAILURE);
    }
    result.data_[i] = std::cos(arr.data_[i]);
  }

  return result;

}

template <typename M>
array<M> tan(array<M> arr) {
  array<M> result;
  result.shape_ = arr.shape_;
  result.ndim = arr.ndim;
  result.size = arr.size;
  result.strides_ = arr.strides_;

  result.data_.resize(arr.data_.size());

  for(size_t i = 0; i < arr.data_.size(); i++) {
    if(arr.data_[i] > 1 || arr.data_[i] < -1) {
      std::cerr << "Angle's value must be between 1 and -1" << std::endl;
      exit(EXIT_FAILURE);
    }
    result.data_[i] = std::tan(arr.data_[i]);
  }

  return result;

}


template <typename M>
array<M> exp(array<M> arr) {
  array<M> result;
  result.shape_ = arr.shape_;
  result.ndim = arr.ndim;
  result.size = arr.size;
  result.strides_ = arr.strides_;

  result.data_.resize(arr.data_.size());

  for(size_t i = 0; i < arr.data_.size(); i++) {
    result.data_[i] = std::exp(arr.data_[i]);
  }

  return result;

}

template <typename M>
array<M> log(array<M> arr) {
  array<M> result;
  result.shape_ = arr.shape_;
  result.ndim = arr.ndim;
  result.size = arr.size;
  result.strides_ = arr.strides_;

  result.data_.resize(arr.data_.size());

  for(size_t i = 0; i < arr.data_.size(); i++) {
    result.data_[i] = std::log(arr.data_[i]);
  }

  return result;

}

template <typename M>
array<M> abs(array<M> arr) {
  array<M> result;
  result.shape_ = arr.shape_;
  result.ndim = arr.ndim;
  result.size = arr.size;
  result.strides_ = arr.strides_;

  result.data_.resize(arr.data_.size());

  for(size_t i = 0; i < arr.data_.size(); i++) {
    result.data_[i] = std::abs(arr.data_[i]);
  }

  return result;

}

} // namespace numcy