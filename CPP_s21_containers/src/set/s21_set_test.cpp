#include "s21_set.h"

#include <gtest/gtest.h>

#include <set>

// =======================
// Test of default constructor
// =======================

TEST(s21_set_test, test_default_constructor_1) {
  s21::set<char> set_tst;
  std::set<char> set_std;
  ASSERT_EQ(set_tst.size(), set_std.size());
  ASSERT_EQ(set_tst.empty(), set_std.empty());
}

TEST(s21_set_test, test_default_constructor_2) {
  s21::set<int> set_tst;
  std::set<int> set_std;
  ASSERT_EQ(set_tst.size(), set_std.size());
  ASSERT_EQ(set_tst.empty(), set_std.empty());
}

TEST(s21_set_test, test_default_constructor_3) {
  s21::set<double> set_tst;
  std::set<double> set_std;
  ASSERT_EQ(set_tst.size(), set_std.size());
  ASSERT_EQ(set_tst.empty(), set_std.empty());
}

TEST(s21_set_test, test_default_constructor_4) {
  s21::set<std::string> set_tst;
  std::set<std::string> set_std;
  ASSERT_EQ(set_tst.size(), set_std.size());
  ASSERT_EQ(set_tst.empty(), set_std.empty());
}

// =======================
// Test of set constructor
// =======================

TEST(s21_set_test, test_set_constructor_1) {
  s21::set<char> set_tst = {'a', 'b', 'x', 'z'};
  std::set<char> set_std = {'a', 'b', 'x', 'z'};
  ASSERT_EQ(set_tst.size(), set_std.size());
  ASSERT_EQ(set_tst.empty(), set_std.empty());
}

TEST(s21_set_test, test_set_constructor_2) {
  s21::set<int> set_tst = {0, 1, 500, -500};
  std::set<int> set_std = {0, 1, 500, -500};
  ASSERT_EQ(set_tst.size(), set_std.size());
  ASSERT_EQ(set_tst.empty(), set_std.empty());
}

TEST(s21_set_test, test_set_constructor_3) {
  s21::set<double> set_tst = {-123.456, 0.0, -0.0, 567.890};
  std::set<double> set_std = {-123.456, 0.0, -0.0, 567.890};
  ASSERT_EQ(set_tst.size(), set_std.size());
  ASSERT_EQ(set_tst.empty(), set_std.empty());
}

TEST(s21_set_test, test_set_constructor_4) {
  s21::set<std::string> set_tst = {"begin", "123-2", "wtf?", "END!"};
  std::set<std::string> set_std = {"begin", "123-2", "wtf?", "END!"};
  ASSERT_EQ(set_tst.size(), set_std.size());
  ASSERT_EQ(set_tst.empty(), set_std.empty());
}

// =======================
// Test of copy constructor
// =======================

TEST(s21_set_test, test_copy_constructor_1) {
  s21::set<char> set_tst_src = {'a', 'b', 'x', 'z'};
  s21::set<char> set_tst_dst(set_tst_src);
  s21::set<char>::iterator it_src = set_tst_src.begin();
  s21::set<char>::iterator it_dst = set_tst_dst.begin();
  for (; it_src != set_tst_src.end(); it_src++, it_dst++)
    ASSERT_EQ(*it_src, *it_dst);
}

TEST(s21_set_test, test_copy_constructor_2) {
  s21::set<int> set_tst_src = {0, 1, 500, -500};
  s21::set<int> set_tst_dst(set_tst_src);
  s21::set<int>::iterator it_src = set_tst_src.begin();
  s21::set<int>::iterator it_dst = set_tst_dst.begin();
  for (; it_src != set_tst_src.end(); it_src++, it_dst++)
    ASSERT_EQ(*it_src, *it_dst);
}

TEST(s21_set_test, test_copy_constructor_3) {
  s21::set<double> set_tst_src = {-123.456, 0.0, -0.0, 567.890};
  s21::set<double> set_tst_dst(set_tst_src);
  s21::set<double>::iterator it_src = set_tst_src.begin();
  s21::set<double>::iterator it_dst = set_tst_dst.begin();
  for (; it_src != set_tst_src.end(); it_src++, it_dst++)
    ASSERT_EQ(*it_src, *it_dst);
}

TEST(s21_set_test, test_copy_constructor_4) {
  s21::set<std::string> set_tst_src = {"begin", "123-2", "wtf?", "END!"};
  s21::set<std::string> set_tst_dst(set_tst_src);
  s21::set<std::string>::iterator it_src = set_tst_src.begin();
  s21::set<std::string>::iterator it_dst = set_tst_dst.begin();
  for (; it_src != set_tst_src.end(); it_src++, it_dst++)
    ASSERT_EQ(*it_src, *it_dst);
}

// =======================
// Test of assignment constructor
// =======================

TEST(s21_set_test, test_assign_constructor_1) {
  s21::set<char> set_tst = {'a', 'b', 'x', 'z'};
  s21::set<char> set_tst_src = {'a', 'b', 'x', 'z'};
  s21::set<char> set_tst_dst = std::move(set_tst_src);
  s21::set<char>::iterator it = set_tst.begin();
  s21::set<char>::iterator it_dst = set_tst_dst.begin();
  for (; it != set_tst.end(); it++, it_dst++) ASSERT_EQ(*it, *it_dst);
}

TEST(s21_set_test, test_assign_constructor_2) {
  s21::set<int> set_tst = {0, 1, 500, -500};
  s21::set<int> set_tst_src = {0, 1, 500, -500};
  s21::set<int> set_tst_dst = std::move(set_tst_src);
  s21::set<int>::iterator it = set_tst.begin();
  s21::set<int>::iterator it_dst = set_tst_dst.begin();
  for (; it != set_tst.end(); it++, it_dst++) ASSERT_EQ(*it, *it_dst);
}

TEST(s21_set_test, test_assign_constructor_3) {
  s21::set<double> set_tst = {-123.456, 0.0, -0.0, 567.890};
  s21::set<double> set_tst_src = {-123.456, 0.0, -0.0, 567.890};
  s21::set<double> set_tst_dst = std::move(set_tst_src);
  s21::set<double>::iterator it = set_tst.begin();
  s21::set<double>::iterator it_dst = set_tst_dst.begin();
  for (; it != set_tst.end(); it++, it_dst++) ASSERT_EQ(*it, *it_dst);
}

TEST(s21_set_test, test_assign_constructor_4) {
  s21::set<std::string> set_tst = {"begin", "123-2", "wtf?", "END!"};
  s21::set<std::string> set_tst_src = {"begin", "123-2", "wtf?", "END!"};
  s21::set<std::string> set_tst_dst = std::move(set_tst_src);
  s21::set<std::string>::iterator it = set_tst.begin();
  s21::set<std::string>::iterator it_dst = set_tst_dst.begin();
  for (; it != set_tst.end(); it++, it_dst++) ASSERT_EQ(*it, *it_dst);
}

// =======================
// Test of insert
// =======================

TEST(s21_set_test, test_insert_1) {
  s21::set<char> set_tst = {'x', 'z'};
  std::set<char> set_std = {'x', 'z'};
  std::pair<s21::set<char>::iterator, bool> it_tst_result = set_tst.insert('y');
  std::pair<std::set<char>::iterator, bool> it_std_result = set_std.insert('y');
  ASSERT_EQ(it_tst_result.second, it_std_result.second);
  ASSERT_EQ(*(it_tst_result.first), *(it_std_result.first));

  s21::set<char>::iterator it_tst = set_tst.begin();
  std::set<char>::iterator it_std = set_std.begin();
  for (; it_tst != set_tst.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_set_test, test_insert_2) {
  s21::set<int> set_tst = {23, 34, 675};
  std::set<int> set_std = {23, 34, 675};
  std::pair<s21::set<int>::iterator, bool> it_tst_result = set_tst.insert(55);
  std::pair<std::set<int>::iterator, bool> it_std_result = set_std.insert(55);
  ASSERT_EQ(it_tst_result.second, it_std_result.second);
  ASSERT_EQ(*(it_tst_result.first), *(it_std_result.first));

  s21::set<int>::iterator it_tst = set_tst.begin();
  std::set<int>::iterator it_std = set_std.begin();
  for (; it_tst != set_tst.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_set_test, test_insert_3) {
  s21::set<double> set_tst = {-123.456, 0.0, -0.0, 567.890, 12.23543, 96.75};
  std::set<double> set_std = {-123.456, 0.0, -0.0, 567.890, 12.23543, 96.75};
  std::pair<s21::set<double>::iterator, bool> it_tst_result =
      set_tst.insert(8.97);
  std::pair<std::set<double>::iterator, bool> it_std_result =
      set_std.insert(8.97);
  ASSERT_EQ(it_tst_result.second, it_std_result.second);
  ASSERT_EQ(*(it_tst_result.first), *(it_std_result.first));

  s21::set<double>::iterator it_tst = set_tst.begin();
  std::set<double>::iterator it_std = set_std.begin();
  for (; it_tst != set_tst.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_set_test, test_insert_4) {
  s21::set<std::string> set_tst;
  std::set<std::string> set_std;
  set_tst.insert("test");
  set_std.insert("test");

  s21::set<std::string>::iterator it_tst = set_tst.begin();
  std::set<std::string>::iterator it_std = set_std.begin();
  for (; it_tst != set_tst.end(); it_tst++, it_std++) {
    ASSERT_EQ(*it_tst, *it_std);
  }
}

TEST(s21_set_test, test_insert_5) {
  s21::set<std::string> set_tst = {"game", "over", "over", "hello!"};
  std::set<std::string> set_std = {"game", "over", "over", "hello!"};
  set_tst.insert("over");
  set_std.insert("over");

  s21::set<std::string>::iterator it_tst = set_tst.begin();
  std::set<std::string>::iterator it_std = set_std.begin();
  for (; it_tst != set_tst.end(); it_tst++, it_std++) {
    ASSERT_EQ(*it_tst, *it_std);
  }
}

// =======================
// Test of erase
// =======================

TEST(s21_set_test, test_erase_1) {
  s21::set<char> set_tst = {'x', 'z'};
  std::set<char> set_std = {'x', 'z'};
  s21::set<char>::iterator it_tst_temp = set_tst.begin();
  std::set<char>::iterator it_std_temp = set_std.begin();
  set_tst.erase(it_tst_temp);
  set_std.erase(it_std_temp);

  s21::set<char>::iterator it_tst = set_tst.begin();
  std::set<char>::iterator it_std = set_std.begin();
  for (; it_tst != set_tst.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_set_test, test_erase_2) {
  s21::set<int> set_tst = {23, 34, 675};
  std::set<int> set_std = {23, 34, 675};
  s21::set<int>::iterator it_tst_temp = set_tst.end();
  std::set<int>::iterator it_std_temp = set_std.end();
  it_tst_temp--;
  it_std_temp--;
  set_tst.erase(it_tst_temp);
  set_std.erase(it_std_temp);

  s21::set<int>::iterator it_tst = set_tst.begin();
  std::set<int>::iterator it_std = set_std.begin();
  for (; it_tst != set_tst.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_set_test, test_erase_3) {
  s21::set<double> set_tst = {-123.456, 0.0, -0.0, 567.890, 12.23543, 96.75};
  std::set<double> set_std = {-123.456, 0.0, -0.0, 567.890, 12.23543, 96.75};
  s21::set<double>::iterator it_tst_in = set_tst.begin();
  std::set<double>::iterator it_std_in = set_std.begin();
  for (int i = 0; i < 4; i++) it_tst_in++;
  for (int i = 0; i < 4; i++) it_std_in++;
  set_tst.erase(it_tst_in);
  set_std.erase(it_std_in);

  s21::set<double>::iterator it_tst = set_tst.begin();
  std::set<double>::iterator it_std = set_std.begin();
  for (; it_tst != set_tst.end(); it_tst++, it_std++) {
    ASSERT_EQ(*it_tst, *it_std);
  }
}

TEST(s21_set_test, test_erase_4) {
  s21::set<std::string> set_tst = {"WTF?!"};
  std::set<std::string> set_std = {"WTF?!"};
  s21::set<std::string>::iterator it_tst_temp = set_tst.begin();
  std::set<std::string>::iterator it_std_temp = set_std.begin();
  set_tst.erase(it_tst_temp);
  set_std.erase(it_std_temp);
  ASSERT_EQ(set_tst.empty(), set_std.empty());
}

// =======================
// Test of merge
// =======================

TEST(s21_set_test, test_merge_1) {
  s21::set<char> set_tst_1 = {'x', 'z'};
  s21::set<char> set_tst_2;
  std::set<char> set_std_1 = {'x', 'z'};
  std::set<char> set_std_2;
  set_tst_1.merge(set_tst_2);
  set_std_1.merge(set_std_2);

  s21::set<char>::iterator it_tst = set_tst_1.begin();
  std::set<char>::iterator it_std = set_std_1.begin();
  for (; it_tst != set_tst_1.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_set_test, test_merge_2) {
  s21::set<int> set_tst_1;
  s21::set<int> set_tst_2 = {23, 34, 675};
  std::set<int> set_std_1;
  std::set<int> set_std_2 = {23, 34, 675};
  set_tst_1.merge(set_tst_2);
  set_std_1.merge(set_std_2);

  s21::set<int>::iterator it_tst = set_tst_1.begin();
  std::set<int>::iterator it_std = set_std_1.begin();
  for (; it_tst != set_tst_1.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_set_test, test_merge_3) {
  s21::set<double> set_tst_1 = {-123.456, 0.0, -0.0, 567.890};
  s21::set<double> set_tst_2 = {12.23543, 96.75};
  std::set<double> set_std_1 = {-123.456, 0.0, -0.0, 567.890};
  std::set<double> set_std_2 = {12.23543, 96.75};
  set_tst_1.merge(set_tst_2);
  set_std_1.merge(set_std_2);

  s21::set<double>::iterator it_tst = set_tst_1.begin();
  std::set<double>::iterator it_std = set_std_1.begin();
  for (; it_tst != set_tst_1.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_set_test, test_merge_4) {
  s21::set<std::string> set_tst_1 = {"begin", "123-2", "wtf?", "END!"};
  std::set<std::string> set_std_1 = {"begin", "123-2", "wtf?", "END!"};
  set_tst_1.merge(set_tst_1);
  set_std_1.merge(set_std_1);

  s21::set<std::string>::iterator it_tst = set_tst_1.begin();
  std::set<std::string>::iterator it_std = set_std_1.begin();
  for (; it_tst != set_tst_1.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

// =======================
// Test of swap
// =======================

TEST(s21_set_test, test_swap_1) {
  s21::set<char> set_tst_1 = {'x', 'z'};
  s21::set<char> set_tst_2;
  std::set<char> set_std_1 = {'x', 'z'};
  std::set<char> set_std_2;
  set_tst_1.swap(set_tst_2);
  set_std_1.swap(set_std_2);
  s21::set<char>::iterator it_tst_1 = set_tst_1.begin();
  std::set<char>::iterator it_std_1 = set_std_1.begin();
  for (; it_tst_1 != set_tst_1.end(); it_tst_1++, it_std_1++)
    ASSERT_EQ(*it_tst_1, *it_std_1);

  s21::set<char>::iterator it_tst_2 = set_tst_2.begin();
  std::set<char>::iterator it_std_2 = set_std_2.begin();
  for (; it_tst_2 != set_tst_2.end(); it_tst_2++, it_std_2++)
    ASSERT_EQ(*it_tst_2, *it_std_2);
}

TEST(s21_set_test, test_swap_2) {
  s21::set<int> set_tst_1;
  s21::set<int> set_tst_2 = {23, 34, 675};
  std::set<int> set_std_1;
  std::set<int> set_std_2 = {23, 34, 675};
  set_tst_1.swap(set_tst_2);
  set_std_1.swap(set_std_2);
  s21::set<int>::iterator it_tst_1 = set_tst_1.begin();
  std::set<int>::iterator it_std_1 = set_std_1.begin();
  for (; it_tst_1 != set_tst_1.end(); it_tst_1++, it_std_1++)
    ASSERT_EQ(*it_tst_1, *it_std_1);

  s21::set<int>::iterator it_tst_2 = set_tst_2.begin();
  std::set<int>::iterator it_std_2 = set_std_2.begin();
  for (; it_tst_2 != set_tst_2.end(); it_tst_2++, it_std_2++)
    ASSERT_EQ(*it_tst_2, *it_std_2);
}

TEST(s21_set_test, test_swap_3) {
  s21::set<double> set_tst_1 = {-123.456, 0.0, -0.0, 567.890};
  s21::set<double> set_tst_2 = {12.23543, 96.75};
  std::set<double> set_std_1 = {-123.456, 0.0, -0.0, 567.890};
  std::set<double> set_std_2 = {12.23543, 96.75};
  set_tst_1.swap(set_tst_2);
  set_std_1.swap(set_std_2);
  s21::set<double>::iterator it_tst_1 = set_tst_1.begin();
  std::set<double>::iterator it_std_1 = set_std_1.begin();
  for (; it_tst_1 != set_tst_1.end(); it_tst_1++, it_std_1++)
    ASSERT_EQ(*it_tst_1, *it_std_1);

  s21::set<double>::iterator it_tst_2 = set_tst_2.begin();
  std::set<double>::iterator it_std_2 = set_std_2.begin();
  for (; it_tst_2 != set_tst_2.end(); it_tst_2++, it_std_2++)
    ASSERT_EQ(*it_tst_2, *it_std_2);
}

TEST(s21_set_test, test_swap_4) {
  s21::set<std::string> set_tst_1 = {"begin", "123-2", "wtf?", "END!"};
  std::set<std::string> set_std_1 = {"begin", "123-2", "wtf?", "END!"};
  set_tst_1.swap(set_tst_1);
  set_std_1.swap(set_std_1);

  s21::set<std::string>::iterator it_tst = set_tst_1.begin();
  std::set<std::string>::iterator it_std = set_std_1.begin();
  for (; it_tst != set_tst_1.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

// =======================
// Test of find
// =======================

TEST(s21_set_test, test_find_1) {
  s21::set<char> set_tst = {'x', 'y', 'z', 'a', 'b'};
  std::set<char> set_std = {'x', 'y', 'z', 'a', 'b'};

  s21::set<char>::iterator it_tst_1 = set_tst.find('x');
  std::set<char>::iterator it_std_1 = set_std.find('x');
  ASSERT_EQ(*it_tst_1, *it_std_1);

  s21::set<char>::iterator it_tst_2 = set_tst.find('z');
  std::set<char>::iterator it_std_2 = set_std.find('z');
  ASSERT_EQ(*it_tst_2, *it_std_2);

  s21::set<char>::iterator it_tst_3 = set_tst.find('b');
  std::set<char>::iterator it_std_3 = set_std.find('b');
  ASSERT_EQ(*it_tst_3, *it_std_3);
}

TEST(s21_set_test, test_find_2) {
  s21::set<int> set_tst = {0, 1, 23, 34, 675};
  std::set<int> set_std = {0, 1, 23, 34, 675};

  s21::set<int>::iterator it_tst_1 = set_tst.find(0);
  std::set<int>::iterator it_std_1 = set_std.find(0);
  ASSERT_EQ(*it_tst_1, *it_std_1);

  s21::set<int>::iterator it_tst_2 = set_tst.find(1);
  std::set<int>::iterator it_std_2 = set_std.find(1);
  ASSERT_EQ(*it_tst_2, *it_std_2);

  s21::set<int>::iterator it_tst_3 = set_tst.find(675);
  std::set<int>::iterator it_std_3 = set_std.find(675);
  ASSERT_EQ(*it_tst_3, *it_std_3);
}

TEST(s21_set_test, test_find_3) {
  s21::set<double> set_tst = {-123.456, 0.0, -0.0, 567.890, 12.23543, 96.75};
  std::set<double> set_std = {-123.456, 0.0, -0.0, 567.890, 12.23543, 96.75};

  s21::set<double>::iterator it_tst_1 = set_tst.find(-0.0);
  std::set<double>::iterator it_std_1 = set_std.find(-0.0);
  ASSERT_EQ(*it_tst_1, *it_std_1);

  s21::set<double>::iterator it_tst_2 = set_tst.find(-123.456);
  std::set<double>::iterator it_std_2 = set_std.find(-123.456);
  ASSERT_EQ(*it_tst_2, *it_std_2);

  s21::set<double>::iterator it_tst_3 = set_tst.find(12.23543);
  std::set<double>::iterator it_std_3 = set_std.find(12.23543);
  ASSERT_EQ(*it_tst_3, *it_std_3);
}

TEST(s21_set_test, test_find_4) {
  s21::set<std::string> set_tst = {"begin", "123-2", "wtf?", "END!"};
  std::set<std::string> set_std = {"begin", "123-2", "wtf?", "END!"};

  s21::set<std::string>::iterator it_tst_1 = set_tst.find("begin");
  std::set<std::string>::iterator it_std_1 = set_std.find("begin");
  ASSERT_EQ(*it_tst_1, *it_std_1);

  s21::set<std::string>::iterator it_tst_2 = set_tst.find("123-2");
  std::set<std::string>::iterator it_std_2 = set_std.find("123-2");
  ASSERT_EQ(*it_tst_2, *it_std_2);

  s21::set<std::string>::iterator it_tst_3 = set_tst.find("END!");
  std::set<std::string>::iterator it_std_3 = set_std.find("END!");
  ASSERT_EQ(*it_tst_3, *it_std_3);
}

// =======================
// Test of contains
// =======================

TEST(s21_set_test, test_contains_1) {
  s21::set<char> set_tst = {'x', 'y', 'z', 'a', 'b'};
  std::set<char> set_std = {'x', 'y', 'z', 'a', 'b'};
  ASSERT_EQ(set_tst.contains('x'), true);
  ASSERT_EQ(set_tst.contains('b'), true);
  ASSERT_EQ(set_tst.contains('e'), false);
  ASSERT_EQ(set_tst.contains('0'), false);
}

TEST(s21_set_test, test_contains_2) {
  s21::set<int> set_tst = {0, 1, 23, 34, 675};
  std::set<int> set_std = {0, 1, 23, 34, 675};
  ASSERT_EQ(set_tst.contains(0), true);
  ASSERT_EQ(set_tst.contains(1), true);
  ASSERT_EQ(set_tst.contains(675), true);
  ASSERT_EQ(set_tst.contains(2334), false);
  ASSERT_EQ(set_tst.contains(-1), false);
}

TEST(s21_set_test, test_contains_3) {
  s21::set<double> set_tst = {-123.456, 0.0, -0.0, 567.890, 12.23543, 96.75};
  std::set<double> set_std = {-123.456, 0.0, -0.0, 567.890, 12.23543, 96.75};
  ASSERT_EQ(set_tst.contains(-0.0), true);
  ASSERT_EQ(set_tst.contains(-123.456), true);
  ASSERT_EQ(set_tst.contains(12.23543), true);
  ASSERT_EQ(set_tst.contains(-11.2412), false);
  ASSERT_EQ(set_tst.contains(12.2), false);
}

TEST(s21_set_test, test_contains_4) {
  s21::set<std::string> set_tst = {"begin", "123-2", "wtf?", "END!"};
  std::set<std::string> set_std = {"begin", "123-2", "wtf?", "END!"};
  ASSERT_EQ(set_tst.contains("begin"), true);
  ASSERT_EQ(set_tst.contains("123-2"), true);
  ASSERT_EQ(set_tst.contains("END!"), true);
  ASSERT_EQ(set_tst.contains("XXXX"), false);
  ASSERT_EQ(set_tst.contains(""), false);
}