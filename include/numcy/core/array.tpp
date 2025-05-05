#include "array.hpp"
#include <iostream>

namespace numcy {
template <typename T> bool nested_type<T>::is_list() const {
  return type == nested_type<T>::Type::LIST;
}

template <typename T> bool nested_type<T>::is_value() const {
  return type == nested_type<T>::Type::VALUE;
}

template <typename T>
const nested_type<T>::List &nested_type<T>::get_list() const {
  if (type != nested_type<T>::Type::LIST) {
    std::cout << "Not a list" << std::endl;
    exit(EXIT_FAILURE);
  }

  return list;
}

template <typename T> const T &nested_type<T>::get_value() const {
  if (type != nested_type<T>::Type::VALUE) {
    std::cout << "Not a single value" << std::endl;
    exit(EXIT_FAILURE);
  }

  return value;
}

/*=======================================================ARRAY==========================================================*/

template <typename T> void array<T>::flatten(nested_type<T> &data) {
  if (data.is_value()) {
    // single value
    data_.push_back(data.get_value());
  } else {
    // list
    for (auto el : data.get_list()) {
      flatten(el);
    }
  }
}

template <typename T>
void array<T>::determinate_shape(const nested_type<T> data) {
  if (data.is_value()) {
    // do nothing in case of single value
    return;
  }

  // in case it's a list
  const auto &list = data.get_list();
  shape_.push_back(list.size());

  const auto &first_element = list.front();
  determinate_shape(list.front());
}

template <typename T> array<T>::array(nested_type<T> data) {
  flatten(data); // flatten user input and insert into data_
  determinate_shape(data);
  determinate_dim();
  determinate_size();
  determinate_strides();
}

template <typename U>
std::ostream &print_recursive(std::ostream &os, const std::vector<U> &data,
                              const std::vector<size_t> &shape, size_t dim,
                              size_t &index, const std::string &indent = "") {
  os << "[";
  size_t count = shape[dim];
  std::string next_indent = indent + " ";

  for (size_t i = 0; i < count; i++) {
    if (dim < shape.size() - 1) {
      if (i > 0) os << "\n" << next_indent;
      print_recursive(os, data, shape, dim + 1, index, next_indent);
    } else {
      os << data[index++];
      if (i < count - 1) os << ", ";
    }
  }

  os << "]";
  return os;
}

template <typename U>
std::ostream &operator<<(std::ostream &os, const array<U> &arr) {
  size_t index = 0;
  return print_recursive(os, arr.data_, arr.shape_, 0, index);
}

template <typename U> void print(const array<U> &arr) {
  std::cout << arr << std::endl;
}

template <typename T> void array<T>::determinate_dim(void) {
  ndim = shape_.size();
}

template <typename T> void array<T>::determinate_size(void) {
  size = data_.size();
}

template <typename T> void array<T>::determinate_strides(void) {
  size_t stride = 1;
  for (int i = (shape_.size() - 1); i >= 0; i--) {
    strides_.insert(strides_.begin(), stride);
    stride *= shape_[i];
  }
}

template <typename T>
template <typename... Args>
T &array<T>::operator()(Args... args) {
  size_t el_index = 0;
  size_t indices[] = {static_cast<size_t>(
      args)...}; // convert args into size_t type and build array

  for (size_t i = 0; i < strides_.size(); i++) {
    el_index += strides_[i] * indices[i];
  }

  return this->data_[el_index];
}

template <typename T> void array<T>::reshape(std::vector<size_t> new_shape) {
  float size = 1;

  // compute the mul of new_shape elements
  for (int i = 0; i < new_shape.size(); i++) {
    size *= new_shape[i];
  }

  if (this->data_.size() != size) {
    std::cerr << "Error: verify your shape" << std::endl;
    exit(EXIT_FAILURE);
  }

  this->shape_ = new_shape;
  determinate_dim();
  determinate_size();
  determinate_strides();
}
}; // namespace numcy