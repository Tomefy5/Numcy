#include "array.hpp"
#include <iostream>

namespace numcy {
template <typename T> bool nested_type<T>::is_list() const {
  return type == nested_type<T>::Type::LIST;
}

template <typename T> bool nested_type<T>::is_value() const {
  return type == nested_type<T>::Type::VALUE;
}

template <typename T> const nested_type<T>::List& nested_type<T>::get_list() const {
  if (type != nested_type<T>::Type::LIST) {
    std::cout << "Not a list" << std::endl;
    exit(EXIT_FAILURE);
  }

  return list;
}

template <typename T> const T& nested_type<T>::get_value() const {
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
}

template <typename U> std::ostream& operator<<(std::ostream& os, const array<U>& arr) {

  return os;
}

}; // namespace numcy