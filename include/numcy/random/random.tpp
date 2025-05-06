#pragma once

#include "../core/array.hpp"
#include <random>

namespace numcy::random {

numcy::array<float> rand(std::vector<size_t> shape) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<float> dist(0.0, 1.0);

  array<float> result;
  result.shape_ = shape;
  result.ndim = shape.size();
  result.determinate_size();
  result.determinate_strides();

  double nb_el = 1;
  for (auto el : shape)
    nb_el *= el;

  result.data_.resize(nb_el);
  for (size_t i = 0; i < nb_el; ++i) {
    result.data_[i] = dist(gen);
  }

  return result;
}

numcy::array<float> randn(std::vector<size_t> shape) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<float> dist(0.0, 1.0);

  array<float> result;
  result.shape_ = shape;
  result.ndim = shape.size();
  result.determinate_size();
  result.determinate_strides();

  double nb_el = 1;
  for (auto el : shape)
    nb_el *= el;

  result.data_.resize(nb_el);
  for (size_t i = 0; i < nb_el; ++i) {
    result.data_[i] = dist(gen);
  }

  return result;
}

numcy::array<float> randint(int low, int high, std::vector<size_t> shape) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(low, high);
  
    array<float> result;
    result.shape_ = shape;
    result.ndim = shape.size();
    result.determinate_size();
    result.determinate_strides();
  
    double nb_el = 1;
    for (auto el : shape)
      nb_el *= el;
  
    result.data_.resize(nb_el);
    for (size_t i = 0; i < nb_el; ++i) {
      result.data_[i] = dist(gen);
    }
  
    return result;
  }

} // namespace numcy::random