#ifndef S21_stack_H_
#define S21_stack_H_

#include <iostream>
#include <limits>

#include "../list/s21_list.h"

namespace s21 {

template <typename T>
class stack {
 public:
  using value_type = T;
  using ref = T &;
  using size_type = size_t;
  using const_ref = const T &;
  using Container = list<T>;

  stack() noexcept : list_(Container()) {}

  stack(std::initializer_list<value_type> const &items)
      : list_(Container(items)) {}

  stack(const stack &q) : list_(Container(q.list_)) {}

  stack(stack &&q) : list_(Container()) { this->swap(q); }

  ~stack() { list_.clear(); }

  stack &operator=(stack &&q) {
    if (this != &q) {
      stack other(std::move(q));
      swap(other);
    }
    return this;
  }

  const_ref top() noexcept { return list_.back(); }

  // Проверка списка на пустоту
  bool empty() noexcept { return list_.empty(); }

  // Текущий размер очереди
  size_type size() noexcept { return list_.size(); }

  // Добавление элемента в конец очереди
  void push(const_ref value) { list_.push_back(value); }

  // Удаление элемента из начала очереди
  void pop() { list_.pop_back(); }

  // Меняет очереди местами
  void swap(stack &other) noexcept { list_.swap(other.list_); }

 private:
  Container list_;
};
}  // namespace s21

#endif  // S21_stack_H_