#ifndef S21_MULTISET_H_
#define S21_MULTISET_H_

#include "../RBTree/s21_rbtree.h"

namespace s21 {
template <typename Key>
class multiset {
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using Container = RBTree<Key>;
  using size_type = std::size_t;

 public:
  using iterator = typename Container::iterator;
  using const_iterator = typename Container::const_iterator;

  multiset() noexcept : RBTree_(Container()) {}

  multiset(std::initializer_list<value_type> const &items)
      : RBTree_(Container()) {
    for (auto i = items.begin(); i != items.end(); i++)
      RBTree_.insert_multi(*i);
  }

  multiset(const multiset &ms) : RBTree_(Container()) {
    for (const_iterator it = ms.cbegin(); it != ms.cend(); it++)
      this->insert(*it);
  }

  multiset(multiset &&ms) : RBTree_(Container()) { this->swap(ms); }

  ~multiset() { RBTree_.clear(); }

  multiset &operator=(multiset &&s) {
    if (this != &s) {
      multiset other(std::move(s));
      swap(other);
    }
    return this;
  }

  iterator begin() noexcept { return RBTree_.begin(); }
  const_iterator cbegin() const noexcept { return RBTree_.cbegin(); }

  iterator end() noexcept { return RBTree_.end(); }
  const_iterator cend() const noexcept { return RBTree_.cend(); }

  bool empty() noexcept { return RBTree_.empty(); }
  size_type size() noexcept { return RBTree_.size(); }
  size_type max_size() noexcept { return RBTree_.max_size(); }

  void clear() { RBTree_.clear(); }

  iterator insert(const value_type &value) {
    return RBTree_.insert_multi(value);
  }

  void erase(iterator pos) { RBTree_.erase(pos); }

  void swap(multiset &other) { RBTree_.swap(other.RBTree_); }

  void merge(multiset &other) { RBTree_.merge_multi(other.RBTree_); }

  size_type count(const Key &key) {
    size_type count = 0;
    for (iterator it = begin(); it != end(); it++)
      if (std::equal_to<value_type>{}(*it, key)) count++;
    return count;
  }

  iterator find(const Key &key) { return RBTree_.find(key); }
  bool contains(const Key &key) { return RBTree_.contains(key); }

  std::pair<iterator, iterator> equal_range(const Key &key) {
    std::pair<iterator, iterator> result = {lower_bound(key), upper_bound(key)};
    return result;
  }

  iterator lower_bound(const Key &key) {
    iterator it = begin();
    bool found = false;
    while (it != end() && !found) {
      if (std::greater_equal<value_type>{}(*it, key)) found = true;
      if (!found) it++;
    }
    return it;
  }

  iterator upper_bound(const Key &key) {
    iterator it = begin();
    bool found = false;
    while (it != end() && !found) {
      if (*it > key) found = true;
      if (!found) it++;
    }
    return it;
  }

 private:
  Container RBTree_;
};
}  // namespace s21

#endif  // S21_MULTISET_H_