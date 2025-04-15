#include "../array/array.hpp"

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
} // namespace numcy