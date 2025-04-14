#pragma once
#include <initializer_list>
#include <vector>

namespace numcy {

template <typename T> class array;

template <typename T> class nested_type {

public:
  // Alias for a list of nested_type elements
  using List = std::vector<nested_type<T>>;

  // Constructor for a single value
  nested_type(T value) : type(Type::VALUE), value(value) {}

  // Constructor for a list
  nested_type(std::initializer_list<nested_type<T>> list)
      : type(Type::LIST), list(list) {}

  // Accessors
  bool is_value() const;
  bool is_list() const;

  const List& get_list() const; //return reference for avoiding copy process
  const T& get_value() const; //return reference for avoiding copy process

  // friend class
  template <typename> friend class array;

private:
  // Indicates whether this instance holds a single value or a list
  enum class Type { VALUE, LIST };
  Type type;

  // Data
  T value;   // A single value(float, int, string, ...)
  List list; // A list of nested_type<T>
};

// class array
template <typename T> class array {
public:
  // Constructor
  array(nested_type<T> data);

  // public attributes
  std::vector<size_t> shape_;
  int ndim; // dimension

  // functions
  void flatten(nested_type<T> &data);
  void determinate_shape(const nested_type<T> data);

  // friend functions
  template <typename U>
  friend std::ostream& operator<<(std::ostream& os, const array<U>& arr);

private:
  std::vector<T> data_;
  
};

}; // namespace numcy

#include "array.tpp"