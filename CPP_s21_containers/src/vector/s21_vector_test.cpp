#include "s21_vector.h"

#include <gtest/gtest.h>

#include <vector>

TEST(s21_vector_test, test_default_constructor_1) {
  s21::vector<char> vector_tst;
  std::vector<char> vector_std;
  ASSERT_EQ(vector_tst.size(), vector_std.size());
  ASSERT_EQ(vector_tst.max_size(), vector_std.max_size());
  ASSERT_EQ(vector_tst.empty(), vector_std.empty());
}

TEST(s21_vector_test, test_default_constructor_2) {
  s21::vector<int> vector_tst;
  std::vector<int> vector_std;
  ASSERT_EQ(vector_tst.size(), vector_std.size());
  ASSERT_EQ(vector_tst.max_size(), vector_std.max_size());
  ASSERT_EQ(vector_tst.empty(), vector_std.empty());
}

TEST(s21_vector_test, test_default_constructor_3) {
  s21::vector<double> vector_tst;
  std::vector<double> vector_std;
  ASSERT_EQ(vector_tst.size(), vector_std.size());
  ASSERT_EQ(vector_tst.max_size(), vector_std.max_size());
  ASSERT_EQ(vector_tst.empty(), vector_std.empty());
}

TEST(s21_vector_test, test_default_constructor_4) {
  s21::vector<std::string> vector_tst;
  std::vector<std::string> vector_std;
  ASSERT_EQ(vector_tst.size(), vector_std.size());
  ASSERT_EQ(vector_tst.max_size(), vector_std.max_size());
  ASSERT_EQ(vector_tst.empty(), vector_std.empty());
}

TEST(s21_vector_test, test_size_constructor_1) {
  s21::vector<char> vector_tst(5);
  std::vector<char> vector_std(5);
  ASSERT_EQ(vector_tst.size(), vector_std.size());
  ASSERT_EQ(vector_tst.max_size(), vector_std.max_size());
  ASSERT_EQ(vector_tst.empty(), vector_std.empty());
}

TEST(s21_vector_test, test_size_constructor_2) {
  s21::vector<int> vector_tst(5);
  std::vector<int> vector_std(5);
  ASSERT_EQ(vector_tst.size(), vector_std.size());
  ASSERT_EQ(vector_tst.max_size(), vector_std.max_size());
  ASSERT_EQ(vector_tst.empty(), vector_std.empty());
}

TEST(s21_vector_test, test_size_constructor_3) {
  s21::vector<double> vector_tst(5);
  std::vector<double> vector_std(5);
  ASSERT_EQ(vector_tst.size(), vector_std.size());
  ASSERT_EQ(vector_tst.max_size(), vector_std.max_size());
  ASSERT_EQ(vector_tst.empty(), vector_std.empty());
}

TEST(s21_vector_test, test_size_constructor_4) {
  s21::vector<std::string> vector_tst(5);
  std::vector<std::string> vector_std(5);
  ASSERT_EQ(vector_tst.size(), vector_std.size());
  ASSERT_EQ(vector_tst.max_size(), vector_std.max_size());
  ASSERT_EQ(vector_tst.empty(), vector_std.empty());
}

TEST(s21_vector_test, test_list_constructor_1) {
  s21::vector<char> vector_tst = {'a', 'b', 'x', 'z'};
  std::vector<char> vector_std = {'a', 'b', 'x', 'z'};
  ASSERT_EQ(vector_tst.size(), vector_std.size());
  ASSERT_EQ(vector_tst.max_size(), vector_std.max_size());
  ASSERT_EQ(vector_tst.empty(), vector_std.empty());
}

TEST(s21_vector_test, test_list_constructor_2) {
  s21::vector<int> vector_tst = {0, 1, 500, -500};
  std::vector<int> vector_std = {0, 1, 500, -500};
  ASSERT_EQ(vector_tst.size(), vector_std.size());
  ASSERT_EQ(vector_tst.max_size(), vector_std.max_size());
  ASSERT_EQ(vector_tst.empty(), vector_std.empty());
}

TEST(s21_vector_test, test_list_constructor_3) {
  s21::vector<double> vector_tst = {-123.456, 0.0, -0.0, 567.890};
  std::vector<double> vector_std = {-123.456, 0.0, -0.0, 567.890};
}

TEST(s21_vector_test, test_list_constructor_4) {
  s21::vector<std::string> vector_tst = {"begin", "123-2", "wtf?", "END!"};
  std::vector<std::string> vector_std = {"begin", "123-2", "wtf?", "END!"};
  ASSERT_EQ(vector_tst.size(), vector_std.size());
  ASSERT_EQ(vector_tst.max_size(), vector_std.max_size());
  ASSERT_EQ(vector_tst.empty(), vector_std.empty());
}

TEST(s21_vector_test, test_copy_constructor_1) {
  s21::vector<char> s21_vec_src = {'a', 'b', 'x', 'z'};
  std::vector<char> std_vec_src(s21_vec_src.begin(), s21_vec_src.end());
  for (size_t i = 0; i < s21_vec_src.size(); i++) {
    ASSERT_EQ(s21_vec_src[i], std_vec_src[i]);
  }
}

TEST(s21_vector_test, test_copy_constructor_2) {
  s21::vector<int> s21_vec_src = {0, 1, 500, -500};
  std::vector<int> std_vec_src(s21_vec_src.begin(), s21_vec_src.end());
  for (size_t i = 0; i < s21_vec_src.size(); i++) {
    ASSERT_EQ(s21_vec_src[i], std_vec_src[i]);
  }
}

TEST(s21_vector_test, test_copy_constructor_3) {
  s21::vector<double> s21_vec_src = {-123.456, 0.0, -0.0, 567.890};
  std::vector<double> std_vec_src(s21_vec_src.begin(), s21_vec_src.end());
  for (size_t i = 0; i < s21_vec_src.size(); i++) {
    ASSERT_EQ(s21_vec_src[i], std_vec_src[i]);
  }
}

TEST(s21_vector_test, test_copy_constructor_4) {
  s21::vector<std::string> s21_vec_src = {"begin", "123-2", "wtf?", "END!"};
  std::vector<std::string> std_vec_src(s21_vec_src.begin(), s21_vec_src.end());
  for (size_t i = 0; i < s21_vec_src.size(); i++) {
    ASSERT_EQ(s21_vec_src[i], std_vec_src[i]);
  }
}

TEST(s21_vector_test, test_move_constructor_1) {
  s21::vector<int> s21_vector_src = {1, 2, 3};
  s21::vector<int> s21_vector_moved(std::move(s21_vector_src));

  std::vector<int> std_vector_src = {1, 2, 3};
  std::vector<int> std_vector_moved(std::move(std_vector_src));

  EXPECT_EQ(s21_vector_moved.size(), std_vector_moved.size());
  EXPECT_EQ(s21_vector_moved.capacity(), std_vector_moved.capacity());
  EXPECT_EQ(s21_vector_moved.front(), std_vector_moved.front());
  EXPECT_EQ(s21_vector_moved.back(), std_vector_moved.back());
  EXPECT_EQ(s21_vector_moved.at(1), std_vector_moved.at(1));
  EXPECT_NE(s21_vector_moved.data(), nullptr);
  EXPECT_FALSE(s21_vector_moved.empty());

  EXPECT_EQ(s21_vector_src.size(), 0u);
  EXPECT_TRUE(s21_vector_src.empty());

  EXPECT_EQ(std_vector_src.size(), 0u);
  EXPECT_TRUE(std_vector_src.empty());
}

TEST(s21_vector_test, at) {
  s21::vector<int> s21_vector = {1, 2, 3};
  std::vector<int> std_vector = {1, 2, 3};
  EXPECT_EQ(s21_vector.at(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.at(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.at(2), std_vector.at(2));
}

TEST(s21_vector_test, at_char_const) {
  const s21::vector<char> s21_vector = {'a', 'b', 'c'};
  const std::vector<char> std_vector = {'a', 'b', 'c'};
  EXPECT_EQ(s21_vector.at(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.at(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.at(2), std_vector.at(2));
}

TEST(s21_vector_test, at_insert) {
  s21::vector<int> s21_vector = {1, 2, 3};
  std::vector<int> std_vector = {1, 2, 3};
  s21_vector.at(1) = 777;
  std_vector.at(1) = 777;
  EXPECT_EQ(s21_vector.at(0), std_vector.at(0));
  EXPECT_EQ(s21_vector.at(1), std_vector.at(1));
  EXPECT_EQ(s21_vector.at(2), std_vector.at(2));
}

TEST(s21_vector_test, operator_sq_brackets) {
  s21::vector<int> s21_vector = {1, 2, 3};
  std::vector<int> std_vector = {1, 2, 3};
  EXPECT_EQ(s21_vector[0], std_vector[0]);
  EXPECT_EQ(s21_vector[1], std_vector[1]);
  EXPECT_EQ(s21_vector[2], std_vector[2]);
}

TEST(s21_vector_test, operator_sq_brackets_char_const) {
  const s21::vector<char> s21_vector = {'a', 'b', 'c'};
  const std::vector<char> std_vector = {'a', 'b', 'c'};
  EXPECT_EQ(s21_vector[0], std_vector[0]);
  EXPECT_EQ(s21_vector[1], std_vector[1]);
  EXPECT_EQ(s21_vector[2], std_vector[2]);
}

TEST(s21_vector_test, operator_sq_brackets_insert) {
  s21::vector<int> s21_vector = {1, 2, 3};
  std::vector<int> std_vector = {1, 2, 3};
  s21_vector[1] = 777;
  std_vector[1] = 777;
  EXPECT_EQ(s21_vector[0], std_vector[0]);
  EXPECT_EQ(s21_vector[1], std_vector[1]);
  EXPECT_EQ(s21_vector[2], std_vector[2]);
}

TEST(s21_vector_test, front) {
  s21::vector<int> s21_vector = {1, 2, 3};
  std::vector<int> std_vector = {1, 2, 3};
  EXPECT_EQ(s21_vector.front(), std_vector.front());
}

TEST(s21_vector_test, back) {
  s21::vector<int> s21_vector = {1, 2, 3};
  std::vector<int> std_vector = {1, 2, 3};
  EXPECT_EQ(s21_vector.back(), std_vector.back());
}

TEST(s21_vector_test, data) {
  s21::vector<int> s21_vector = {1, 2, 3};
  std::vector<int> std_vector = {1, 2, 3};
  EXPECT_EQ(*s21_vector.data(), *std_vector.data());
}

TEST(s21_vector_test, data_const) {
  const s21::vector<int> s21_vector = {1, 2, 3};
  const std::vector<int> std_vector = {1, 2, 3};
  EXPECT_EQ(*s21_vector.data(), *std_vector.data());
}

TEST(s21_vector_test, data_empty) {
  s21::vector<int> s21_vector;
  std::vector<int> std_vector;

  EXPECT_TRUE(s21_vector.empty() && std_vector.empty());
}

TEST(s21_vector_test, begin) {
  s21::vector<int> s21_vector = {1, 2, 3};
  auto example = s21_vector.begin();
  EXPECT_EQ(s21_vector.front(), *example);
}

TEST(s21_vector_test, begin_empty) {
  s21::vector<int> s21_vector;
  EXPECT_EQ(s21_vector.begin(), nullptr);
}

TEST(s21_vector_test, end) {
  s21::vector<int> s21_vector = {1, 2, 3};
  auto example = s21_vector.end() - 1;
  EXPECT_EQ(s21_vector.back(), *example);
}

TEST(s21_vector_test, end_empty) {
  s21::vector<int> s21_vector;
  EXPECT_EQ(s21_vector.end(), nullptr);
}

TEST(s21_vector_test, empty) {
  s21::vector<int> s21_vector;
  EXPECT_TRUE(s21_vector.empty());
}

TEST(s21_vector_test, not_empty) {
  s21::vector<int> s21_vector = {1, 2, 3};
  EXPECT_FALSE(s21_vector.empty());
}

TEST(s21_vector_test, size) {
  s21::vector<int> s21_vector = {1, 2, 3};
  EXPECT_EQ(s21_vector.size(), 3);
}

TEST(s21_vector_test, size_empty) {
  s21::vector<int> s21_vector;
  EXPECT_EQ(s21_vector.size(), 0);
}

TEST(s21_vector_test, max_size_int) {
  s21::vector<int> s21_v_int;
  std::vector<int> std_v_int;
  EXPECT_EQ(s21_v_int.max_size(), std_v_int.max_size());
}

TEST(s21_vector_test, max_size_char) {
  s21::vector<char> s21_v_char;
  std::vector<char> std_v_char;
  EXPECT_EQ(s21_v_char.max_size(), std_v_char.max_size());
}

TEST(s21_vector_test, max_size_double) {
  s21::vector<double> s21_v_double;
  std::vector<double> std_v_double;
  EXPECT_EQ(s21_v_double.max_size(), std_v_double.max_size());
}

TEST(s21_vector_test, reserve) {
  s21::vector<int> s21_vector = {1, 2, 3};
  s21_vector.reserve(6);
  std::vector<int> std_vector = {1, 2, 3};
  std_vector.reserve(6);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  auto i = 0;
  for (auto it = std_vector.begin(); it != std_vector.end(); it++) {
    EXPECT_EQ(s21_vector.at(i), *it);
    i++;
  }
}

TEST(s21_vector_test, shrink_to_fit) {
  s21::vector<int> s21_vector = {1, 2, 3};
  s21_vector.reserve(10);
  std::vector<int> std_vector = {1, 2, 3};
  std_vector.reserve(10);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());

  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  auto i = 0;
  for (auto it = std_vector.begin(); it != std_vector.end(); it++) {
    EXPECT_EQ(s21_vector.at(i), *it);
    i++;
  }
}

TEST(s21_vector_test, clear) {
  s21::vector<int> s21_vector = {1, 2, 3};
  s21_vector.clear();
  std::vector<int> std_vector = {1, 2, 3};
  std_vector.clear();
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(s21_vector_test, insert_begin) {
  s21::vector<int> s21_vector = {1, 2, 3};
  s21_vector.insert(s21_vector.begin(), 100);
  std::vector<int> std_vector = {1, 2, 3};
  std_vector.insert(std_vector.begin(), 100);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());

  auto i = 0;
  for (auto it = std_vector.begin(); it != std_vector.end(); it++) {
    EXPECT_EQ(s21_vector.at(i), *it);
    i++;
  }
}

TEST(s21_vector_test, insert_begin_char) {
  s21::vector<char> s21_vector = {'a', 'b', 'c'};
  s21_vector.insert(s21_vector.begin(), 'd');
  std::vector<char> std_vector = {'a', 'b', 'c'};
  std_vector.insert(std_vector.begin(), 'd');
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());

  auto i = 0;
  for (auto it = std_vector.begin(); it != std_vector.end(); it++) {
    EXPECT_EQ(s21_vector.at(i), *it);
    i++;
  }
}

TEST(s21_vector_test, insert_end) {
  s21::vector<int> s21_vector = {1, 2, 3};
  s21_vector.insert(s21_vector.end(), 100);
  std::vector<int> std_vector = {1, 2, 3};
  std_vector.insert(std_vector.end(), 100);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());

  auto i = 0;
  for (auto it = std_vector.begin(); it != std_vector.end(); it++) {
    EXPECT_EQ(s21_vector.at(i), *it);
    i++;
  }
}

TEST(s21_vector_test, insert_middle) {
  s21::vector<int> s21_vector = {1, 2, 3};
  s21_vector.insert(s21_vector.begin() + 1, 100);
  std::vector<int> std_vector = {1, 2, 3};
  std_vector.insert(std_vector.begin() + 1, 100);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());

  auto i = 0;
  for (auto it = std_vector.begin(); it != std_vector.end(); it++) {
    EXPECT_EQ(s21_vector.at(i), *it);
    i++;
  }
}

TEST(s21_vector_test, erase_begin) {
  s21::vector<int> s21_vector = {1, 2, 3};
  s21_vector.erase(s21_vector.begin());
  std::vector<int> std_vector = {1, 2, 3};
  std_vector.erase(std_vector.begin());
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());

  auto i = 0;
  for (auto it = std_vector.begin(); it != std_vector.end(); it++) {
    EXPECT_EQ(s21_vector.at(i), *it);
    i++;
  }
}

TEST(s21_vector_test, erase_begin_char) {
  s21::vector<char> s21_vector = {'a', 'b', 'c'};
  s21_vector.erase(s21_vector.begin());
  std::vector<char> std_vector = {'a', 'b', 'c'};
  std_vector.erase(std_vector.begin());
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());

  auto i = 0;
  for (auto it = std_vector.begin(); it != std_vector.end(); it++) {
    EXPECT_EQ(s21_vector.at(i), *it);
    i++;
  }
}

TEST(s21_vector_test, erase_end) {
  s21::vector<int> s21_vector = {1, 2, 3};
  s21_vector.erase(s21_vector.end() - 1);
  std::vector<int> std_vector = {1, 2, 3};
  std_vector.erase(std_vector.end() - 1);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());

  auto i = 0;
  for (auto it = std_vector.begin(); it != std_vector.end(); it++) {
    EXPECT_EQ(s21_vector.at(i), *it);
    i++;
  }
}

TEST(s21_vector_test, erase_middle) {
  s21::vector<int> s21_vector = {1, 2, 3};
  s21_vector.erase(s21_vector.end() - 2);
  std::vector<int> std_vector = {1, 2, 3};
  std_vector.erase(std_vector.end() - 2);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());

  auto i = 0;
  for (auto it = std_vector.begin(); it != std_vector.end(); it++) {
    EXPECT_EQ(s21_vector.at(i), *it);
    i++;
  }
}

TEST(s21_vector_test, push_back_eq) {
  s21::vector<int> s21_vector = {1, 2, 3};
  s21_vector.push_back(100);
  std::vector<int> std_vector = {1, 2, 3};
  std_vector.push_back(100);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());

  auto i = 0;
  for (auto it = std_vector.begin(); it != std_vector.end(); it++) {
    EXPECT_EQ(s21_vector.at(i), *it);
    i++;
  }
}

TEST(s21_vector_test, push_back_eq_char) {
  s21::vector<char> s21_vector = {'a', 'b', 'c'};
  s21_vector.push_back(100);
  std::vector<char> std_vector = {'a', 'b', 'c'};
  std_vector.push_back(100);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());

  auto i = 0;
  for (auto it = std_vector.begin(); it != std_vector.end(); it++) {
    EXPECT_EQ(s21_vector.at(i), *it);
    i++;
  }
}

TEST(s21_vector_test, push_back_not_eq) {
  s21::vector<int> s21_vector = {1, 2, 3};
  s21_vector.reserve(4);
  s21_vector.push_back(100);
  std::vector<int> std_vector = {1, 2, 3};
  std_vector.reserve(4);
  std_vector.push_back(100);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());

  auto i = 0;
  for (auto it = std_vector.begin(); it != std_vector.end(); it++) {
    EXPECT_EQ(s21_vector.at(i), *it);
    i++;
  }
}

TEST(s21_vector_test, push_back_negative) {
  s21::vector<int> s21_vector = {1, 2, 3};
  s21_vector.push_back(-100);
  std::vector<int> std_vector = {1, 2, 3};
  std_vector.push_back(-100);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());

  auto i = 0;
  for (auto it = std_vector.begin(); it != std_vector.end(); it++) {
    EXPECT_EQ(s21_vector.at(i), *it);
    i++;
  }
}

TEST(s21_vector_test, push_back_double) {
  s21::vector<double> s21_vector = {1, 2, 3};
  s21_vector.push_back(12.21);
  std::vector<double> std_vector = {1, 2, 3};
  std_vector.push_back(12.21);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());

  auto i = 0;
  for (auto it = std_vector.begin(); it != std_vector.end(); it++) {
    EXPECT_EQ(s21_vector.at(i), *it);
    i++;
  }
}

TEST(s21_vector_test, push_back_repeatedly) {
  s21::vector<double> s21_vector = {1, 2, 3};
  size_t sz = 10;
  while (sz-- > 0) {
    s21_vector.push_back(12.21);
  }
  std::vector<double> std_vector = {1, 2, 3};
  size_t sz2 = 10;
  while (sz2-- > 0) {
    std_vector.push_back(12.21);
  }
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());

  auto i = 0;
  for (auto it = std_vector.begin(); it != std_vector.end(); it++) {
    EXPECT_EQ(s21_vector.at(i), *it);
    i++;
  }
}

TEST(s21_vector_test, pop_back) {
  s21::vector<int> s21_vector = {1, 2, 3};
  s21_vector.pop_back();
  std::vector<int> std_vector = {1, 2, 3};
  std_vector.pop_back();
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());

  auto i = 0;
  for (auto it = std_vector.begin(); it != std_vector.end(); it++) {
    EXPECT_EQ(s21_vector.at(i), *it);
    i++;
  }
}

TEST(s21_vector_test, pop_back_char) {
  s21::vector<char> s21_vector = {'a', 'b', 'c'};
  s21_vector.pop_back();
  std::vector<char> std_vector = {'a', 'b', 'c'};
  std_vector.pop_back();
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());

  auto i = 0;
  for (auto it = std_vector.begin(); it != std_vector.end(); it++) {
    EXPECT_EQ(s21_vector.at(i), *it);
    i++;
  }
}

TEST(s21_vector_test, swap) {
  s21::vector<int> s21_vector = {1, 2, 3};
  s21::vector<int> s21_test = {500, 400, 300, 200, 100};
  s21_vector.swap(s21_test);
  std::vector<int> std_vector = {1, 2, 3};
  std::vector<int> std_test = {500, 400, 300, 200, 100};
  std_vector.swap(std_test);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_test.size(), std_test.size());
  EXPECT_EQ(s21_test.capacity(), std_test.capacity());

  auto i = 0;
  for (auto it = std_vector.begin(); it != std_vector.end(); it++) {
    EXPECT_EQ(s21_vector.at(i), *it);
    i++;
  }

  auto j = 0;
  for (auto it = std_test.begin(); it != std_test.end(); it++) {
    EXPECT_EQ(s21_test.at(j), *it);
    j++;
  }
}

TEST(s21_vector_test, emplace_begin) {
  s21::vector<int> s21_vector = {1, 2, 3};
  auto s21_it = s21_vector.begin();
  s21_vector.emplace(s21_it, 0);

  std::vector<int> std_vector = {1, 2, 3};
  auto std_it = std_vector.begin();
  std_vector.emplace(std_it, 0);

  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  auto i = 0;
  for (auto it = std_vector.begin(); it != std_vector.end(); it++) {
    EXPECT_EQ(s21_vector.at(i), *it);
    i++;
  }
}

TEST(s21_vector_test, emplace_middle) {
  s21::vector<int> s21_vector = {1, 2, 3};
  auto s21_it = s21_vector.begin();
  s21_it++;
  s21_vector.emplace(s21_it, 9, 8, 7);
  std::vector<int> std_vector = {1, 9, 8, 7, 2, 3};

  auto i = 0;
  for (auto it = std_vector.begin(); it != std_vector.end(); it++) {
    EXPECT_EQ(s21_vector.at(i), *it);
    i++;
  }
}

TEST(s21_vector_test, emplace_back) {
  s21::vector<int> s21_vector = {1, 2, 3};
  s21_vector.emplace_back(4);
  std::vector<int> std_vector = {1, 2, 3};
  std_vector.emplace_back(4);

  EXPECT_EQ(s21_vector.size(), std_vector.size());
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  auto i = 0;
  for (auto it = std_vector.begin(); it != std_vector.end(); it++) {
    EXPECT_EQ(s21_vector.at(i), *it);
    i++;
  }
}

TEST(s21_vector_test, emplace_back_1) {
  s21::vector<int> s21_vector = {1, 2, 3};
  s21_vector.emplace_back(4, 5, 6);
  std::vector<int> std_vector = {1, 2, 3, 4, 5, 6};

  auto i = 0;
  for (auto it = std_vector.begin(); it != std_vector.end(); it++) {
    EXPECT_EQ(s21_vector.at(i), *it);
    i++;
  }
}
