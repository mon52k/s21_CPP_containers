#include "s21_stack.h"

#include <gtest/gtest.h>

#include <list>
#include <stack>

// =======================
// Test of default constructor
// =======================

TEST(s21_stack_test, test_default_constructor_1) {
  s21::stack<char> stack_tst;
  std::stack<char> stack_std;
  ASSERT_EQ(stack_tst.size(), stack_std.size());
  ASSERT_EQ(stack_tst.empty(), stack_std.empty());
}

TEST(s21_stack_test, test_default_constructor_2) {
  s21::stack<int> stack_tst;
  std::stack<int> stack_std;
  ASSERT_EQ(stack_tst.size(), stack_std.size());
  ASSERT_EQ(stack_tst.empty(), stack_std.empty());
}

TEST(s21_stack_test, test_default_constructor_3) {
  s21::stack<double> stack_tst;
  std::stack<double> stack_std;
  ASSERT_EQ(stack_tst.size(), stack_std.size());
  ASSERT_EQ(stack_tst.empty(), stack_std.empty());
}

TEST(s21_stack_test, test_default_constructor_4) {
  s21::stack<std::string> stack_tst;
  std::stack<std::string> stack_std;
  ASSERT_EQ(stack_tst.size(), stack_std.size());
  ASSERT_EQ(stack_tst.empty(), stack_std.empty());
}

// =======================
// Test of stack constructor
// =======================

TEST(s21_stack_test, test_stack_constructor_1) {
  s21::stack<char> stack_tst = {'a', 'b', 'x', 'z'};
  std::stack<char> stack_std;
  stack_std.push('a');
  stack_std.push('b');
  stack_std.push('x');
  stack_std.push('z');
  ASSERT_EQ(stack_tst.size(), stack_std.size());
  ASSERT_EQ(stack_tst.empty(), stack_std.empty());
}

TEST(s21_stack_test, test_stack_constructor_2) {
  s21::stack<int> stack_tst = {0, 1, 500, -500};
  std::stack<int> stack_std;
  stack_std.push(0);
  stack_std.push(1);
  stack_std.push(500);
  stack_std.push(-500);
  ASSERT_EQ(stack_tst.size(), stack_std.size());
  ASSERT_EQ(stack_tst.empty(), stack_std.empty());
}

TEST(s21_stack_test, test_stack_constructor_3) {
  s21::stack<double> stack_tst = {-123.456, 0.0, -0.0, 567.890};
  std::stack<double> stack_std;
  stack_std.push(-123.456);
  stack_std.push(0.0);
  stack_std.push(-0.0);
  stack_std.push(567.890);
  ASSERT_EQ(stack_tst.size(), stack_std.size());
  ASSERT_EQ(stack_tst.empty(), stack_std.empty());
}

TEST(s21_stack_test, test_stack_constructor_4) {
  s21::stack<std::string> stack_tst = {"begin", "123-2", "wtf?", "END!"};
  std::stack<std::string> stack_std;
  stack_std.push("begin");
  stack_std.push("123-2");
  stack_std.push("wtf?");
  stack_std.push("END!");
  ASSERT_EQ(stack_tst.size(), stack_std.size());
  ASSERT_EQ(stack_tst.empty(), stack_std.empty());
}

// =======================
// Test of copy constructor
// =======================

TEST(s21_stack_test, test_copy_constructor_1) {
  s21::stack<char> stack_tst_src = {'a', 'b', 'x', 'z'};
  s21::stack<char> stack_tst_dst(stack_tst_src);
  for (size_t i = stack_tst_src.size(); i > 0; i--) {
    ASSERT_EQ(stack_tst_src.top(), stack_tst_dst.top());
    stack_tst_src.pop();
    stack_tst_dst.pop();
  }
}

TEST(s21_stack_test, test_copy_constructor_2) {
  s21::stack<int> stack_tst_src = {0, 1, 500, -500};
  s21::stack<int> stack_tst_dst(stack_tst_src);
  for (size_t i = stack_tst_src.size(); i > 0; i--) {
    ASSERT_EQ(stack_tst_src.top(), stack_tst_dst.top());
    stack_tst_src.pop();
    stack_tst_dst.pop();
  }
}

TEST(s21_stack_test, test_copy_constructor_3) {
  s21::stack<double> stack_tst_src = {-123.456, 0.0, -0.0, 567.890};
  s21::stack<double> stack_tst_dst(stack_tst_src);
  for (size_t i = stack_tst_src.size(); i > 0; i--) {
    ASSERT_EQ(stack_tst_src.top(), stack_tst_dst.top());
    stack_tst_src.pop();
    stack_tst_dst.pop();
  }
}

TEST(s21_stack_test, test_copy_constructor_4) {
  s21::stack<std::string> stack_tst_src = {"begin", "123-2", "wtf?", "END!"};
  s21::stack<std::string> stack_tst_dst(stack_tst_src);
  for (size_t i = stack_tst_src.size(); i > 0; i--) {
    ASSERT_EQ(stack_tst_src.top(), stack_tst_dst.top());
    stack_tst_src.pop();
    stack_tst_dst.pop();
  }
}

// =======================
// Test of assignment constructor
// =======================

TEST(s21_stack_test, test_assign_constructor_1) {
  s21::stack<char> stack_tst = {'a', 'b', 'x', 'z'};
  s21::stack<char> stack_tst_src = {'a', 'b', 'x', 'z'};
  s21::stack<char> stack_tst_dst = std::move(stack_tst_src);
  for (size_t i = stack_tst_src.size(); i > 0; i--) {
    ASSERT_EQ(stack_tst.top(), stack_tst_dst.top());
    stack_tst.pop();
    stack_tst_dst.pop();
  }
}

TEST(s21_stack_test, test_assign_constructor_2) {
  s21::stack<int> stack_tst = {0, 1, 500, -500};
  s21::stack<int> stack_tst_src = {0, 1, 500, -500};
  s21::stack<int> stack_tst_dst = std::move(stack_tst_src);
  for (size_t i = stack_tst_src.size(); i > 0; i--) {
    ASSERT_EQ(stack_tst.top(), stack_tst_dst.top());
    stack_tst.pop();
    stack_tst_dst.pop();
  }
}

TEST(s21_stack_test, test_assign_constructor_3) {
  s21::stack<double> stack_tst = {-123.456, 0.0, -0.0, 567.890};
  s21::stack<double> stack_tst_src = {-123.456, 0.0, -0.0, 567.890};
  s21::stack<double> stack_tst_dst = std::move(stack_tst_src);
  for (size_t i = stack_tst_src.size(); i > 0; i--) {
    ASSERT_EQ(stack_tst.top(), stack_tst_dst.top());
    stack_tst.pop();
    stack_tst_dst.pop();
  }
}

TEST(s21_stack_test, test_assign_constructor_4) {
  s21::stack<std::string> stack_tst = {"begin", "123-2", "wtf?", "END!"};
  s21::stack<std::string> stack_tst_src = {"begin", "123-2", "wtf?", "END!"};
  s21::stack<std::string> stack_tst_dst = std::move(stack_tst_src);
  for (size_t i = stack_tst_src.size(); i > 0; i--) {
    ASSERT_EQ(stack_tst.top(), stack_tst_dst.top());
    stack_tst.pop();
    stack_tst_dst.pop();
  }
}

// =======================
// Test of push and pop
// =======================

TEST(s21_stack_test, test_stack_push_1) {
  s21::stack<char> stack_tst;
  stack_tst.push('a');
  stack_tst.push('b');
  stack_tst.push('x');
  stack_tst.push('z');
  std::stack<char> stack_std;
  stack_std.push('a');
  stack_std.push('b');
  stack_std.push('x');
  stack_std.push('z');
  for (size_t i = stack_tst.size(); i > 0; i--) {
    ASSERT_EQ(stack_tst.top(), stack_std.top());
    stack_tst.pop();
    stack_std.pop();
  }
}

TEST(s21_stack_test, test_stack_push_2) {
  s21::stack<int> stack_tst;
  stack_tst.push(0);
  stack_tst.push(1);
  stack_tst.push(500);
  stack_tst.push(-500);
  std::stack<int> stack_std;
  stack_std.push(0);
  stack_std.push(1);
  stack_std.push(500);
  stack_std.push(-500);
  for (size_t i = stack_tst.size(); i > 0; i--) {
    ASSERT_EQ(stack_tst.top(), stack_std.top());
    stack_tst.pop();
    stack_std.pop();
  }
}

TEST(s21_stack_test, test_stack_push_3) {
  s21::stack<double> stack_tst;
  stack_tst.push(-123.456);
  stack_tst.push(0.0);
  stack_tst.push(-0.0);
  stack_tst.push(567.890);
  std::stack<double> stack_std;
  stack_std.push(-123.456);
  stack_std.push(0.0);
  stack_std.push(-0.0);
  stack_std.push(567.890);
  for (size_t i = stack_tst.size(); i > 0; i--) {
    ASSERT_EQ(stack_tst.top(), stack_std.top());
    stack_tst.pop();
    stack_std.pop();
  }
}

TEST(s21_stack_test, test_stack_push_4) {
  s21::stack<std::string> stack_tst;
  stack_tst.push("begin");
  stack_tst.push("123-2");
  stack_tst.push("wtf?");
  stack_tst.push("END!");
  std::stack<std::string> stack_std;
  stack_std.push("begin");
  stack_std.push("123-2");
  stack_std.push("wtf?");
  stack_std.push("END!");
  for (size_t i = stack_tst.size(); i > 0; i--) {
    ASSERT_EQ(stack_tst.top(), stack_std.top());
    stack_tst.pop();
    stack_std.pop();
  }
}

// =======================
// Test of swap
// =======================

TEST(s21_stack_test, test_stack_swap_1) {
  s21::stack<char> stack_tst_1 = {'a', 'b', 'x', 'z'};
  s21::stack<char> stack_tst_2 = {'x', 'x', 'x'};
  s21::stack<char> stack_tst_src = {'a', 'b', 'x', 'z'};
  s21::stack<char> stack_tst_dst = {'x', 'x', 'x'};
  stack_tst_src.swap(stack_tst_dst);
  for (size_t i = stack_tst_1.size(); i > 0; i--) {
    ASSERT_EQ(stack_tst_1.top(), stack_tst_dst.top());
    stack_tst_1.pop();
    stack_tst_dst.pop();
  }
  for (size_t i = stack_tst_2.size(); i > 0; i--) {
    ASSERT_EQ(stack_tst_2.top(), stack_tst_src.top());
    stack_tst_2.pop();
    stack_tst_src.pop();
  }
}

TEST(s21_stack_test, test_stack_swap_2) {
  s21::stack<int> stack_tst_1 = {923405, 0, 1, 500, -500};
  s21::stack<int> stack_tst_2 = {23, -9823, 2352};
  s21::stack<int> stack_tst_src = {923405, 0, 1, 500, -500};
  s21::stack<int> stack_tst_dst = {23, -9823, 2352};
  stack_tst_src.swap(stack_tst_dst);
  for (size_t i = stack_tst_1.size(); i > 0; i--) {
    ASSERT_EQ(stack_tst_1.top(), stack_tst_dst.top());
    stack_tst_1.pop();
    stack_tst_dst.pop();
  }
  for (size_t i = stack_tst_2.size(); i > 0; i--) {
    ASSERT_EQ(stack_tst_2.top(), stack_tst_src.top());
    stack_tst_2.pop();
    stack_tst_src.pop();
  }
}

TEST(s21_stack_test, test_stack_swap_3) {
  s21::stack<double> stack_tst_1 = {-123.456, 0.0, -0.0, 567.890};
  s21::stack<double> stack_tst_2 = {23.1345, -9823.021, 2352.0095};
  s21::stack<double> stack_tst_src = {-123.456, 0.0, -0.0, 567.890};
  s21::stack<double> stack_tst_dst = {23.1345, -9823.021, 2352.0095};
  stack_tst_src.swap(stack_tst_dst);
  for (size_t i = stack_tst_1.size(); i > 0; i--) {
    ASSERT_EQ(stack_tst_1.top(), stack_tst_dst.top());
    stack_tst_1.pop();
    stack_tst_dst.pop();
  }
  for (size_t i = stack_tst_2.size(); i > 0; i--) {
    ASSERT_EQ(stack_tst_2.top(), stack_tst_src.top());
    stack_tst_2.pop();
    stack_tst_src.pop();
  }
}

TEST(s21_stack_test, test_stack_swap_4) {
  s21::stack<std::string> stack_tst_1 = {"ewr!", "<>_<>", "{}.!.[]"};
  s21::stack<std::string> stack_tst_2;
  s21::stack<std::string> stack_tst_src = {"ewr!", "<>_<>", "{}.!.[]"};
  s21::stack<std::string> stack_tst_dst;
  stack_tst_src.swap(stack_tst_dst);
  for (size_t i = stack_tst_1.size(); i > 0; i--) {
    ASSERT_EQ(stack_tst_1.top(), stack_tst_dst.top());
    stack_tst_1.pop();
    stack_tst_dst.pop();
  }
  ASSERT_EQ(stack_tst_2.size(), stack_tst_src.size());
}