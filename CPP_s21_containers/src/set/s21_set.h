#ifndef S21_SET_H_
#define S21_SET_H_

#include "../RBTree/s21_rbtree.h"

namespace s21 {
template <typename Key>
class set {
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using Container = RBTree<Key>;
  using size_type = std::size_t;

 public:
  using iterator = typename Container::iterator;
  using const_iterator = typename Container::const_iterator;

  set() noexcept : RBTree_(Container()) {}

  set(std::initializer_list<value_type> const &items)
      : RBTree_(Container(items)) {}

  set(const set &s) : RBTree_(Container(s.RBTree_)) {}

  set(set &&s) : RBTree_(Container()) { this->swap(s); }

  ~set() { RBTree_.clear(); }

  set &operator=(set &&s) {
    if (this != &s) {
      set other(std::move(s));
      swap(other);
    }
    return this;
  }

  iterator begin() noexcept { return RBTree_.begin(); }
  iterator end() noexcept { return RBTree_.end(); }

  bool empty() noexcept { return RBTree_.empty(); }
  size_type size() noexcept { return RBTree_.size(); }
  size_type max_size() noexcept { return RBTree_.max_size(); }

  void clear() { RBTree_.clear(); }

  std::pair<iterator, bool> insert(const value_type &value) {
    return RBTree_.insert(value);
  }

  void erase(iterator pos) { RBTree_.erase(pos); }

  void swap(set &other) { RBTree_.swap(other.RBTree_); }

  void merge(set &other) { RBTree_.merge(other.RBTree_); }

  iterator find(const Key &key) { return RBTree_.find(key); }
  bool contains(const Key &key) { return RBTree_.contains(key); }

 private:
  Container RBTree_;
};
}  // namespace s21

#endif  // S21_SET_H_