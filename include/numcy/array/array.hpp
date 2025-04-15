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
  array(void){} // default
  array(nested_type<T> data);

  // public attributes
  std::vector<size_t> shape_;
  int ndim; // dimension
  int size; // number of ndarray element
  std::vector<size_t> strides_;

  // functions
  void flatten(nested_type<T> &data);
  void determinate_shape(const nested_type<T> data);
  void determinate_dim(void);
  void determinate_size(void);
  template <typename... Args> 
  T& operator()(Args... args);

  // friend functions
  template <typename U>
  friend std::ostream& operator<<(std::ostream& os, const array<U>& arr);
  template <typename U>
  friend std::ostream& print_recursive(std::ostream& os, const std::vector<U>& data, const std::vector<size_t>& shape, size_t dim, size_t& index);
  template <typename U>
  friend void print(const array<U>& arr);
  template <typename V>
  friend array<V> fill_with_number(const std::vector<size_t>& shape, V number);
  friend array<float> zeros(const std::vector<size_t>& shape);
  friend array<float> ones(const std::vector<size_t>& shape);


  // maths functions
  friend float sum(const array<float>& arr);
  friend float sum(const array<double>& arr);
  friend float sum(const array<int>& arr);

  friend float mean(const array<float>& arr);
  friend float mean(const array<double>& arr);
  friend float mean(const array<int>& arr);

  friend float min(const array<float>& arr);
  friend double min(const array<double>& arr);
  friend int min(const array<int>& arr);

  friend float max(const array<float>& arr);
  friend double max(const array<double>& arr);
  friend int max(const array<int>& arr);

private:
  std::vector<T> data_;
  void determinate_strides(void); // step for navigating
  
  
};

}; // namespace numcy

#include "array.tpp"