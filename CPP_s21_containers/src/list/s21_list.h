#ifndef S21_LIST_H_
#define S21_LIST_H_

#include <iostream>
#include <limits>

namespace s21 {

template <typename T>
class list {
 public:
  using val_t = T;
  using ref = T &;
  using size_type = size_t;

  // Узел списка
  struct ListNode {
    val_t value = val_t();
    ListNode *next = nullptr;
    ListNode *prev = nullptr;
    ListNode(const T &value = T())
        : value(value), next(nullptr), prev(nullptr) {}
  };

  // Внутренний класс - итератор
  class ListIter {
    friend class list<T>;

   public:
    ListIter() noexcept : node_(nullptr) {}
    ListIter(ListNode *node) noexcept : node_(node) {}
    ListIter(const ListIter &other) noexcept : node_(other.node_) {}
    ListIter(ListIter &&other) noexcept : node_(nullptr) {
      std::swap(node_, other.node_);
    }

    ListIter &operator=(ListIter &&l) {
      if (this != &l) {
        ListIter other(std::move(l));
        std::swap(node_, other.node_);
      }
      return *this;
    }

    bool operator==(const ListIter &o) noexcept {
      return (node_ == o.node_) ? true : false;
    }

    bool operator!=(const ListIter &other) noexcept {
      return (node_ == other.node_) ? false : true;
    }

    ListIter &operator++() noexcept {
      node_ = node_->next;
      return *this;
    }

    ListIter operator++(int) {
      ListIter it = *this;
      node_ = node_->next;
      return it;
    }

    ListIter &operator--() noexcept {
      node_ = node_->prev;
      return *this;
    }

    ListIter operator--(int) {
      ListIter it = *this;
      node_ = node_->prev;
      return it;
    }

    val_t &operator*() noexcept { return node_->value; }

    val_t *operator->() noexcept { return &(node_->value); }

   protected:
    ListNode *node_;
  };

  class ListConstIterator : public ListIter {
   public:
    ListConstIterator() noexcept : ListIter() {}
    ListConstIterator(const ListIter &node) noexcept : ListIter(node) {}
  };

  using iter = ListIter;
  using const_iter = ListConstIterator;
  using const_ref = const T &;

  list() noexcept {
    head = nullptr;
    tail = nullptr;
    size_ = 0;

    fake_ = new ListNode();
    fake_->next = fake_;
    fake_->prev = fake_;
  }

  list(size_type n) : list() {
    if (n > 0)
      for (size_type i = 0; i < n; i++) push_front(val_t());
  }

  list(std::initializer_list<val_t> const &items) : list() {
    for (auto i = items.begin(); i != items.end(); i++) this->push_back(*i);
  }

  list(const list &l) : list() {
    for (const_iter it = l.cbegin(); it != l.cend(); it++) this->push_back(*it);
  }

  list(list &&l) noexcept : list() {
    this->head = l.head;
    this->tail = l.tail;
    this->fake_ = l.fake_;
    this->size_ = l.size_;
    l.head = nullptr;
    l.tail = nullptr;
    l.fake_ = nullptr;
    l.size_ = 0;
  }

  ~list() {
    clear();
    delete fake_;
  }

  list &operator=(list &&l) {
    if (this != &l) {
      list other(std::move(l));
      swap(other);
    }
    return this;
  }

  // Доступ к первому и элементу после последнего
  const_ref front() noexcept {
    return (this->head) ? this->head->value : this->fake_->value;
  }
  const_ref back() noexcept {
    return (this->tail) ? this->tail->value : this->fake_->value;
  }

  // Возвращает итератор в начало или конец списка
  iter begin() noexcept { return head ? iter(head) : iter(fake_); }
  const_iter cbegin() const noexcept {
    return head ? const_iter(head) : const_iter(fake_);
  }
  iter end() noexcept { return iter(fake_); }
  const_iter cend() const { return const_iter(fake_); }

  // Проверка списка на пустоту
  bool empty() noexcept { return (this->size_ == 0) ? true : false; }

  // Текущий и максимальный размер списка
  size_type size() noexcept { return this->size_; }
  size_type max_size() noexcept {
    return std::numeric_limits<size_type>::max() / sizeof(ListNode) / 2;
  }

  // Очистить список
  void clear() {
    while (head) pop_front();
  }

  // Помещает элемент в список и возвращает ссылку на него
  iter insert(iter pos, const_ref value) {
    iter result;
    if (pos == this->begin()) {
      push_front(value);
      result = this->begin();
    } else if (pos == this->end()) {
      push_back(value);
      result = this->end();
      result--;
    } else {
      ListNode *insert_node = new ListNode(value);
      ListNode *current_node = pos.node_;
      insert_node->next = current_node;
      insert_node->prev = current_node->prev;
      current_node->prev->next = insert_node;
      current_node->prev = insert_node;
      size_++;
      result = iter(insert_node);
    }
    return result;
  }

  // Удаляет элемент из списка
  void erase(iter pos) {
    if (pos == begin()) {
      pop_front();
    } else if (pos.node_ == tail) {
      pop_back();
    } else {
      ListNode *current_node = pos.node_;
      current_node->prev->next = current_node->next;
      current_node->next->prev = current_node->prev;
      current_node->next = nullptr;
      current_node->prev = nullptr;
      delete current_node;
      size_--;
    }
  }

  // Добавление элемента в начало списка
  void push_front(const_ref value) {
    ListNode *node = new ListNode(value);
    node->prev = fake_;
    fake_->next = node;

    if (head) {
      node->next = head;
      head->prev = node;
    } else {
      node->next = fake_;
      fake_->prev = node;
    }
    head = node;

    if (!tail) tail = node;
    size_++;
  }

  // Добавление элемента в конец списка
  void push_back(const_ref value) {
    ListNode *node = new ListNode(value);
    node->next = fake_;
    fake_->prev = node;

    if (tail) {
      node->prev = tail;
      tail->next = node;
    } else {
      node->prev = fake_;
      fake_->next = node;
    }
    tail = node;

    if (!head) head = node;
    size_++;
  }

  // Удаление первого элемента из списка
  void pop_front() {
    if (head) {
      ListNode *node = head;
      if (head != tail) {
        head = head->next;
        head->prev = fake_;
        fake_->next = head;
      } else {
        head = nullptr;
        tail = nullptr;
        fake_->next = fake_;
        fake_->prev = fake_;
      }
      delete node;
      size_--;
    }
  }

  // Удаление последнего элемента из списка
  void pop_back() {
    if (tail) {
      ListNode *node = tail;
      if (head != tail) {
        tail = tail->prev;
        tail->next = fake_;
        fake_->prev = tail;
      } else {
        head = nullptr;
        tail = nullptr;
        fake_->next = fake_;
        fake_->prev = fake_;
      }
      delete node;
      size_--;
    }
  }

  // Меняет списки местами
  void swap(list &other) noexcept {
    std::swap(head, other.head);
    std::swap(tail, other.tail);
    std::swap(size_, other.size_);
    std::swap(fake_, other.fake_);
  }

  // Объединяет два отсортированных списка
  void merge(list &other) {
    if (this != &other) {
      if (this->empty()) {
        swap(other);
      } else {
        iter it = this->begin();
        iter it_other = other.begin();
        while (!other.empty()) {
          if (it.node_->value > it_other.node_->value || it == this->end()) {
            this->insert(it, it_other.node_->value);
            iter temp = it_other;
            it_other++;
            other.erase(temp);
          } else {
            it++;
          }
        }
      }
    }
  }

  // Перемещает элементы из другого списка в текущий, начиная с позиции pos
  void splice(const_iter pos, list &other) {
    if (this != &other) {
      if (this->empty()) {
        swap(other);
      } else {
        iter it = pos;
        iter it_other = other.begin();
        while (!other.empty()) {
          this->insert(it, it_other.node_->value);
          iter temp = it_other;
          it_other++;
          other.erase(temp);
        }
      }
    }
  }

  // Реверс эелементов в списке
  void reverse() {
    for (iter it = this->begin(); it != this->end(); it--)
      std::swap(it.node_->next, it.node_->prev);
    std::swap(this->head, this->tail);
  }

  // Удаляет все дубликаты, следующих друг за другом
  void unique() {
    for (iter it = this->begin(); it != this->end();) {
      iter it_next = it;
      it_next++;
      if (*it == *it_next)
        this->erase(it_next);
      else
        it++;
    }
  }

  // Сортирует элементы в списке
  void sort() {
    if (head) {
      head->prev = nullptr;
      tail->next = nullptr;

      head = MergeSort(head);
      tail = head;
      while (tail->next != nullptr) tail = tail->next;

      head->prev = fake_;
      fake_->next = head;
      tail->next = fake_;
      fake_->prev = tail;
    }
  }

 private:
  ListNode *head;   // Первый элемент в списке
  ListNode *tail;   // Последний элемент в списке
  ListNode *fake_;  // Фейковая нода пустого списка
  size_type size_;  // Размер списка

  ListNode *MergeSort(ListNode *first) {
    if (first == nullptr || first->next == nullptr) return first;
    ListNode *center = GetCenter(first);
    ListNode *next_center = center->next;
    center->next = nullptr;
    ListNode *left = MergeSort(first);
    ListNode *right = MergeSort(next_center);
    return LinkNodes(left, right);
  }

  ListNode *GetCenter(ListNode *first) {
    ListNode *center = first;
    for (ListNode *last = first;
         last->next != nullptr && last->next->next != nullptr;
         last = last->next->next)
      center = center->next;
    return center;
  }

  ListNode *LinkNodes(ListNode *left, ListNode *right) {
    ListNode *result = nullptr;
    if (left == nullptr) {
      result = right;
    } else if (right == nullptr) {
      result = left;
    } else if (left->value <= right->value) {
      result = left;
      result->next = LinkNodes(left->next, right);
    } else {
      result = right;
      result->next = LinkNodes(left, right->next);
    }
    return result;
  }
};

}  // namespace s21

#endif  // S21_LIST_H_