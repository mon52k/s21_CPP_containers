#include "s21_list.h"

#include <gtest/gtest.h>

#include <list>

// =======================
// Test of default constructor
// =======================

TEST(s21_list_test, test_default_constructor_1) {
  s21::list<char> list_tst;
  std::list<char> list_std;
  ASSERT_EQ(list_tst.size(), list_std.size());
  ASSERT_EQ(list_tst.max_size(), list_std.max_size());
  ASSERT_EQ(list_tst.empty(), list_std.empty());
}

TEST(s21_list_test, test_default_constructor_2) {
  s21::list<int> list_tst;
  std::list<int> list_std;
  ASSERT_EQ(list_tst.size(), list_std.size());
  ASSERT_EQ(list_tst.max_size(), list_std.max_size());
  ASSERT_EQ(list_tst.empty(), list_std.empty());
}

TEST(s21_list_test, test_default_constructor_3) {
  s21::list<double> list_tst;
  std::list<double> list_std;
  ASSERT_EQ(list_tst.size(), list_std.size());
  ASSERT_EQ(list_tst.max_size(), list_std.max_size());
  ASSERT_EQ(list_tst.empty(), list_std.empty());
}

TEST(s21_list_test, test_default_constructor_4) {
  s21::list<std::string> list_tst;
  std::list<std::string> list_std;
  ASSERT_EQ(list_tst.size(), list_std.size());
  ASSERT_EQ(list_tst.max_size(), list_std.max_size());
  ASSERT_EQ(list_tst.empty(), list_std.empty());
}

// =======================
// Test of size constructor
// =======================

TEST(s21_list_test, test_size_constructor_1) {
  s21::list<char> list_tst(5);
  std::list<char> list_std(5);
  ASSERT_EQ(list_tst.size(), list_std.size());
  ASSERT_EQ(list_tst.max_size(), list_std.max_size());
  ASSERT_EQ(list_tst.empty(), list_std.empty());
}

TEST(s21_list_test, test_size_constructor_2) {
  s21::list<int> list_tst(5);
  std::list<int> list_std(5);
  ASSERT_EQ(list_tst.size(), list_std.size());
  ASSERT_EQ(list_tst.max_size(), list_std.max_size());
  ASSERT_EQ(list_tst.empty(), list_std.empty());
}

TEST(s21_list_test, test_size_constructor_3) {
  s21::list<double> list_tst(5);
  std::list<double> list_std(5);
  ASSERT_EQ(list_tst.size(), list_std.size());
  ASSERT_EQ(list_tst.max_size(), list_std.max_size());
  ASSERT_EQ(list_tst.empty(), list_std.empty());
}

TEST(s21_list_test, test_size_constructor_4) {
  s21::list<std::string> list_tst(5);
  std::list<std::string> list_std(5);
  ASSERT_EQ(list_tst.size(), list_std.size());
  ASSERT_EQ(list_tst.max_size(), list_std.max_size());
  ASSERT_EQ(list_tst.empty(), list_std.empty());
}

// =======================
// Test of list constructor
// =======================

TEST(s21_list_test, test_list_constructor_1) {
  s21::list<char> list_tst = {'a', 'b', 'x', 'z'};
  std::list<char> list_std = {'a', 'b', 'x', 'z'};
  ASSERT_EQ(list_tst.size(), list_std.size());
  ASSERT_EQ(list_tst.max_size(), list_std.max_size());
  ASSERT_EQ(list_tst.empty(), list_std.empty());
}

TEST(s21_list_test, test_list_constructor_2) {
  s21::list<int> list_tst = {0, 1, 500, -500};
  std::list<int> list_std = {0, 1, 500, -500};
  ASSERT_EQ(list_tst.size(), list_std.size());
  ASSERT_EQ(list_tst.max_size(), list_std.max_size());
  ASSERT_EQ(list_tst.empty(), list_std.empty());
}

TEST(s21_list_test, test_list_constructor_3) {
  s21::list<double> list_tst = {-123.456, 0.0, -0.0, 567.890};
  std::list<double> list_std = {-123.456, 0.0, -0.0, 567.890};
  ASSERT_EQ(list_tst.size(), list_std.size());
  ASSERT_EQ(list_tst.max_size(), list_std.max_size());
  ASSERT_EQ(list_tst.empty(), list_std.empty());
}

TEST(s21_list_test, test_list_constructor_4) {
  s21::list<std::string> list_tst = {"begin", "123-2", "wtf?", "END!"};
  std::list<std::string> list_std = {"begin", "123-2", "wtf?", "END!"};
  ASSERT_EQ(list_tst.size(), list_std.size());
  ASSERT_EQ(list_tst.max_size(), list_std.max_size());
  ASSERT_EQ(list_tst.empty(), list_std.empty());
}

// =======================
// Test of copy constructor
// =======================

TEST(s21_list_test, test_copy_constructor_1) {
  s21::list<char> list_tst_src = {'a', 'b', 'x', 'z'};
  s21::list<char> list_tst_dst(list_tst_src);
  s21::list<char>::iter it_src = list_tst_src.begin();
  s21::list<char>::iter it_dst = list_tst_dst.begin();
  for (; it_src != list_tst_src.end(); it_src++, it_dst++)
    ASSERT_EQ(*it_src, *it_dst);
}

TEST(s21_list_test, test_copy_constructor_2) {
  s21::list<int> list_tst_src = {0, 1, 500, -500};
  s21::list<int> list_tst_dst(list_tst_src);
  s21::list<int>::iter it_src = list_tst_src.begin();
  s21::list<int>::iter it_dst = list_tst_dst.begin();
  for (; it_src != list_tst_src.end(); it_src++, it_dst++)
    ASSERT_EQ(*it_src, *it_dst);
}

TEST(s21_list_test, test_copy_constructor_3) {
  s21::list<double> list_tst_src = {-123.456, 0.0, -0.0, 567.890};
  s21::list<double> list_tst_dst(list_tst_src);
  s21::list<double>::iter it_src = list_tst_src.begin();
  s21::list<double>::iter it_dst = list_tst_dst.begin();
  for (; it_src != list_tst_src.end(); it_src++, it_dst++)
    ASSERT_EQ(*it_src, *it_dst);
}

TEST(s21_list_test, test_copy_constructor_4) {
  s21::list<std::string> list_tst_src = {"begin", "123-2", "wtf?", "END!"};
  s21::list<std::string> list_tst_dst(list_tst_src);
  s21::list<std::string>::iter it_src = list_tst_src.begin();
  s21::list<std::string>::iter it_dst = list_tst_dst.begin();
  for (; it_src != list_tst_src.end(); it_src++, it_dst++)
    ASSERT_EQ(*it_src, *it_dst);
}

// =======================
// Test of assignment constructor
// =======================

TEST(s21_list_test, test_assign_constructor_1) {
  s21::list<char> list_tst = {'a', 'b', 'x', 'z'};
  s21::list<char> list_tst_src = {'a', 'b', 'x', 'z'};
  s21::list<char> list_tst_dst = std::move(list_tst_src);
  s21::list<char>::iter it = list_tst.begin();
  s21::list<char>::iter it_dst = list_tst_dst.begin();
  for (; it != list_tst.end(); it++, it_dst++) ASSERT_EQ(*it, *it_dst);
}

TEST(s21_list_test, test_assign_constructor_2) {
  s21::list<int> list_tst = {0, 1, 500, -500};
  s21::list<int> list_tst_src = {0, 1, 500, -500};
  s21::list<int> list_tst_dst = std::move(list_tst_src);
  s21::list<int>::iter it = list_tst.begin();
  s21::list<int>::iter it_dst = list_tst_dst.begin();
  for (; it != list_tst.end(); it++, it_dst++) ASSERT_EQ(*it, *it_dst);
}

TEST(s21_list_test, test_assign_constructor_3) {
  s21::list<double> list_tst = {-123.456, 0.0, -0.0, 567.890};
  s21::list<double> list_tst_src = {-123.456, 0.0, -0.0, 567.890};
  s21::list<double> list_tst_dst = std::move(list_tst_src);
  s21::list<double>::iter it = list_tst.begin();
  s21::list<double>::iter it_dst = list_tst_dst.begin();
  for (; it != list_tst.end(); it++, it_dst++) ASSERT_EQ(*it, *it_dst);
}

TEST(s21_list_test, test_assign_constructor_4) {
  s21::list<std::string> list_tst = {"begin", "123-2", "wtf?", "END!"};
  s21::list<std::string> list_tst_src = {"begin", "123-2", "wtf?", "END!"};
  s21::list<std::string> list_tst_dst = std::move(list_tst_src);
  s21::list<std::string>::iter it = list_tst.begin();
  s21::list<std::string>::iter it_dst = list_tst_dst.begin();
  for (; it != list_tst.end(); it++, it_dst++) ASSERT_EQ(*it, *it_dst);
}

// =======================
// Test of limits
// =======================

TEST(s21_list_test, test_limits_1) {
  s21::list<char> list_tst = {'a', 'b', 'x', 'z'};
  std::list<char> list_std = {'a', 'b', 'x', 'z'};
  ASSERT_EQ(list_tst.front(), list_std.front());
  ASSERT_EQ(list_tst.back(), list_std.back());
  s21::list<char>::iter it_tst = list_tst.begin();
  std::list<char>::iterator it_std = list_std.begin();
  for (; it_tst != list_tst.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_list_test, test_limits_2) {
  s21::list<int> list_tst = {32768, 0, 1, 438, -500};
  std::list<int> list_std = {32768, 0, 1, 438, -500};
  ASSERT_EQ(list_tst.front(), list_std.front());
  ASSERT_EQ(list_tst.back(), list_std.back());
  s21::list<int>::iter it_tst = list_tst.begin();
  std::list<int>::iterator it_std = list_std.begin();
  for (; it_tst != list_tst.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_list_test, test_limits_3) {
  s21::list<double> list_tst = {-123.456, 0.0, -0.0, 567.890};
  std::list<double> list_std = {-123.456, 0.0, -0.0, 567.890};
  ASSERT_EQ(list_tst.front(), list_std.front());
  ASSERT_EQ(list_tst.back(), list_std.back());
  s21::list<double>::iter it_tst = list_tst.begin();
  std::list<double>::iterator it_std = list_std.begin();
  for (; it_tst != list_tst.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_list_test, test_limits_4) {
  s21::list<std::string> list_tst = {"begin", "123-2", "wtf?", "END!"};
  std::list<std::string> list_std = {"begin", "123-2", "wtf?", "END!"};
  ASSERT_EQ(list_tst.front(), list_std.front());
  ASSERT_EQ(list_tst.back(), list_std.back());
  s21::list<std::string>::iter it_tst = list_tst.begin();
  std::list<std::string>::iterator it_std = list_std.begin();
  for (; it_tst != list_tst.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

// =======================
// Test of insert
// =======================

TEST(s21_list_test, test_insert_1) {
  s21::list<char> list_tst = {'x', 'z'};
  std::list<char> list_std = {'x', 'z'};
  s21::list<char>::iter it_tst_in = list_tst.begin();
  std::list<char>::iterator it_std_in = list_std.begin();
  s21::list<char>::iter it_tst_out = list_tst.insert(it_tst_in, 'y');
  std::list<char>::iterator it_std_out = list_std.insert(it_std_in, 'y');
  ASSERT_EQ(*it_tst_out, *it_std_out);

  s21::list<char>::iter it_tst = list_tst.begin();
  std::list<char>::iterator it_std = list_std.begin();
  for (; it_tst != list_tst.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_list_test, test_insert_2) {
  s21::list<int> list_tst = {23, 34, 675};
  std::list<int> list_std = {23, 34, 675};
  s21::list<int>::iter it_tst_in = list_tst.end();
  std::list<int>::iterator it_std_in = list_std.end();
  s21::list<int>::iter it_tst_out = list_tst.insert(it_tst_in, 55);
  std::list<int>::iterator it_std_out = list_std.insert(it_std_in, 55);
  ASSERT_EQ(*it_tst_out, *it_std_out);

  s21::list<int>::iter it_tst = list_tst.begin();
  std::list<int>::iterator it_std = list_std.begin();
  for (; it_tst != list_tst.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_list_test, test_insert_3) {
  s21::list<double> list_tst = {-123.456, 0.0, -0.0, 567.890, 12.23543, 96.75};
  std::list<double> list_std = {-123.456, 0.0, -0.0, 567.890, 12.23543, 96.75};
  s21::list<double>::iter it_tst_in = list_tst.begin();
  std::list<double>::iterator it_std_in = list_std.begin();
  for (int i = 0; i < 4; i++) it_tst_in++;
  for (int i = 0; i < 4; i++) it_std_in++;
  s21::list<double>::iter it_tst_out = list_tst.insert(it_tst_in, 8.97);
  std::list<double>::iterator it_std_out = list_std.insert(it_std_in, 8.97);
  ASSERT_EQ(*it_tst_out, *it_std_out);

  s21::list<double>::iter it_tst = list_tst.begin();
  std::list<double>::iterator it_std = list_std.begin();
  for (; it_tst != list_tst.end(); it_tst++, it_std++) {
    ASSERT_EQ(*it_tst, *it_std);
  }
}

TEST(s21_list_test, test_insert_4) {
  s21::list<std::string> list_tst;
  std::list<std::string> list_std;
  s21::list<std::string>::iter it_tst_temp = list_tst.begin();
  std::list<std::string>::iterator it_std_temp = list_std.begin();
  list_tst.insert(it_tst_temp, "test");
  list_std.insert(it_std_temp, "test");
  s21::list<std::string>::iter it_tst = list_tst.begin();
  std::list<std::string>::iterator it_std = list_std.begin();
  for (; it_tst != list_tst.end(); it_tst++, it_std++) {
    ASSERT_EQ(*it_tst, *it_std);
  }
}

// =======================
// Test of erase
// =======================

TEST(s21_list_test, test_erase_1) {
  s21::list<char> list_tst = {'x', 'z'};
  std::list<char> list_std = {'x', 'z'};
  s21::list<char>::iter it_tst_temp = list_tst.begin();
  std::list<char>::iterator it_std_temp = list_std.begin();
  list_tst.erase(it_tst_temp);
  list_std.erase(it_std_temp);

  s21::list<char>::iter it_tst = list_tst.begin();
  std::list<char>::iterator it_std = list_std.begin();
  for (; it_tst != list_tst.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_list_test, test_erase_2) {
  s21::list<int> list_tst = {23, 34, 675};
  std::list<int> list_std = {23, 34, 675};
  s21::list<int>::iter it_tst_temp = list_tst.end();
  std::list<int>::iterator it_std_temp = list_std.end();
  it_tst_temp--;
  it_std_temp--;
  list_tst.erase(it_tst_temp);
  list_std.erase(it_std_temp);

  s21::list<int>::iter it_tst = list_tst.begin();
  std::list<int>::iterator it_std = list_std.begin();
  for (; it_tst != list_tst.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_list_test, test_erase_3) {
  s21::list<double> list_tst = {-123.456, 0.0, -0.0, 567.890, 12.23543, 96.75};
  std::list<double> list_std = {-123.456, 0.0, -0.0, 567.890, 12.23543, 96.75};
  s21::list<double>::iter it_tst_in = list_tst.begin();
  std::list<double>::iterator it_std_in = list_std.begin();
  for (int i = 0; i < 4; i++) it_tst_in++;
  for (int i = 0; i < 4; i++) it_std_in++;
  list_tst.erase(it_tst_in);
  list_std.erase(it_std_in);

  s21::list<double>::iter it_tst = list_tst.begin();
  std::list<double>::iterator it_std = list_std.begin();
  for (; it_tst != list_tst.end(); it_tst++, it_std++) {
    ASSERT_EQ(*it_tst, *it_std);
  }
}

TEST(s21_list_test, test_erase_4) {
  s21::list<std::string> list_tst = {"WTF?!"};
  std::list<std::string> list_std = {"WTF?!"};
  s21::list<std::string>::iter it_tst_temp = list_tst.begin();
  std::list<std::string>::iterator it_std_temp = list_std.begin();
  list_tst.erase(it_tst_temp);
  list_std.erase(it_std_temp);

  ASSERT_EQ(list_tst.empty(), list_std.empty());
}

// =======================
// Test of merge
// =======================

TEST(s21_list_test, test_merge_1) {
  s21::list<char> list_tst_1 = {'x', 'z'};
  s21::list<char> list_tst_2;
  std::list<char> list_std_1 = {'x', 'z'};
  std::list<char> list_std_2;
  list_tst_1.merge(list_tst_2);
  list_std_1.merge(list_std_2);

  s21::list<char>::iter it_tst = list_tst_1.begin();
  std::list<char>::iterator it_std = list_std_1.begin();
  for (; it_tst != list_tst_1.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_list_test, test_merge_2) {
  s21::list<int> list_tst_1;
  s21::list<int> list_tst_2 = {23, 34, 675};
  std::list<int> list_std_1;
  std::list<int> list_std_2 = {23, 34, 675};
  list_tst_1.merge(list_tst_2);
  list_std_1.merge(list_std_2);

  s21::list<int>::iter it_tst = list_tst_1.begin();
  std::list<int>::iterator it_std = list_std_1.begin();
  for (; it_tst != list_tst_1.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_list_test, test_merge_3) {
  s21::list<double> list_tst_1 = {-123.456, 0.0, -0.0, 567.890};
  s21::list<double> list_tst_2 = {12.23543, 96.75};
  std::list<double> list_std_1 = {-123.456, 0.0, -0.0, 567.890};
  std::list<double> list_std_2 = {12.23543, 96.75};
  list_tst_1.merge(list_tst_2);
  list_std_1.merge(list_std_2);

  s21::list<double>::iter it_tst = list_tst_1.begin();
  std::list<double>::iterator it_std = list_std_1.begin();
  for (; it_tst != list_tst_1.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_list_test, test_merge_4) {
  s21::list<std::string> list_tst_1 = {"begin", "123-2", "wtf?", "END!"};
  std::list<std::string> list_std_1 = {"begin", "123-2", "wtf?", "END!"};
  list_tst_1.merge(list_tst_1);
  list_std_1.merge(list_std_1);

  s21::list<std::string>::iter it_tst = list_tst_1.begin();
  std::list<std::string>::iterator it_std = list_std_1.begin();
  for (; it_tst != list_tst_1.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

// =======================
// Test of splice
// =======================

TEST(s21_list_test, test_splice_1) {
  s21::list<char> list_tst_1 = {'x', 'z'};
  s21::list<char> list_tst_2;
  std::list<char> list_std_1 = {'x', 'z'};
  std::list<char> list_std_2;
  s21::list<char>::iter it_tst_temp = list_tst_1.begin();
  std::list<char>::iterator it_std_temp = list_std_1.begin();
  ++it_tst_temp;
  ++it_std_temp;
  list_tst_1.splice(it_tst_temp, list_tst_2);
  list_std_1.splice(it_std_temp, list_std_2);

  s21::list<char>::iter it_tst = list_tst_1.begin();
  std::list<char>::iterator it_std = list_std_1.begin();
  for (; it_tst != list_tst_1.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_list_test, test_splice_2) {
  s21::list<int> list_tst_1;
  s21::list<int> list_tst_2 = {23, 34, 675};
  std::list<int> list_std_1;
  std::list<int> list_std_2 = {23, 34, 675};
  s21::list<int>::iter it_tst_temp = list_tst_1.begin();
  std::list<int>::iterator it_std_temp = list_std_1.begin();
  list_tst_1.splice(it_tst_temp, list_tst_2);
  list_std_1.splice(it_std_temp, list_std_2);

  s21::list<int>::iter it_tst = list_tst_1.begin();
  std::list<int>::iterator it_std = list_std_1.begin();
  for (; it_tst != list_tst_1.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_list_test, test_splice_3) {
  s21::list<int> list_tst_1 = {983, 44, 18, 92, 54, 11, 15};
  s21::list<int> list_tst_2 = {35, 20, 169};
  std::list<int> list_std_1 = {983, 44, 18, 92, 54, 11, 15};
  std::list<int> list_std_2 = {35, 20, 169};
  s21::list<int>::iter it_tst_temp = list_tst_1.begin();
  std::list<int>::iterator it_std_temp = list_std_1.begin();
  for (int i = 0; i < 3; i++) it_tst_temp++;
  for (int i = 0; i < 3; i++) it_std_temp++;
  list_tst_1.splice(it_tst_temp, list_tst_2);
  list_std_1.splice(it_std_temp, list_std_2);

  s21::list<int>::iter it_tst = list_tst_1.begin();
  std::list<int>::iterator it_std = list_std_1.begin();
  for (; it_tst != list_tst_1.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_list_test, test_splice_4) {
  s21::list<double> list_tst_1 = {-123.456, 0.0, -0.0, 567.890};
  s21::list<double> list_tst_2 = {12.23543, 96.75};
  std::list<double> list_std_1 = {-123.456, 0.0, -0.0, 567.890};
  std::list<double> list_std_2 = {12.23543, 96.75};
  s21::list<double>::iter it_tst_temp = list_tst_1.begin();
  std::list<double>::iterator it_std_temp = list_std_1.begin();
  for (int i = 0; i < 3; i++) it_tst_temp++;
  for (int i = 0; i < 3; i++) it_std_temp++;
  list_tst_1.splice(it_tst_temp, list_tst_2);
  list_std_1.splice(it_std_temp, list_std_2);

  s21::list<double>::iter it_tst = list_tst_1.begin();
  std::list<double>::iterator it_std = list_std_1.begin();
  for (; it_tst != list_tst_1.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_list_test, test_splice_5) {
  s21::list<std::string> list_tst_1 = {"begin", "123-2", "wtf?", "END!"};
  s21::list<std::string> list_tst_2 = {"xxx", "YYY", "zzz"};
  std::list<std::string> list_std_1 = {"begin", "123-2", "wtf?", "END!"};
  std::list<std::string> list_std_2 = {"xxx", "YYY", "zzz"};
  s21::list<std::string>::iter it_tst_temp = list_tst_1.end();
  std::list<std::string>::iterator it_std_temp = list_std_1.end();
  list_tst_1.splice(it_tst_temp, list_tst_2);
  list_std_1.splice(it_std_temp, list_std_2);

  s21::list<std::string>::iter it_tst = list_tst_1.begin();
  std::list<std::string>::iterator it_std = list_std_1.begin();
  for (; it_tst != list_tst_1.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

// =======================
// Test of reverse
// =======================

TEST(s21_list_test, test_reverse_1) {
  s21::list<char> list_tst = {'a', 'b', 'x', 'z'};
  std::list<char> list_std = {'a', 'b', 'x', 'z'};
  list_tst.reverse();
  list_std.reverse();

  s21::list<char>::iter it_tst = list_tst.begin();
  std::list<char>::iterator it_std = list_std.begin();
  for (; it_std != list_std.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_list_test, test_reverse_2) {
  s21::list<int> list_tst = {12};
  std::list<int> list_std = {12};
  list_tst.reverse();
  list_std.reverse();

  s21::list<int>::iter it_tst = list_tst.begin();
  std::list<int>::iterator it_std = list_std.begin();
  for (; it_std != list_std.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_list_test, test_reverse_3) {
  s21::list<double> list_tst = {-123.456, 0.0, -0.0, 567.890, 12.23543, 96.75};
  std::list<double> list_std = {-123.456, 0.0, -0.0, 567.890, 12.23543, 96.75};
  list_tst.reverse();
  list_std.reverse();

  s21::list<double>::iter it_tst = list_tst.begin();
  std::list<double>::iterator it_std = list_std.begin();
  for (; it_std != list_std.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_list_test, test_reverse_4) {
  s21::list<std::string> list_tst = {"begin", "123-2", "wtf?", "END!"};
  std::list<std::string> list_std = {"begin", "123-2", "wtf?", "END!"};
  list_tst.reverse();
  list_std.reverse();

  s21::list<std::string>::iter it_tst = list_tst.begin();
  std::list<std::string>::iterator it_std = list_std.begin();
  for (; it_std != list_std.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_list_test, test_reverse_5) {
  s21::list<int> list_tst;
  std::list<int> list_std;
  list_tst.reverse();
  list_std.reverse();
}

// =======================
// Test of unique
// =======================

TEST(s21_list_test, test_unique_1) {
  s21::list<char> list_tst = {'a', 'b', 'a', 'a', 'a', 'x', 'z', 'z'};
  std::list<char> list_std = {'a', 'b', 'a', 'a', 'a', 'x', 'z', 'z'};
  list_tst.unique();
  list_std.unique();

  s21::list<char>::iter it_tst = list_tst.begin();
  std::list<char>::iterator it_std = list_std.begin();
  for (; it_std != list_std.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_list_test, test_unique_2) {
  s21::list<int> list_tst = {1, 11, 23, 11, 23, 0, 0, 2, 2, 1, 1, 1, 1};
  std::list<int> list_std = {1, 11, 23, 11, 23, 0, 0, 2, 2, 1, 1, 1, 1};
  list_tst.unique();
  list_std.unique();

  s21::list<int>::iter it_tst = list_tst.begin();
  std::list<int>::iterator it_std = list_std.begin();
  for (; it_std != list_std.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_list_test, test_unique_3) {
  s21::list<double> list_tst = {-123.456, 0.0, -0.0, 567.890, 12.23543, 96.75};
  std::list<double> list_std = {-123.456, 0.0, -0.0, 567.890, 12.23543, 96.75};
  list_tst.unique();
  list_std.unique();

  s21::list<double>::iter it_tst = list_tst.begin();
  std::list<double>::iterator it_std = list_std.begin();
  for (; it_std != list_std.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_list_test, test_unique_4) {
  s21::list<std::string> list_tst = {"WTF?!"};
  std::list<std::string> list_std = {"WTF?!"};
  list_tst.unique();
  list_std.unique();

  s21::list<std::string>::iter it_tst = list_tst.begin();
  std::list<std::string>::iterator it_std = list_std.begin();
  for (; it_std != list_std.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_list_test, test_unique_5) {
  s21::list<int> list_tst;
  std::list<int> list_std;
  list_tst.unique();
  list_std.unique();
}

// =======================
// Test of sort
// =======================

TEST(s21_list_test, test_sort_1) {
  s21::list<int> list_tst = {983, 44, 18, 92, 54, 11, 15, 0, 11, 2789};
  std::list<int> list_std = {983, 44, 18, 92, 54, 11, 15, 0, 11, 2789};
  list_tst.sort();
  list_std.sort();

  s21::list<int>::iter it_tst = list_tst.begin();
  std::list<int>::iterator it_std = list_std.begin();
  for (; it_std != list_std.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_list_test, test_sort_2) {
  s21::list<char> list_tst = {'a', 'b', 'a', 'a', 'a', 'x', 'z', 'z'};
  std::list<char> list_std = {'a', 'b', 'a', 'a', 'a', 'x', 'z', 'z'};
  list_tst.sort();
  list_std.sort();

  s21::list<char>::iter it_tst = list_tst.begin();
  std::list<char>::iterator it_std = list_std.begin();
  for (; it_std != list_std.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_list_test, test_sort_3) {
  s21::list<double> list_tst = {-123.456};
  std::list<double> list_std = {-123.456};
  list_tst.sort();
  list_std.sort();

  s21::list<double>::iter it_tst = list_tst.begin();
  std::list<double>::iterator it_std = list_std.begin();
  for (; it_std != list_std.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_list_test, test_sort_4) {
  s21::list<std::string> list_tst = {"begin", "123-2", "wtf?", "END!"};
  std::list<std::string> list_std = {"begin", "123-2", "wtf?", "END!"};
  list_tst.sort();
  list_std.sort();

  s21::list<std::string>::iter it_tst = list_tst.begin();
  std::list<std::string>::iterator it_std = list_std.begin();
  for (; it_std != list_std.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_list_test, test_sort_5) {
  s21::list<int> list_tst;
  std::list<int> list_std;
  list_tst.sort();
  list_std.sort();
}
