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
float min(const array<float> &arr);
double min(const array<double> &arr);
int min(const array<int> &arr);

// max functions and its overloads
float max(const array<float> &arr);
double max(const array<double> &arr);
int max(const array<int> &arr);

// argmin functions and its overloads
size_t argmin(const array<float> &arr);
size_t argmin(const array<double> &arr);
size_t argmin(const array<int> &arr);

// argmax functions and its overloads
size_t argmax(const array<float> &arr);
size_t argmax(const array<double> &arr);
size_t argmax(const array<int> &arr);

// Trigos
template <typename M>
array<M> sin(array<M> arr);
template <typename M>
array<M> cos(array<M> arr);
template <typename M>
array<M> tan(array<M> arr);
template <typename M>
array<M> exp(array<M> arr);
template <typename M>
array<M> log(array<M> arr);
template <typename M>
array<M> abs(array<M> arr);


} // namespace numcy

#include "maths.tpp"