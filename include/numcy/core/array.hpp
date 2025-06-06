#pragma once
#include <initializer_list>
#include <string>
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

  const List &get_list() const; // return reference for avoiding copy process
  const T &get_value() const;   // return reference for avoiding copy process

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

namespace random {
 array<float> rand(std::vector<size_t> shape);
 array<float> randn(std::vector<size_t> shape);
 array<float> randint(int low, int high, int size);
} // namespace random

/*===================================ARRAY===================================================*/
template <typename T> class array {
public:
  // Constructor
  array(void) {} // default
  array(nested_type<T> data);

  // public attributes
  std::vector<size_t> shape_;
  int ndim; // dimension
  int size; // number of ndarray element
  std::vector<size_t> strides_;
  std::string dtype;

  // functions
  void flatten(nested_type<T> &data);
  std::vector<T> flatten();
  void determinate_shape(const nested_type<T> data);
  void determinate_dim(void);
  void determinate_size(void);
  void determinate_strides(void); // step for navigating
  template <typename... Args> auto operator()(Args... args);
  void reshape(std::vector<size_t> new_shape);

  // display function
  template <typename U> friend void print(const array<U> &arr);
  friend void print(std::vector<size_t> shape);
  friend void print(std::vector<T> array);
  template <typename... Args> friend void print(Args... args);
  template <typename U>
  friend std::ostream &operator<<(std::ostream &os, const array<U> &arr);
  template <typename U>
  friend std::ostream &
  print_recursive(std::ostream &os, const std::vector<U> &data,
                  const std::vector<size_t> &shape, size_t dim, size_t &index);

  // Generators
  template <typename V>
  friend array<V> fill_with_number(const std::vector<size_t> &shape, V number);
  friend array<float> zeros(const std::vector<size_t> &shape);
  friend array<float> ones(const std::vector<size_t> &shape);

  // elementary operations
  template <typename X>
  friend array<X> add(const array<X> nd_arr, const array<X> other);
  template <typename X>
  friend array<X> sub(const array<X> nd_arr, const array<X> other);
  template <typename X>
  friend array<X> mul(const array<X> nd_arr, const array<X> other);
  template <typename X>
  friend array<X> div(const array<X> nd_arr, const array<X> other);

  // Stats functions
  friend float sum(const array<float> &arr);
  friend float sum(const array<double> &arr);
  friend float sum(const array<int> &arr);
  friend float mean(const array<float> &arr);
  friend float mean(const array<double> &arr);
  friend float mean(const array<int> &arr);
  friend float min(const array<float> &arr);
  friend double min(const array<double> &arr);
  friend int min(const array<int> &arr);
  friend float max(const array<float> &arr);
  friend double max(const array<double> &arr);
  friend int max(const array<int> &arr);
  friend size_t argmin(const array<float> &arr);
  friend size_t argmin(const array<double> &arr);
  friend size_t argmin(const array<int> &arr);
  friend size_t argmax(const array<float> &arr);
  friend size_t argmax(const array<double> &arr);
  friend size_t argmax(const array<int> &arr);
  template <typename S> friend double var(array<S> arr);
  template <typename S> friend double std(array<S> arr);

  // Maths functions
  template <typename M> friend array<M> sin(array<M> arr);
  template <typename M> friend array<M> cos(array<M> arr);
  template <typename M> friend array<M> tan(array<M> arr);
  template <typename M> friend array<M> exp(array<M> arr);
  template <typename M> friend array<M> log(array<M> arr);
  template <typename M> friend array<M> abs(array<M> arr);
  template <typename M> friend array<M> pow(array<M> arr, double exponent);
  template <typename M> friend array<M> sqrt(array<M> arr);
  template <typename M> friend array<M> square(array<M> arr);
  template <typename M> friend array<int> floor(array<M> arr);
  template <typename M> friend array<int> round(array<M> arr);
  template <typename M> friend array<int> ceil(array<M> arr);

  friend numcy::array<float> numcy::random::rand(std::vector<size_t> shape);
  friend numcy::array<float> numcy::random::randn(std::vector<size_t> shape);
  friend numcy::array<float> numcy::random::randint(int low, int high, std::vector<size_t> shape);

private:
  std::vector<T> data_;
};

}; // namespace numcy

#include "../maths/maths.tpp"
#include "../random/random.tpp"
#include "array.tpp"