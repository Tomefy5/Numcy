#pragma once

#include "../core/array.hpp"

namespace numcy {

// Trigos
template <typename M> array<M> sin(array<M> arr);
template <typename M> array<M> cos(array<M> arr);
template <typename M> array<M> tan(array<M> arr);
template <typename M> array<M> exp(array<M> arr);
template <typename M> array<M> log(array<M> arr);
template <typename M> array<M> abs(array<M> arr);
template <typename M> array<M> pow(array<M> arr, double exponent);
template <typename M> array<M> sqrt(array<M> arr);
template <typename M> array<M> square(array<M> arr);


} // namespace numcy

#include "maths.tpp"