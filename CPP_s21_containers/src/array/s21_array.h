#ifndef SRC_S21_ARRAY_H_
#define SRC_S21_ARRAY_H_

#include <initializer_list>
#include <iostream>

namespace s21 {

template <class T, std::size_t N>
class array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = std::size_t;

  array() : arr_{} {}

  array(std::initializer_list<value_type> init) : arr_{} {
    if (init.size() > N) {
      throw std::out_of_range("Initializer list too large");
    }
    std::copy(init.begin(), init.end(), arr_);
  }

  array(const array &other) : arr_{} {
    std::copy(other.arr_, other.arr_ + N, arr_);
  }

  array(array &&other) noexcept : arr_{} { std::swap(arr_, other.arr_); }

  ~array() {}

  array &operator=(const array &other) {
    if (this != &other) {
      std::copy(other.arr_, other.arr_ + N, arr_);
    }
    return *this;
  }

  array &operator=(array &&other) noexcept {
    if (this != &other) {
      std::swap(arr_, other.arr_);
    }
    return *this;
  }

  reference at(size_type pos) {
    if (pos >= N) {
      throw std::out_of_range("Access out of bounds");
    }
    return arr_[pos];
  }

  const_reference at(size_type pos) const {
    if (pos >= N) {
      throw std::out_of_range("Access out of bounds");
    }
    return arr_[pos];
  }

  reference operator[](size_type pos) { return arr_[pos]; }
  const_reference operator[](size_type pos) const { return arr_[pos]; }

  const_reference front() const {
    if (N == 0) {
      throw std::logic_error("Array is empty");
    }
    return arr_[0];
  }

  const_reference back() const {
    if (N == 0) {
      throw std::logic_error("Array is empty");
    }
    return arr_[N - 1];
  }

  iterator data() noexcept { return arr_; }
  const_iterator data() const noexcept { return arr_; }

  iterator begin() noexcept { return arr_; }
  const_iterator begin() const noexcept { return arr_; }

  iterator end() noexcept { return arr_ + N; }
  const_iterator end() const noexcept { return arr_ + N; }

  bool empty() const noexcept { return N == 0; }
  size_type size() const noexcept { return N; }
  size_type max_size() const noexcept { return N; }

  void swap(array &other) { std::swap(arr_, other.arr_); }
  void fill(const_reference value) { std::fill(arr_, arr_ + N, value); }

 private:
  T arr_[N];
};

}  // namespace s21

#endif  // SRC_S21_ARRAY_H_