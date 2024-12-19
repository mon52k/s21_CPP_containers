#ifndef S21_VECTOR_H_
#define S21_VECTOR_H_

#include <iostream>
#include <limits>

namespace s21 {

template <typename T>
class vector {
 public:
  // Типовые алиасы
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = std::size_t;

  // Конструктор по умолчанию: инициализирует пустой вектор
  vector() : m_size(0), m_capacity(0), arr(nullptr) {}

  // Параметризированный конструктор: инициализирует вектор заданного размера
  explicit vector(size_type n) : vector() {
    m_size = m_capacity = n;
    if (n > 0) {
      arr = new value_type[m_capacity];
    }
  }

  // Конструктор списка инициализации: инициализирует вектор с данным списком
  vector(std::initializer_list<value_type> const &item) : vector(item.size()) {
    size_type i = 0;
    for (auto it = item.begin(); it != item.end(); it++) {
      arr[i] = *it;
      i++;
    }
  }

  // Конструктор копирования: создает копию данного вектора
  vector(const vector &v)
      : m_size(v.m_size),
        m_capacity(v.m_capacity),
        arr(new value_type[m_capacity]) {
    for (size_type i = 0; i < m_size; i++) {
      arr[i] = v.arr[i];
    }
  }

  // Конструктор перемещения: забирает содержимое данного вектора
  vector(vector &&v) : vector() { operator=(std::move(v)); }

  // деструктор
  ~vector() { delete[] arr; }

  // резервирует память для указанного числа элементов
  void reserve(size_type size) {
    if (size > max_size()) {
      throw std::length_error(
          "The new capacity number entered is greater than the maximum number "
          "of items the container can hold.");
    } else {
      if (size > m_capacity) {
        access_to_vector_capacity(size);
      }
    }
  }

  // для сокращения памяти (освобождение неиспользуемой памяти)
  void shrink_to_fit() {
    if (m_capacity > m_size) {
      access_to_vector_capacity(m_size);
    }
  }

  // Вставляет  элемент в конкретную позицию
  iterator insert(iterator pos, const_reference value) {
    size_type zero = 0;
    size_type shift = std::distance(begin(), pos);
    if (shift < zero || shift > m_size) {
      throw std::out_of_range("The specified position is outside the vector");
    }
    if (m_size + 1 > m_capacity) {
      reserve(m_capacity * 2);
    }
    value_type buf = arr[shift];
    m_size++;
    arr[shift] = value;
    for (size_type i = shift + 1; i < m_size; i++) {
      std::swap(buf, arr[i]);
    }
    return arr + shift;
  }

  // Очищает все содержимое вектора
  void clear() noexcept { m_size = 0; }

  // Erase element at a specific position
  void erase(iterator pos) {
    size_type zero = 0;
    size_type shift = std::distance(begin(), pos);
    if (shift < zero || shift > m_size) {
      throw std::out_of_range("The specified position is outside the vector");
    }
    std::copy(const_cast<iterator>(pos) + 1, end(), arr + shift);
    m_size--;
  }

  // добавляет элемент в конец
  void push_back(const_reference value) { insert(end(), value); }

  // удаляет последний элемент
  void pop_back() {
    if (empty()) {
      throw std::logic_error("vector is empty, can't delete last element");
    }
    m_size--;
  }

  // Обменивается содержимым с другим вектором
  void swap(vector &other) {
    std::swap(arr, other.arr);
    std::swap(m_size, other.m_size);
    std::swap(m_capacity, other.m_capacity);
  }

  // размещает элемент в конкретную позицию
  template <class... Args>
  iterator emplace(const_iterator pos, Args &&...args) {
    auto shift = pos - begin();
    iterator it = nullptr;
    for (const auto &element : {std::forward<Args>(args)...}) {
      it = insert(begin() + shift, element);
      shift++;
    }
    return it;
  }

  // Добавляет новые элементы в конец контейнера
  template <class... Args>
  void emplace_back(Args &&...args) {
    for (const auto &element : {std::forward<Args>(args)...}) {
      push_back(element);
    }
  }

  // Доступ к указанному элементу с проверкой границ
  reference at(size_type pos) {
    if (pos >= m_size) {
      throw std::out_of_range(
          "The position of the returned element does not match the range of "
          "the container");
    } else {
      return arr[pos];
    }
  }

  // Доступ к указанному элементу без проверки границ
  reference operator[](size_type pos) { return arr[pos]; }

  // Доступ к указанному элементу с проверкой границ (const)
  const_reference at(size_type pos) const {
    if (pos >= m_size) {
      throw std::out_of_range(
          "The position of the returned element does not match the range of "
          "the container");
    } else {
      return arr[pos];
    }
  }

  // Доступ к указанному элементу без проверки границ (const)
  const_reference operator[](size_type pos) const { return arr[pos]; }

  // Access the first element
  const_reference front() const {
    if (empty()) {
      throw std::logic_error(
          "Cannot access front element because vector is empty");
    }
    return arr[0];
  }

  // доступ к последнему элементу
  const_reference back() const {
    if (empty()) {
      throw std::logic_error(
          "Cannot access back element because vector is empty");
    }
    return arr[m_size - 1];
  }

  // Прямой доступ к базовому массиву
  iterator data() noexcept { return arr; }

  // Прямой доступ к базовому массиву (const)
  const_iterator data() const noexcept { return arr; }

  // Возвращает итератор на начало
  iterator begin() noexcept { return arr; }

  // Возвращает const итератор на начало
  const_iterator begin() const noexcept { return arr; }

  // Возвращает итератор на конец
  iterator end() noexcept { return arr + m_size; }

  // озвращает const итератор на конец
  const_iterator end() const noexcept { return arr + m_size; }

  // Возвращает количество элементов в векторе.
  size_type size() const noexcept { return m_size; }

  // Возвращает общее количество элементов, которые вектор может содержать
  // перед необходимостью выделить больше памяти.
  size_type capacity() const noexcept { return m_capacity; }

  // Проверяет, есть ли в векторе элементы, т.е. если begin() == end().
  bool empty() const noexcept { return begin() == end(); }

  size_type max_size() const noexcept {
    return (std::numeric_limits<size_type>::max() / sizeof(value_type) / 2);
  }

  // Оператор присваивания перемещения: передает владение ресурсами, которыми
  // управляет данный вектор, в *this. После этой операции исходный вектор (v)
  // остается в допустимом, но неопределенном состоянии.
  vector &operator=(vector &&v) {
    if (this != &v) {
      delete[] arr;
      m_size = v.m_size;
      m_capacity = v.m_capacity;
      arr = v.arr;
      v.m_size = 0;
      v.m_capacity = 0;
      v.arr = nullptr;
    }
    return *this;
  }

 private:
  size_type m_size;
  size_type m_capacity;
  T *arr;

  void access_to_vector_capacity(size_type size) {
    iterator buff = new value_type[size];
    for (size_type i = 0; i < m_size; ++i) {
      buff[i] = std::move(arr[i]);
    }
    delete[] arr;
    arr = buff;
    m_capacity = size;
  }
};  // namespace s21
}  // namespace s21

#endif  // S21_VECTOR_H_