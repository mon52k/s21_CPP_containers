#ifndef S21_QUEUE_H_
#define S21_QUEUE_H_

#include <iostream>
#include <limits>

#include "../list/s21_list.h"

namespace s21 {

template <typename T>
class queue {
 public:
  using value_type = T;
  using reference = T &;
  using size_type = size_t;
  using const_ref = const T &;
  using Container = list<T>;

  queue() noexcept : list_(Container()) {}

  queue(std::initializer_list<value_type> const &items)
      : list_(Container(items)) {}

  queue(const queue &q) : list_(Container(q.list_)) {}

  queue(queue &&q) : list_(Container()) { this->swap(q); }

  ~queue() { list_.clear(); }

  queue &operator=(queue &&q) {
    if (this != &q) {
      queue other(std::move(q));
      swap(other);
    }
    return this;
  }

  const_ref front() noexcept { return list_.front(); }

  const_ref back() noexcept { return list_.back(); }

  // Проверка списка на пустоту
  bool empty_list() noexcept { return list_.empty(); }

  // Текущий размер очереди
  size_type current_size() noexcept { return list_.size(); }

  // Добавление элемента в конец очереди
  void push(const_ref value) { list_.push_back(value); }

  // Удаление элемента из начала очереди
  void del_pop() { list_.pop_front(); }

  // Меняет очереди местами
  void swap(queue &other) noexcept { list_.swap(other.list_); }

 private:
  Container list_;
};
}  // namespace s21

#endif  // S21_QUEUE_H_