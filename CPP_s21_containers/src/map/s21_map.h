#ifndef S21_MAP_H_
#define S21_MAP_H_

#include "../RBTree/s21_rbtree.h"

namespace s21 {
template <typename Key, typename T>
class map {
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using Container = RBTree<value_type>;
  using size_type = std::size_t;

 public:
  using iterator = typename Container::iterator;
  using const_iterator = typename Container::const_iterator;

  map() noexcept : RBTree_(Container()) {}

  map(std::initializer_list<value_type> const &items) : map() {
    for (auto i = items.begin(); i != items.end(); i++) this->insert(*i);
  }

  map(const map &m) : RBTree_(Container(m.RBTree_)) {}

  map(map &&m) : RBTree_(Container()) { this->swap(m); }

  ~map() { RBTree_.clear(); }

  map &operator=(map &&m) {
    if (this != &m) {
      map other(std::move(m));
      swap(other);
    }
    return this;
  }

  T &at(const Key &key) {
    iterator it = FindKey(key);
    if (it == end()) throw std::out_of_range("Out of range");
    return (*it).second;
  }

  T &operator[](const Key &key) {
    value_type value = {key, mapped_type{}};
    iterator it = FindKey(key);
    std::pair<iterator, bool> result = {end(), false};
    if (it == end()) result = insert(value);
    return (result.second) ? (*result.first).second : (*it).second;
  }

  iterator begin() noexcept { return RBTree_.begin(); }
  iterator end() noexcept { return RBTree_.end(); }

  bool empty() noexcept { return RBTree_.empty(); }
  size_type size() noexcept { return RBTree_.size(); }
  size_type max_size() noexcept { return RBTree_.max_size(); }

  void clear() { RBTree_.clear(); }

  std::pair<iterator, bool> insert(const value_type &value) {
    iterator it = FindKey(value.first);
    std::pair<iterator, bool> result;
    (it == end()) ? result = RBTree_.insert(value) : result = {it, false};
    return result;
  }

  std::pair<iterator, bool> insert(const Key &key, const T &obj) {
    value_type value = {key, obj};
    iterator it = FindKey(key);
    std::pair<iterator, bool> result;
    (it == end()) ? result = RBTree_.insert(value) : result = {it, false};
    return result;
  }

  std::pair<iterator, bool> insert_or_assign(const Key &key, const T &obj) {
    value_type value = {key, obj};
    iterator it = FindKey(key);
    if (it != end()) (*it).second = obj;
    std::pair<iterator, bool> result;
    (it == end()) ? result = RBTree_.insert(value) : result = {it, false};
    return result;
  }

  void erase(iterator pos) { RBTree_.erase(pos); }
  void swap(map &other) { RBTree_.swap(other.RBTree_); }
  void merge(map &other) { RBTree_.merge(other.RBTree_); }

  bool contains(const Key &key) {
    const_iterator result = FindKey(key);
    return (result == end()) ? false : true;
  }

 private:
  Container RBTree_;

  iterator FindKey(const Key &key) {
    iterator it = begin();
    for (;; it++)
      if (((*it).first == key) || (it == end())) break;
    return it;
  }
};
}  // namespace s21

#endif  // S21_MAP_H_