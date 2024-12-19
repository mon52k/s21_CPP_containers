#ifndef S21_RBTREE_H_
#define S21_RBTREE_H_

#include <iostream>
#include <limits>

namespace s21 {

template <typename Key>
class RBTree {
 public:
  using value_type = Key;
  using reference = Key &;
  using const_reference = const Key &;
  using size_type = size_t;

  enum Color { RED, BLACK };

  // Узел дерева
  struct RBTreeNode {
    value_type value;
    Color color;
    RBTreeNode *parent;
    RBTreeNode *left;
    RBTreeNode *right;
    RBTreeNode(const_reference v = value_type())
        : value(v),
          color(RED),
          parent(nullptr),
          left(nullptr),
          right(nullptr) {}
  };

  // Внутренний класс - итератор
  class RBTreeIterator {
    friend class RBTree<Key>;

   public:
    RBTreeIterator() noexcept : node_(nullptr) {}
    RBTreeIterator(RBTreeNode *node) noexcept : node_(node) {}
    RBTreeIterator(const RBTreeIterator &other) noexcept : node_(other.node_) {}
    RBTreeIterator(RBTreeIterator &&other) noexcept : node_(nullptr) {
      std::swap(node_, other.node_);
    }
    ~RBTreeIterator() noexcept { node_ = nullptr; }

    RBTreeIterator &operator=(RBTreeIterator &&l) {
      if (this != &l) {
        RBTreeIterator other(std::move(l));
        std::swap(node_, other.node_);
      }
      return *this;
    }

    bool operator==(const RBTreeIterator &other) noexcept {
      return (node_ == other.node_) ? true : false;
    }

    bool operator!=(const RBTreeIterator &other) noexcept {
      return (node_ == other.node_) ? false : true;
    }

    RBTreeIterator &operator++() noexcept {
      if (node_->color == RED &&
          (node_->parent == nullptr || node_->parent->parent == node_)) {
        node_ = node_->left;
      } else if (node_->right) {
        node_ = node_->right;
        while (node_->left) node_ = node_->left;
      } else {
        RBTreeNode *parent = node_->parent;
        while (node_ == parent->right) {
          node_ = parent;
          parent = node_->parent;
        }
        if (node_->right != parent) node_ = parent;
      }
      return *this;
    }

    RBTreeIterator operator++(int) {
      RBTreeIterator it = *this;
      ++(*this);
      return it;
    }

    RBTreeIterator &operator--() noexcept {
      if (node_->color == RED &&
          (node_->parent == nullptr || node_->parent->parent == node_)) {
        node_ = node_->right;
      } else if (node_->left) {
        node_ = node_->left;
        while (node_->right) node_ = node_->right;
      } else {
        RBTreeNode *parent = node_->parent;
        while (node_ == parent->left) {
          node_ = parent;
          parent = node_->parent;
        }
        if (node_->left != parent) node_ = parent;
      }
      return *this;
    }

    RBTreeIterator operator--(int) {
      RBTreeIterator it = *this;
      --(*this);
      return it;
    }

    value_type &operator*() noexcept { return node_->value; }

    value_type *operator->() noexcept { return &(node_->value); }

   protected:
    RBTreeNode *node_;
  };

  class RBTreeConstIterator : public RBTreeIterator {
   public:
    RBTreeConstIterator() noexcept : RBTreeIterator() {}
    RBTreeConstIterator(const RBTreeIterator &node) noexcept
        : RBTreeIterator(node) {}
  };

  using iterator = RBTreeIterator;
  using const_iterator = RBTreeConstIterator;

  RBTree() noexcept {
    root_ = new RBTreeNode(value_type{});
    size_ = 0;
  }

  RBTree(std::initializer_list<value_type> const &items) : RBTree() {
    for (auto i = items.begin(); i != items.end(); i++) this->insert(*i);
  }

  RBTree(const RBTree &other) : RBTree() {
    for (const_iterator it = other.cbegin(); it != other.cend(); it++)
      this->insert(*it);
  }

  RBTree(RBTree &&other) noexcept : RBTree() {
    this->root_ = other.root_;
    this->size_ = other.size_;
    other.root_ = nullptr;
    other.size_ = 0;
  }

  ~RBTree() { clear(); }

  RBTree &operator=(RBTree &&t) {
    if (this != &t) {
      RBTree other(std::move(t));
      swap(other);
    }
    return this;
  }

  iterator begin() noexcept {
    return (root_->left) ? iterator(root_->left) : iterator(root_);
  }
  const_iterator cbegin() const noexcept {
    return (root_->left) ? const_iterator(root_->left) : const_iterator(root_);
  }

  iterator end() noexcept { return iterator(root_); }
  const_iterator cend() const noexcept { return const_iterator(root_); }

  bool empty() noexcept { return (size_ == 0) ? true : false; }

  size_type size() noexcept { return this->size_; }

  size_type max_size() {
    return std::numeric_limits<size_type>::max() / 2 / sizeof(RBTreeNode);
  }

  void clear() {
    DestroyNodes(root_->parent);
    root_->parent = nullptr;
    size_ = 0;
  }

  // Вставка узла в дерево (map, set)
  std::pair<iterator, bool> insert(const value_type &value) {
    RBTreeNode *node = new RBTreeNode(value);
    std::pair<iterator, bool> result = InsertNode(node, false);
    if (!result.second) DestroyNode(node);
    return result;
  }

  // Вставка узла в дерево (multiset)
  iterator insert_multi(const value_type &value) {
    RBTreeNode *node = new RBTreeNode(value);
    std::pair<iterator, bool> result = InsertNode(node, true);
    if (!result.second) DestroyNode(node);
    return result.first;
  }

  // Удаление узла из дерева
  void erase(iterator pos) { DeleteNode(pos); };

  // Меняет деревья местами
  void swap(RBTree &other) noexcept {
    std::swap(root_, other.root_);
    std::swap(size_, other.size_);
  }

  // Соединение другого дерева с текущим, исключая дубликаты
  void merge(RBTree &other) noexcept {
    if (this != &other) {
      iterator it = other.begin();
      while (it != other.end() && it.node_) {
        if (!this->contains(it.node_->value)) {
          RBTreeNode *node = it.node_;
          it++;
          node = other.ExtractNode(node);
          InsertNode(node, false);
        } else {
          it++;
        }
      }
    }
  }
  // Соединение другого дерева с текущим, включая дубликаты
  void merge_multi(RBTree &other) noexcept {
    if (this != &other) {
      iterator it = other.begin();
      while (other.size_ > 0) {
        RBTreeNode *node = it.node_;
        it++;
        if (node->parent->left == node) node->parent->left = nullptr;
        if (node->parent->right == node) node->parent->right = nullptr;
        if (node->left) node->left->parent = node->parent;
        if (node->right) node->right->parent = node->parent;
        node->left = nullptr;
        node->right = nullptr;
        node->parent = nullptr;
        node->color = RED;
        InsertNode(node, true);
        other.size_--;
      }
      other.root_->parent = nullptr;
      other.size_ = 0;
    }
  }

  // Поиск узла по значению
  iterator find(const Key &key) {
    iterator it = begin();
    for (; it != end() && it.node_->value != key; it++) {
    }
    return it;
  }

  // Проверка наличия значения в дереве
  bool contains(const Key &key) {
    bool result = false;
    for (iterator it = begin(); it != end() && !result && it.node_; it++)
      if (it.node_->value == key) result = true;
    return result;
  }

 private:
  RBTreeNode *root_;
  size_type size_;

  // Поворот влево
  void RotateLeft(RBTreeNode *node) {
    RBTreeNode *temp = node->right;
    node->right = temp->left;

    if (temp->left) temp->left->parent = node;
    temp->parent = node->parent;

    if (node->parent == root_)
      root_->parent = temp;
    else if (node == node->parent->left)
      node->parent->left = temp;
    else
      node->parent->right = temp;

    temp->left = node;
    node->parent = temp;
  }

  // Поворот вправо
  void RotateRight(RBTreeNode *node) {
    RBTreeNode *temp = node->left;
    node->left = temp->right;

    if (temp->right) temp->right->parent = node;
    temp->parent = node->parent;

    if (node->parent == root_)
      root_->parent = temp;
    else if (node == node->parent->right)
      node->parent->right = temp;
    else
      node->parent->left = temp;

    temp->right = node;
    node->parent = temp;
  }

  // Обмен нодами в текущем дереве
  void SwapNode(RBTreeNode *current, RBTreeNode *other) noexcept {
    if (current == root_->parent)
      root_->parent = other;
    else if (other == root_->parent)
      root_->parent = current;

    ((root_->parent != other) && (current == current->parent->left))
        ? current->parent->left = other
        : current->parent->right = other;

    ((root_->parent != current) && (other == other->parent->left))
        ? other->parent->left = current
        : other->parent->right = current;

    std::swap(current->color, other->color);
    std::swap(current->left, other->left);
    std::swap(current->right, other->right);
    std::swap(current->parent, other->parent);

    if (current->left) current->left->parent = current;
    if (current->right) current->right->parent = current;
    if (other->left) other->left->parent = other;
    if (other->right) other->right->parent = other;
  }

  // Вставка node в дерево
  std::pair<iterator, bool> InsertNode(RBTreeNode *node, bool allow_copy) {
    RBTreeNode *current_node = root_->parent;
    RBTreeNode *parent = nullptr;

    while (current_node) {
      parent = current_node;
      if (std::less<value_type>{}(node->value, current_node->value))
        current_node = current_node->left;
      else if (std::less<value_type>{}(current_node->value, node->value))
        current_node = current_node->right;
      else if (allow_copy)
        current_node = current_node->right;
      else
        return {iterator(current_node), false};
    }

    size_++;

    if (!parent) {
      node->parent = root_;
      root_->parent = node;
      node->color = BLACK;
    } else {
      node->parent = parent;
      (std::less<value_type>{}(node->value, parent->value))
          ? parent->left = node
          : parent->right = node;
    }

    if (!root_->right || root_->right->right) root_->right = node;
    if (!root_->left || root_->left->left) root_->left = node;

    BalanceAfterInsert(node);

    return {iterator(node), true};
  }

  RBTreeNode *GetRightEnd(RBTreeNode *node) noexcept {
    while (node->right) node = node->right;
    return node;
  }

  RBTreeNode *GetLeftEnd(RBTreeNode *node) noexcept {
    while (node->left) node = node->left;
    return node;
  }

  void DeleteNode(iterator pos) {
    if (pos == end()) return;

    RBTreeNode *node = pos.node_;
    if (node->left && node->right) SwapNode(node, GetRightEnd(node->left));

    if (!node->left && node->right) SwapNode(node, node->right);
    if (!node->right && node->left) SwapNode(node, node->left);
    if (node->color == BLACK && (!node->left && !node->right))
      BalanceAfterDelete(node);

    if (root_->parent == node) {
      root_->left = nullptr;
      root_->right = nullptr;
      root_->parent = nullptr;
    } else {
      node->parent->left == node ? node->parent->left = nullptr
                                 : node->parent->right = nullptr;
      if (root_->left == node) root_->left = GetLeftEnd(root_->parent);
      if (root_->right == node) root_->right = GetRightEnd(root_->parent);
    }

    DestroyNode(node);
    size_--;
  }

  void DestroyNode(RBTreeNode *node) {
    if (node) {
      node->left = nullptr;
      node->right = nullptr;
      node->parent = nullptr;
      delete node;
    }
  };

  void DestroyNodes(RBTreeNode *node) {
    if (node) {
      DestroyNodes(node->left);
      DestroyNodes(node->right);
      DestroyNode(node);
    }
  }

  // Балансировка дерева после вставки нового узла
  void BalanceAfterInsert(RBTreeNode *node) {
    RBTreeNode *uncle;
    while (node != root_->parent && node->parent->color == RED) {
      if (node->parent == node->parent->parent->left) {
        uncle = node->parent->parent->right;
        if (uncle && uncle->color == RED) {
          uncle->color = BLACK;
          node->parent->color = BLACK;
          node->parent->parent->color = RED;
          node = node->parent->parent;
        } else {
          if (node == node->parent->right) {
            node = node->parent;
            RotateLeft(node);
          }
          node->parent->color = BLACK;
          node->parent->parent->color = RED;
          RotateRight(node->parent->parent);
        }
      } else {
        uncle = node->parent->parent->left;
        if (uncle && uncle->color == RED) {
          uncle->color = BLACK;
          node->parent->color = BLACK;
          node->parent->parent->color = RED;
          node = node->parent->parent;
        } else {
          if (node == node->parent->left) {
            node = node->parent;
            RotateRight(node);
          }
          node->parent->color = BLACK;
          node->parent->parent->color = RED;
          RotateLeft(node->parent->parent);
        }
      }
    }
    root_->parent->color = BLACK;
  }

  // Балансировка дерева после удаление узла
  void BalanceAfterDelete(RBTreeNode *node) {
    RBTreeNode *brother = nullptr;
    while (node != root_->parent && node->color == BLACK) {
      if (node == node->parent->left) {
        brother = node->parent->right;
        if (brother->color == RED) {
          brother->color = BLACK;
          node->parent->color = RED;
          RotateLeft(node->parent);
          brother = node->parent->right;
        }
        if (brother->color == BLACK &&
            (!brother->left || brother->left->color == BLACK) &&
            (!brother->right || brother->right->color == BLACK)) {
          brother->color = RED;
          node = node->parent;
        } else {
          if (!brother->right || brother->right->color == BLACK) {
            brother->color = RED;
            brother->left->color = BLACK;
            RotateRight(brother);
            brother = node->parent->right;
          }
          brother->color = node->parent->color;
          brother->right->color = BLACK;
          node->parent->color = BLACK;
          RotateLeft(node->parent);
          node = root_->parent;
        }
      } else {
        brother = node->parent->left;
        if (brother->color == RED) {
          brother->color = BLACK;
          node->parent->color = RED;
          RotateRight(node->parent);
          brother = node->parent->left;
        }
        if (brother->color == BLACK &&
            (!brother->left || brother->left->color == BLACK) &&
            (!brother->right || brother->right->color == BLACK)) {
          brother->color = RED;
          node = node->parent;
        } else {
          if (!brother->left || brother->left->color == BLACK) {
            brother->color = RED;
            brother->right->color = BLACK;
            RotateLeft(brother);
            brother = node->parent->left;
          }
          brother->color = node->parent->color;
          brother->left->color = BLACK;
          node->parent->color = BLACK;
          RotateRight(node->parent);
          node = root_->parent;
        }
      }
    }
    node->color = BLACK;
  }

  RBTreeNode *ExtractNode(RBTreeNode *node) {
    RBTreeNode *result = nullptr;
    if (node != root_) {
      if (node->right && node->left) {
        RBTreeNode *temp = GetRightEnd(node->left);
        SwapNode(node, temp);
      }
      if (node->right && !node->left) SwapNode(node, node->right);
      if (node->left && !node->right) SwapNode(node, node->left);
      if (node->color == BLACK && (!node->right && !node->left))
        BalanceAfterDelete(node);

      iterator it(node);
      if (node == root_->left) {
        iterator temp = it;
        root_->left = (++temp).node_;
      }
      if (node == root_->right) {
        iterator temp = it;
        root_->right = (--temp).node_;
      }
      if (node == root_->parent)
        root_->parent = nullptr;
      else
        node == node->parent->left ? node->parent->left = nullptr
                                   : node->parent->right = nullptr;
      size_--;
      node->left = nullptr;
      node->right = nullptr;
      node->parent = nullptr;
      node->color = RED;
      result = node;
    }
    return result;
  }

  RBTreeNode *ExtractNodeMulti(RBTreeNode *node) {
    if (node->parent->left == node) node->parent->left = nullptr;
    if (node->parent->right == node) node->parent->right = nullptr;
    if (node->right) node->right->parent = node->parent;
    if (node->left) node->left->parent = node->parent;
    node->left = nullptr;
    node->right = nullptr;
    node->parent = nullptr;
    node->color = RED;
    return node;
  }
};
}  // namespace s21

#endif  // S21_RBTREE_H_