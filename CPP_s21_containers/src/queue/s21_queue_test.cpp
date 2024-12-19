#include "s21_queue.h"

#include <gtest/gtest.h>

#include <list>
#include <queue>

// =======================
// Test of default constructor
// =======================

TEST(s21_queue_test, test_default_constructor_1) {
  s21::queue<char> queue_tst;
  std::queue<char> queue_std;
  ASSERT_EQ(queue_tst.current_size(), queue_std.size());
  ASSERT_EQ(queue_tst.empty_list(), queue_std.empty());
}

TEST(s21_queue_test, test_default_constructor_2) {
  s21::queue<int> queue_tst;
  std::queue<int> queue_std;
  ASSERT_EQ(queue_tst.current_size(), queue_std.size());
  ASSERT_EQ(queue_tst.empty_list(), queue_std.empty());
}

TEST(s21_queue_test, test_default_constructor_3) {
  s21::queue<double> queue_tst;
  std::queue<double> queue_std;
  ASSERT_EQ(queue_tst.current_size(), queue_std.size());
  ASSERT_EQ(queue_tst.empty_list(), queue_std.empty());
}

TEST(s21_queue_test, test_default_constructor_4) {
  s21::queue<std::string> queue_tst;
  std::queue<std::string> queue_std;
  ASSERT_EQ(queue_tst.current_size(), queue_std.size());
  ASSERT_EQ(queue_tst.empty_list(), queue_std.empty());
}

// =======================
// Test of queue constructor
// =======================

TEST(s21_queue_test, test_queue_constructor_1) {
  s21::queue<char> queue_tst = {'a', 'b', 'x', 'z'};
  std::queue<char> queue_std;
  queue_std.push('a');
  queue_std.push('b');
  queue_std.push('x');
  queue_std.push('z');
  ASSERT_EQ(queue_tst.current_size(), queue_std.size());
  ASSERT_EQ(queue_tst.empty_list(), queue_std.empty());
}

TEST(s21_queue_test, test_queue_constructor_2) {
  s21::queue<int> queue_tst = {0, 1, 500, -500};
  std::queue<int> queue_std;
  queue_std.push(0);
  queue_std.push(1);
  queue_std.push(500);
  queue_std.push(-500);
  ASSERT_EQ(queue_tst.current_size(), queue_std.size());
  ASSERT_EQ(queue_tst.empty_list(), queue_std.empty());
}

TEST(s21_queue_test, test_queue_constructor_3) {
  s21::queue<double> queue_tst = {-123.456, 0.0, -0.0, 567.890};
  std::queue<double> queue_std;
  queue_std.push(-123.456);
  queue_std.push(0.0);
  queue_std.push(-0.0);
  queue_std.push(567.890);
  ASSERT_EQ(queue_tst.current_size(), queue_std.size());
  ASSERT_EQ(queue_tst.empty_list(), queue_std.empty());
}

TEST(s21_queue_test, test_queue_constructor_4) {
  s21::queue<std::string> queue_tst = {"begin", "123-2", "wtf?", "END!"};
  std::queue<std::string> queue_std;
  queue_std.push("begin");
  queue_std.push("123-2");
  queue_std.push("wtf?");
  queue_std.push("END!");
  ASSERT_EQ(queue_tst.current_size(), queue_std.size());
  ASSERT_EQ(queue_tst.empty_list(), queue_std.empty());
}

// =======================
// Test of copy constructor
// =======================

TEST(s21_queue_test, test_copy_constructor_1) {
  s21::queue<char> queue_tst_src = {'a', 'b', 'x', 'z'};
  s21::queue<char> queue_tst_dst(queue_tst_src);
  for (size_t i = queue_tst_src.current_size(); i > 0; i--) {
    ASSERT_EQ(queue_tst_src.front(), queue_tst_dst.front());
    ASSERT_EQ(queue_tst_src.back(), queue_tst_dst.back());
    queue_tst_src.del_pop();
    queue_tst_dst.del_pop();
  }
}

TEST(s21_queue_test, test_copy_constructor_2) {
  s21::queue<int> queue_tst_src = {0, 1, 500, -500};
  s21::queue<int> queue_tst_dst(queue_tst_src);
  for (size_t i = queue_tst_src.current_size(); i > 0; i--) {
    ASSERT_EQ(queue_tst_src.front(), queue_tst_dst.front());
    ASSERT_EQ(queue_tst_src.back(), queue_tst_dst.back());
    queue_tst_src.del_pop();
    queue_tst_dst.del_pop();
  }
}

TEST(s21_queue_test, test_copy_constructor_3) {
  s21::queue<double> queue_tst_src = {-123.456, 0.0, -0.0, 567.890};
  s21::queue<double> queue_tst_dst(queue_tst_src);
  for (size_t i = queue_tst_src.current_size(); i > 0; i--) {
    ASSERT_EQ(queue_tst_src.front(), queue_tst_dst.front());
    ASSERT_EQ(queue_tst_src.back(), queue_tst_dst.back());
    queue_tst_src.del_pop();
    queue_tst_dst.del_pop();
  }
}

TEST(s21_queue_test, test_copy_constructor_4) {
  s21::queue<std::string> queue_tst_src = {"begin", "123-2", "wtf?", "END!"};
  s21::queue<std::string> queue_tst_dst(queue_tst_src);
  for (size_t i = queue_tst_src.current_size(); i > 0; i--) {
    ASSERT_EQ(queue_tst_src.front(), queue_tst_dst.front());
    ASSERT_EQ(queue_tst_src.back(), queue_tst_dst.back());
    queue_tst_src.del_pop();
    queue_tst_dst.del_pop();
  }
}

// =======================
// Test of assignment constructor
// =======================

TEST(s21_queue_test, test_assign_constructor_1) {
  s21::queue<char> queue_tst = {'a', 'b', 'x', 'z'};
  s21::queue<char> queue_tst_src = {'a', 'b', 'x', 'z'};
  s21::queue<char> queue_tst_dst = std::move(queue_tst_src);
  for (size_t i = queue_tst_src.current_size(); i > 0; i--) {
    ASSERT_EQ(queue_tst.front(), queue_tst_dst.front());
    ASSERT_EQ(queue_tst.back(), queue_tst_dst.back());
    queue_tst.del_pop();
    queue_tst_dst.del_pop();
  }
}

TEST(s21_queue_test, test_assign_constructor_2) {
  s21::queue<int> queue_tst = {0, 1, 500, -500};
  s21::queue<int> queue_tst_src = {0, 1, 500, -500};
  s21::queue<int> queue_tst_dst = std::move(queue_tst_src);
  for (size_t i = queue_tst_src.current_size(); i > 0; i--) {
    ASSERT_EQ(queue_tst.front(), queue_tst_dst.front());
    ASSERT_EQ(queue_tst.back(), queue_tst_dst.back());
    queue_tst.del_pop();
    queue_tst_dst.del_pop();
  }
}

TEST(s21_queue_test, test_assign_constructor_3) {
  s21::queue<double> queue_tst = {-123.456, 0.0, -0.0, 567.890};
  s21::queue<double> queue_tst_src = {-123.456, 0.0, -0.0, 567.890};
  s21::queue<double> queue_tst_dst = std::move(queue_tst_src);
  for (size_t i = queue_tst_src.current_size(); i > 0; i--) {
    ASSERT_EQ(queue_tst.front(), queue_tst_dst.front());
    ASSERT_EQ(queue_tst.back(), queue_tst_dst.back());
    queue_tst.del_pop();
    queue_tst_dst.del_pop();
  }
}

TEST(s21_queue_test, test_assign_constructor_4) {
  s21::queue<std::string> queue_tst = {"begin", "123-2", "wtf?", "END!"};
  s21::queue<std::string> queue_tst_src = {"begin", "123-2", "wtf?", "END!"};
  s21::queue<std::string> queue_tst_dst = std::move(queue_tst_src);
  for (size_t i = queue_tst_src.current_size(); i > 0; i--) {
    ASSERT_EQ(queue_tst.front(), queue_tst_dst.front());
    ASSERT_EQ(queue_tst.back(), queue_tst_dst.back());
    queue_tst.del_pop();
    queue_tst_dst.del_pop();
  }
}

// =======================
// Test of push and pop
// =======================

TEST(s21_queue_test, test_queue_push_1) {
  s21::queue<char> queue_tst;
  queue_tst.push('a');
  queue_tst.push('b');
  queue_tst.push('x');
  queue_tst.push('z');
  std::queue<char> queue_std;
  queue_std.push('a');
  queue_std.push('b');
  queue_std.push('x');
  queue_std.push('z');
  for (size_t i = queue_tst.current_size(); i > 0; i--) {
    ASSERT_EQ(queue_tst.front(), queue_std.front());
    ASSERT_EQ(queue_tst.back(), queue_std.back());
    queue_tst.del_pop();
    queue_std.pop();
  }
}

TEST(s21_queue_test, test_queue_push_2) {
  s21::queue<int> queue_tst;
  queue_tst.push(0);
  queue_tst.push(1);
  queue_tst.push(500);
  queue_tst.push(-500);
  std::queue<int> queue_std;
  queue_std.push(0);
  queue_std.push(1);
  queue_std.push(500);
  queue_std.push(-500);
  for (size_t i = queue_tst.current_size(); i > 0; i--) {
    ASSERT_EQ(queue_tst.front(), queue_std.front());
    ASSERT_EQ(queue_tst.back(), queue_std.back());
    queue_tst.del_pop();
    queue_std.pop();
  }
}

TEST(s21_queue_test, test_queue_push_3) {
  s21::queue<double> queue_tst;
  queue_tst.push(-123.456);
  queue_tst.push(0.0);
  queue_tst.push(-0.0);
  queue_tst.push(567.890);
  std::queue<double> queue_std;
  queue_std.push(-123.456);
  queue_std.push(0.0);
  queue_std.push(-0.0);
  queue_std.push(567.890);
  for (size_t i = queue_tst.current_size(); i > 0; i--) {
    ASSERT_EQ(queue_tst.front(), queue_std.front());
    ASSERT_EQ(queue_tst.back(), queue_std.back());
    queue_tst.del_pop();
    queue_std.pop();
  }
}

TEST(s21_queue_test, test_queue_push_4) {
  s21::queue<std::string> queue_tst;
  queue_tst.push("begin");
  queue_tst.push("123-2");
  queue_tst.push("wtf?");
  queue_tst.push("END!");
  std::queue<std::string> queue_std;
  queue_std.push("begin");
  queue_std.push("123-2");
  queue_std.push("wtf?");
  queue_std.push("END!");
  for (size_t i = queue_tst.current_size(); i > 0; i--) {
    ASSERT_EQ(queue_tst.front(), queue_std.front());
    ASSERT_EQ(queue_tst.back(), queue_std.back());
    queue_tst.del_pop();
    queue_std.pop();
  }
}

// =======================
// Test of swap
// =======================

TEST(s21_queue_test, test_queue_swap_1) {
  s21::queue<char> queue_tst_1 = {'a', 'b', 'x', 'z'};
  s21::queue<char> queue_tst_2 = {'x', 'x', 'x'};
  s21::queue<char> queue_tst_src = {'a', 'b', 'x', 'z'};
  s21::queue<char> queue_tst_dst = {'x', 'x', 'x'};
  queue_tst_src.swap(queue_tst_dst);
  for (size_t i = queue_tst_1.current_size(); i > 0; i--) {
    ASSERT_EQ(queue_tst_1.front(), queue_tst_dst.front());
    ASSERT_EQ(queue_tst_1.back(), queue_tst_dst.back());
    queue_tst_1.del_pop();
    queue_tst_dst.del_pop();
  }
  for (size_t i = queue_tst_2.current_size(); i > 0; i--) {
    ASSERT_EQ(queue_tst_2.front(), queue_tst_src.front());
    ASSERT_EQ(queue_tst_2.back(), queue_tst_src.back());
    queue_tst_2.del_pop();
    queue_tst_src.del_pop();
  }
}

TEST(s21_queue_test, test_queue_swap_2) {
  s21::queue<int> queue_tst_1 = {923405, 0, 1, 500, -500};
  s21::queue<int> queue_tst_2 = {23, -9823, 2352};
  s21::queue<int> queue_tst_src = {923405, 0, 1, 500, -500};
  s21::queue<int> queue_tst_dst = {23, -9823, 2352};
  queue_tst_src.swap(queue_tst_dst);
  for (size_t i = queue_tst_1.current_size(); i > 0; i--) {
    ASSERT_EQ(queue_tst_1.front(), queue_tst_dst.front());
    ASSERT_EQ(queue_tst_1.back(), queue_tst_dst.back());
    queue_tst_1.del_pop();
    queue_tst_dst.del_pop();
  }
  for (size_t i = queue_tst_2.current_size(); i > 0; i--) {
    ASSERT_EQ(queue_tst_2.front(), queue_tst_src.front());
    ASSERT_EQ(queue_tst_2.back(), queue_tst_src.back());
    queue_tst_2.del_pop();
    queue_tst_src.del_pop();
  }
}

TEST(s21_queue_test, test_queue_swap_3) {
  s21::queue<double> queue_tst_1 = {-123.456, 0.0, -0.0, 567.890};
  s21::queue<double> queue_tst_2 = {23.1345, -9823.021, 2352.0095};
  s21::queue<double> queue_tst_src = {-123.456, 0.0, -0.0, 567.890};
  s21::queue<double> queue_tst_dst = {23.1345, -9823.021, 2352.0095};
  queue_tst_src.swap(queue_tst_dst);
  for (size_t i = queue_tst_1.current_size(); i > 0; i--) {
    ASSERT_EQ(queue_tst_1.front(), queue_tst_dst.front());
    ASSERT_EQ(queue_tst_1.back(), queue_tst_dst.back());
    queue_tst_1.del_pop();
    queue_tst_dst.del_pop();
  }
  for (size_t i = queue_tst_2.current_size(); i > 0; i--) {
    ASSERT_EQ(queue_tst_2.front(), queue_tst_src.front());
    ASSERT_EQ(queue_tst_2.back(), queue_tst_src.back());
    queue_tst_2.del_pop();
    queue_tst_src.del_pop();
  }
}

TEST(s21_queue_test, test_queue_swap_4) {
  s21::queue<std::string> queue_tst_1 = {"ewr!", "<>_<>", "{}.!.[]"};
  s21::queue<std::string> queue_tst_2;
  s21::queue<std::string> queue_tst_src = {"ewr!", "<>_<>", "{}.!.[]"};
  s21::queue<std::string> queue_tst_dst;
  queue_tst_src.swap(queue_tst_dst);
  for (size_t i = queue_tst_1.current_size(); i > 0; i--) {
    ASSERT_EQ(queue_tst_1.front(), queue_tst_dst.front());
    ASSERT_EQ(queue_tst_1.back(), queue_tst_dst.back());
    queue_tst_1.del_pop();
    queue_tst_dst.del_pop();
  }
  ASSERT_EQ(queue_tst_2.current_size(), queue_tst_src.current_size());
}