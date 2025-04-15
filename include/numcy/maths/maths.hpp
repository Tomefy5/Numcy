#pragma once

#include "../array/array.hpp"

namespace numcy {
// sum function and its overloads
float sum(const array<float> &arr);
float sum(const array<int> &arr);
float sum(const array<double> &arr);

// mean function and its overloads
float mean(const array<float> &arr);
float mean(const array<double> &arr);
float mean(const array<int> &arr);

// min functions and its overloads
float min(const array<float>& arr);
double min(const array<double>& arr);
int min(const array<int>& arr);

// max functions and its overloads
float max(const array<float>& arr);
double max(const array<double>& arr);
int max(const array<int>& arr);
} // namespace numcy

#include "maths.tpp"