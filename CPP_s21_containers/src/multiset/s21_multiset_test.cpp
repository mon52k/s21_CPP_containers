#include "s21_multiset.h"

#include <gtest/gtest.h>

// =======================
// Test of default constructor
// =======================

TEST(s21_multiset_test, test_default_constructor_1) {
  s21::multiset<char> multiset_tst;
  std::multiset<char> multiset_std;
  ASSERT_EQ(multiset_tst.size(), multiset_std.size());
  ASSERT_EQ(multiset_tst.empty(), multiset_std.empty());
}

TEST(s21_multiset_test, test_default_constructor_2) {
  s21::multiset<int> multiset_tst;
  std::multiset<int> multiset_std;
  ASSERT_EQ(multiset_tst.size(), multiset_std.size());
  ASSERT_EQ(multiset_tst.empty(), multiset_std.empty());
}

TEST(s21_multiset_test, test_default_constructor_3) {
  s21::multiset<double> multiset_tst;
  std::multiset<double> multiset_std;
  ASSERT_EQ(multiset_tst.size(), multiset_std.size());
  ASSERT_EQ(multiset_tst.empty(), multiset_std.empty());
}

TEST(s21_multiset_test, test_default_constructor_4) {
  s21::multiset<std::string> multiset_tst;
  std::multiset<std::string> multiset_std;
  ASSERT_EQ(multiset_tst.size(), multiset_std.size());
  ASSERT_EQ(multiset_tst.empty(), multiset_std.empty());
}

// =======================
// Test of multiset constructor
// =======================

TEST(s21_multiset_test, test_multiset_constructor_1) {
  s21::multiset<char> multiset_tst = {'a', 'b', 'x', 'z'};
  std::multiset<char> multiset_std = {'a', 'b', 'x', 'z'};
  ASSERT_EQ(multiset_tst.size(), multiset_std.size());
  ASSERT_EQ(multiset_tst.empty(), multiset_std.empty());
}

TEST(s21_multiset_test, test_multiset_constructor_2) {
  s21::multiset<int> multiset_tst = {0, 1, 500, -500};
  std::multiset<int> multiset_std = {0, 1, 500, -500};
  ASSERT_EQ(multiset_tst.size(), multiset_std.size());
  ASSERT_EQ(multiset_tst.empty(), multiset_std.empty());
}

TEST(s21_multiset_test, test_multiset_constructor_3) {
  s21::multiset<double> multiset_tst = {-123.456, 0.0, -0.0, 567.890};
  std::multiset<double> multiset_std = {-123.456, 0.0, -0.0, 567.890};
  ASSERT_EQ(multiset_tst.size(), multiset_std.size());
  ASSERT_EQ(multiset_tst.empty(), multiset_std.empty());
}

TEST(s21_multiset_test, test_multiset_constructor_4) {
  s21::multiset<std::string> multiset_tst = {"begin", "123-2", "wtf?", "END!"};
  std::multiset<std::string> multiset_std = {"begin", "123-2", "wtf?", "END!"};
  ASSERT_EQ(multiset_tst.size(), multiset_std.size());
  ASSERT_EQ(multiset_tst.empty(), multiset_std.empty());
}

// =======================
// Test of copy constructor
// =======================

TEST(s21_multiset_test, test_copy_constructor_1) {
  s21::multiset<char> multiset_tst_src = {'a', 'b', 'x', 'z'};
  s21::multiset<char> multiset_tst_dst(multiset_tst_src);
  s21::multiset<char>::iterator it_src = multiset_tst_src.begin();
  s21::multiset<char>::iterator it_dst = multiset_tst_dst.begin();
  for (; it_src != multiset_tst_src.end(); it_src++, it_dst++)
    ASSERT_EQ(*it_src, *it_dst);
}

TEST(s21_multiset_test, test_copy_constructor_2) {
  s21::multiset<int> multiset_tst_src = {0, 1, 500, -500};
  s21::multiset<int> multiset_tst_dst(multiset_tst_src);
  s21::multiset<int>::iterator it_src = multiset_tst_src.begin();
  s21::multiset<int>::iterator it_dst = multiset_tst_dst.begin();
  for (; it_src != multiset_tst_src.end(); it_src++, it_dst++)
    ASSERT_EQ(*it_src, *it_dst);
}

TEST(s21_multiset_test, test_copy_constructor_3) {
  s21::multiset<double> multiset_tst_src = {-123.456, 0.0, -0.0, 567.890};
  s21::multiset<double> multiset_tst_dst(multiset_tst_src);
  s21::multiset<double>::iterator it_src = multiset_tst_src.begin();
  s21::multiset<double>::iterator it_dst = multiset_tst_dst.begin();
  for (; it_src != multiset_tst_src.end(); it_src++, it_dst++)
    ASSERT_EQ(*it_src, *it_dst);
}

TEST(s21_multiset_test, test_copy_constructor_4) {
  s21::multiset<std::string> multiset_tst_src = {"begin", "123-2", "wtf?",
                                                 "END!"};
  s21::multiset<std::string> multiset_tst_dst(multiset_tst_src);
  s21::multiset<std::string>::iterator it_src = multiset_tst_src.begin();
  s21::multiset<std::string>::iterator it_dst = multiset_tst_dst.begin();
  for (; it_src != multiset_tst_src.end(); it_src++, it_dst++)
    ASSERT_EQ(*it_src, *it_dst);
}

// =======================
// Test of assignment constructor
// =======================

TEST(s21_multiset_test, test_assign_constructor_1) {
  s21::multiset<char> multiset_tst = {'a', 'b', 'x', 'z'};
  s21::multiset<char> multiset_tst_src = {'a', 'b', 'x', 'z'};
  s21::multiset<char> multiset_tst_dst = std::move(multiset_tst_src);
  s21::multiset<char>::iterator it = multiset_tst.begin();
  s21::multiset<char>::iterator it_dst = multiset_tst_dst.begin();
  for (; it != multiset_tst.end(); it++, it_dst++) ASSERT_EQ(*it, *it_dst);
}

TEST(s21_multiset_test, test_assign_constructor_2) {
  s21::multiset<int> multiset_tst = {0, 1, 500, -500};
  s21::multiset<int> multiset_tst_src = {0, 1, 500, -500};
  s21::multiset<int> multiset_tst_dst = std::move(multiset_tst_src);
  s21::multiset<int>::iterator it = multiset_tst.begin();
  s21::multiset<int>::iterator it_dst = multiset_tst_dst.begin();
  for (; it != multiset_tst.end(); it++, it_dst++) ASSERT_EQ(*it, *it_dst);
}

TEST(s21_multiset_test, test_assign_constructor_3) {
  s21::multiset<double> multiset_tst = {-123.456, 0.0, -0.0, 567.890};
  s21::multiset<double> multiset_tst_src = {-123.456, 0.0, -0.0, 567.890};
  s21::multiset<double> multiset_tst_dst = std::move(multiset_tst_src);
  s21::multiset<double>::iterator it = multiset_tst.begin();
  s21::multiset<double>::iterator it_dst = multiset_tst_dst.begin();
  for (; it != multiset_tst.end(); it++, it_dst++) ASSERT_EQ(*it, *it_dst);
}

TEST(s21_multiset_test, test_assign_constructor_4) {
  s21::multiset<std::string> multiset_tst = {"begin", "123-2", "wtf?", "END!"};
  s21::multiset<std::string> multiset_tst_src = {"begin", "123-2", "wtf?",
                                                 "END!"};
  s21::multiset<std::string> multiset_tst_dst = std::move(multiset_tst_src);
  s21::multiset<std::string>::iterator it = multiset_tst.begin();
  s21::multiset<std::string>::iterator it_dst = multiset_tst_dst.begin();
  for (; it != multiset_tst.end(); it++, it_dst++) ASSERT_EQ(*it, *it_dst);
}

// =======================
// Test of insert
// =======================

TEST(s21_multiset_test, test_insert_1) {
  s21::multiset<char> multiset_tst = {'x', 'z'};
  std::multiset<char> multiset_std = {'x', 'z'};
  s21::multiset<char>::iterator it_tst_result = multiset_tst.insert('y');
  std::multiset<char>::iterator it_std_result = multiset_std.insert('y');
  ASSERT_EQ(*it_tst_result, *it_std_result);

  s21::multiset<char>::iterator it_tst = multiset_tst.begin();
  std::multiset<char>::iterator it_std = multiset_std.begin();
  for (; it_tst != multiset_tst.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_multiset_test, test_insert_2) {
  s21::multiset<int> multiset_tst = {23, 34, 675};
  std::multiset<int> multiset_std = {23, 34, 675};
  s21::multiset<int>::iterator it_tst_result = multiset_tst.insert(55);
  std::multiset<int>::iterator it_std_result = multiset_std.insert(55);
  ASSERT_EQ(*it_tst_result, *it_std_result);

  s21::multiset<int>::iterator it_tst = multiset_tst.begin();
  std::multiset<int>::iterator it_std = multiset_std.begin();
  for (; it_tst != multiset_tst.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_multiset_test, test_insert_3) {
  s21::multiset<double> multiset_tst = {-123.456, 0.0,      -0.0,
                                        567.890,  12.23543, 96.75};
  std::multiset<double> multiset_std = {-123.456, 0.0,      -0.0,
                                        567.890,  12.23543, 96.75};
  s21::multiset<double>::iterator it_tst_result = multiset_tst.insert(8.97);
  std::multiset<double>::iterator it_std_result = multiset_std.insert(8.97);
  ASSERT_EQ(*it_tst_result, *it_std_result);

  s21::multiset<double>::iterator it_tst = multiset_tst.begin();
  std::multiset<double>::iterator it_std = multiset_std.begin();
  for (; it_tst != multiset_tst.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_multiset_test, test_insert_4) {
  s21::multiset<std::string> multiset_tst;
  std::multiset<std::string> multiset_std;
  multiset_tst.insert("test");
  multiset_std.insert("test");

  s21::multiset<std::string>::iterator it_tst = multiset_tst.begin();
  std::multiset<std::string>::iterator it_std = multiset_std.begin();
  for (; it_tst != multiset_tst.end(); it_tst++, it_std++) {
    ASSERT_EQ(*it_tst, *it_std);
  }
}

TEST(s21_multiset_test, test_insert_5) {
  s21::multiset<std::string> multiset_tst = {"game", "over", "over", "hello!"};
  std::multiset<std::string> multiset_std = {"game", "over", "over", "hello!"};
  multiset_tst.insert("over");
  multiset_std.insert("over");

  s21::multiset<std::string>::iterator it_tst = multiset_tst.begin();
  std::multiset<std::string>::iterator it_std = multiset_std.begin();
  for (; it_tst != multiset_tst.end(); it_tst++, it_std++) {
    ASSERT_EQ(*it_tst, *it_std);
  }
}

// =======================
// Test of erase
// =======================

TEST(s21_multiset_test, test_erase_1) {
  s21::multiset<char> multiset_tst = {'x', 'z'};
  std::multiset<char> multiset_std = {'x', 'z'};
  s21::multiset<char>::iterator it_tst_temp = multiset_tst.begin();
  std::multiset<char>::iterator it_std_temp = multiset_std.begin();
  multiset_tst.erase(it_tst_temp);
  multiset_std.erase(it_std_temp);

  s21::multiset<char>::iterator it_tst = multiset_tst.begin();
  std::multiset<char>::iterator it_std = multiset_std.begin();
  for (; it_tst != multiset_tst.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_multiset_test, test_erase_2) {
  s21::multiset<int> multiset_tst = {23, 34, 675};
  std::multiset<int> multiset_std = {23, 34, 675};
  s21::multiset<int>::iterator it_tst_temp = multiset_tst.end();
  std::multiset<int>::iterator it_std_temp = multiset_std.end();
  it_tst_temp--;
  it_std_temp--;
  multiset_tst.erase(it_tst_temp);
  multiset_std.erase(it_std_temp);

  s21::multiset<int>::iterator it_tst = multiset_tst.begin();
  std::multiset<int>::iterator it_std = multiset_std.begin();
  for (; it_tst != multiset_tst.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_multiset_test, test_erase_3) {
  s21::multiset<double> multiset_tst = {-123.456, 0.0,      -0.0,
                                        567.890,  12.23543, 96.75};
  std::multiset<double> multiset_std = {-123.456, 0.0,      -0.0,
                                        567.890,  12.23543, 96.75};
  s21::multiset<double>::iterator it_tst_in = multiset_tst.begin();
  std::multiset<double>::iterator it_std_in = multiset_std.begin();
  for (int i = 0; i < 4; i++) it_tst_in++;
  for (int i = 0; i < 4; i++) it_std_in++;
  multiset_tst.erase(it_tst_in);
  multiset_std.erase(it_std_in);

  s21::multiset<double>::iterator it_tst = multiset_tst.begin();
  std::multiset<double>::iterator it_std = multiset_std.begin();
  for (; it_tst != multiset_tst.end(); it_tst++, it_std++) {
    ASSERT_EQ(*it_tst, *it_std);
  }
}

TEST(s21_multiset_test, test_erase_4) {
  s21::multiset<std::string> multiset_tst = {"WTF?!"};
  std::multiset<std::string> multiset_std = {"WTF?!"};
  s21::multiset<std::string>::iterator it_tst_temp = multiset_tst.begin();
  std::multiset<std::string>::iterator it_std_temp = multiset_std.begin();
  multiset_tst.erase(it_tst_temp);
  multiset_std.erase(it_std_temp);
  ASSERT_EQ(multiset_tst.empty(), multiset_std.empty());
}

// =======================
// Test of merge
// =======================

TEST(s21_multiset_test, test_merge_1) {
  s21::multiset<char> multiset_tst_1 = {'x', 'z'};
  s21::multiset<char> multiset_tst_2;
  std::multiset<char> multiset_std_1 = {'x', 'z'};
  std::multiset<char> multiset_std_2;
  multiset_tst_1.merge(multiset_tst_2);
  multiset_std_1.merge(multiset_std_2);

  s21::multiset<char>::iterator it_tst = multiset_tst_1.begin();
  std::multiset<char>::iterator it_std = multiset_std_1.begin();
  for (; it_tst != multiset_tst_1.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_multiset_test, test_merge_2) {
  s21::multiset<int> multiset_tst_1;
  s21::multiset<int> multiset_tst_2 = {23, 34, 675};
  std::multiset<int> multiset_std_1;
  std::multiset<int> multiset_std_2 = {23, 34, 675};
  multiset_tst_1.merge(multiset_tst_2);
  multiset_std_1.merge(multiset_std_2);

  s21::multiset<int>::iterator it_tst = multiset_tst_1.begin();
  std::multiset<int>::iterator it_std = multiset_std_1.begin();
  for (; it_tst != multiset_tst_1.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_multiset_test, test_merge_3) {
  s21::multiset<double> multiset_tst_1 = {-123.456, 0.0, -0.0, 567.890};
  s21::multiset<double> multiset_tst_2 = {12.23543, 96.75};
  std::multiset<double> multiset_std_1 = {-123.456, 0.0, -0.0, 567.890};
  std::multiset<double> multiset_std_2 = {12.23543, 96.75};
  multiset_tst_1.merge(multiset_tst_2);
  multiset_std_1.merge(multiset_std_2);

  s21::multiset<double>::iterator it_tst = multiset_tst_1.begin();
  std::multiset<double>::iterator it_std = multiset_std_1.begin();
  for (; it_tst != multiset_tst_1.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

// TEST(s21_multiset_test, test_merge_4) {
//   s21::multiset<std::string> multiset_tst_1 = {"begin", "123-2", "wtf?",
//                                                "END!"};
//   std::multiset<std::string> multiset_std_1 = {"begin", "123-2", "wtf?",
//                                                "END!"};
//   multiset_tst_1.merge(multiset_tst_1);
//   multiset_std_1.merge(multiset_std_1);

//   s21::multiset<std::string>::iterator it_tst = multiset_tst_1.begin();
//   std::multiset<std::string>::iterator it_std = multiset_std_1.begin();
//   for (; it_tst != multiset_tst_1.end(); it_tst++, it_std++)
//     ASSERT_EQ(*it_tst, *it_std);
// }

// =======================
// Test of swap
// =======================

TEST(s21_multiset_test, test_swap_1) {
  s21::multiset<char> multiset_tst_1 = {'x', 'z'};
  s21::multiset<char> multiset_tst_2;
  std::multiset<char> multiset_std_1 = {'x', 'z'};
  std::multiset<char> multiset_std_2;
  multiset_tst_1.swap(multiset_tst_2);
  multiset_std_1.swap(multiset_std_2);
  s21::multiset<char>::iterator it_tst_1 = multiset_tst_1.begin();
  std::multiset<char>::iterator it_std_1 = multiset_std_1.begin();
  for (; it_tst_1 != multiset_tst_1.end(); it_tst_1++, it_std_1++)
    ASSERT_EQ(*it_tst_1, *it_std_1);

  s21::multiset<char>::iterator it_tst_2 = multiset_tst_2.begin();
  std::multiset<char>::iterator it_std_2 = multiset_std_2.begin();
  for (; it_tst_2 != multiset_tst_2.end(); it_tst_2++, it_std_2++)
    ASSERT_EQ(*it_tst_2, *it_std_2);
}

TEST(s21_multiset_test, test_swap_2) {
  s21::multiset<int> multiset_tst_1;
  s21::multiset<int> multiset_tst_2 = {23, 34, 675};
  std::multiset<int> multiset_std_1;
  std::multiset<int> multiset_std_2 = {23, 34, 675};
  multiset_tst_1.swap(multiset_tst_2);
  multiset_std_1.swap(multiset_std_2);
  s21::multiset<int>::iterator it_tst_1 = multiset_tst_1.begin();
  std::multiset<int>::iterator it_std_1 = multiset_std_1.begin();
  for (; it_tst_1 != multiset_tst_1.end(); it_tst_1++, it_std_1++)
    ASSERT_EQ(*it_tst_1, *it_std_1);

  s21::multiset<int>::iterator it_tst_2 = multiset_tst_2.begin();
  std::multiset<int>::iterator it_std_2 = multiset_std_2.begin();
  for (; it_tst_2 != multiset_tst_2.end(); it_tst_2++, it_std_2++)
    ASSERT_EQ(*it_tst_2, *it_std_2);
}

TEST(s21_multiset_test, test_swap_3) {
  s21::multiset<double> multiset_tst_1 = {-123.456, 0.0, -0.0, 567.890};
  s21::multiset<double> multiset_tst_2 = {12.23543, 96.75};
  std::multiset<double> multiset_std_1 = {-123.456, 0.0, -0.0, 567.890};
  std::multiset<double> multiset_std_2 = {12.23543, 96.75};
  multiset_tst_1.swap(multiset_tst_2);
  multiset_std_1.swap(multiset_std_2);
  s21::multiset<double>::iterator it_tst_1 = multiset_tst_1.begin();
  std::multiset<double>::iterator it_std_1 = multiset_std_1.begin();
  for (; it_tst_1 != multiset_tst_1.end(); it_tst_1++, it_std_1++)
    ASSERT_EQ(*it_tst_1, *it_std_1);

  s21::multiset<double>::iterator it_tst_2 = multiset_tst_2.begin();
  std::multiset<double>::iterator it_std_2 = multiset_std_2.begin();
  for (; it_tst_2 != multiset_tst_2.end(); it_tst_2++, it_std_2++)
    ASSERT_EQ(*it_tst_2, *it_std_2);
}

TEST(s21_multiset_test, test_swap_4) {
  s21::multiset<std::string> multiset_tst_1 = {"begin", "123-2", "wtf?",
                                               "END!"};
  std::multiset<std::string> multiset_std_1 = {"begin", "123-2", "wtf?",
                                               "END!"};
  multiset_tst_1.swap(multiset_tst_1);
  multiset_std_1.swap(multiset_std_1);

  s21::multiset<std::string>::iterator it_tst = multiset_tst_1.begin();
  std::multiset<std::string>::iterator it_std = multiset_std_1.begin();
  for (; it_tst != multiset_tst_1.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

// =======================
// Test of find
// =======================

TEST(s21_multiset_test, test_find_1) {
  s21::multiset<char> multiset_tst = {'x', 'y', 'z', 'a', 'b'};
  std::multiset<char> multiset_std = {'x', 'y', 'z', 'a', 'b'};

  s21::multiset<char>::iterator it_tst_1 = multiset_tst.find('x');
  std::multiset<char>::iterator it_std_1 = multiset_std.find('x');
  ASSERT_EQ(*it_tst_1, *it_std_1);

  s21::multiset<char>::iterator it_tst_2 = multiset_tst.find('z');
  std::multiset<char>::iterator it_std_2 = multiset_std.find('z');
  ASSERT_EQ(*it_tst_2, *it_std_2);

  s21::multiset<char>::iterator it_tst_3 = multiset_tst.find('b');
  std::multiset<char>::iterator it_std_3 = multiset_std.find('b');
  ASSERT_EQ(*it_tst_3, *it_std_3);
}

TEST(s21_multiset_test, test_find_2) {
  s21::multiset<int> multiset_tst = {0, 1, 23, 34, 675};
  std::multiset<int> multiset_std = {0, 1, 23, 34, 675};

  s21::multiset<int>::iterator it_tst_1 = multiset_tst.find(0);
  std::multiset<int>::iterator it_std_1 = multiset_std.find(0);
  ASSERT_EQ(*it_tst_1, *it_std_1);

  s21::multiset<int>::iterator it_tst_2 = multiset_tst.find(1);
  std::multiset<int>::iterator it_std_2 = multiset_std.find(1);
  ASSERT_EQ(*it_tst_2, *it_std_2);

  s21::multiset<int>::iterator it_tst_3 = multiset_tst.find(675);
  std::multiset<int>::iterator it_std_3 = multiset_std.find(675);
  ASSERT_EQ(*it_tst_3, *it_std_3);
}

TEST(s21_multiset_test, test_find_3) {
  s21::multiset<double> multiset_tst = {-123.456, 0.0,      -0.0,
                                        567.890,  12.23543, 96.75};
  std::multiset<double> multiset_std = {-123.456, 0.0,      -0.0,
                                        567.890,  12.23543, 96.75};

  s21::multiset<double>::iterator it_tst_1 = multiset_tst.find(-0.0);
  std::multiset<double>::iterator it_std_1 = multiset_std.find(-0.0);
  ASSERT_EQ(*it_tst_1, *it_std_1);

  s21::multiset<double>::iterator it_tst_2 = multiset_tst.find(-123.456);
  std::multiset<double>::iterator it_std_2 = multiset_std.find(-123.456);
  ASSERT_EQ(*it_tst_2, *it_std_2);

  s21::multiset<double>::iterator it_tst_3 = multiset_tst.find(12.23543);
  std::multiset<double>::iterator it_std_3 = multiset_std.find(12.23543);
  ASSERT_EQ(*it_tst_3, *it_std_3);
}

TEST(s21_multiset_test, test_find_4) {
  s21::multiset<std::string> multiset_tst = {"begin", "123-2", "wtf?", "END!"};
  std::multiset<std::string> multiset_std = {"begin", "123-2", "wtf?", "END!"};

  s21::multiset<std::string>::iterator it_tst_1 = multiset_tst.find("begin");
  std::multiset<std::string>::iterator it_std_1 = multiset_std.find("begin");
  ASSERT_EQ(*it_tst_1, *it_std_1);

  s21::multiset<std::string>::iterator it_tst_2 = multiset_tst.find("123-2");
  std::multiset<std::string>::iterator it_std_2 = multiset_std.find("123-2");
  ASSERT_EQ(*it_tst_2, *it_std_2);

  s21::multiset<std::string>::iterator it_tst_3 = multiset_tst.find("END!");
  std::multiset<std::string>::iterator it_std_3 = multiset_std.find("END!");
  ASSERT_EQ(*it_tst_3, *it_std_3);
}

// =======================
// Test of contains
// =======================

TEST(s21_multiset_test, test_contains_1) {
  s21::multiset<char> multiset_tst = {'x', 'y', 'z', 'a', 'b'};
  std::multiset<char> multiset_std = {'x', 'y', 'z', 'a', 'b'};
  ASSERT_EQ(multiset_tst.contains('x'), true);
  ASSERT_EQ(multiset_tst.contains('b'), true);
  ASSERT_EQ(multiset_tst.contains('e'), false);
  ASSERT_EQ(multiset_tst.contains('0'), false);
}

TEST(s21_multiset_test, test_contains_2) {
  s21::multiset<int> multiset_tst = {0, 1, 23, 34, 675};
  std::multiset<int> multiset_std = {0, 1, 23, 34, 675};
  ASSERT_EQ(multiset_tst.contains(0), true);
  ASSERT_EQ(multiset_tst.contains(1), true);
  ASSERT_EQ(multiset_tst.contains(675), true);
  ASSERT_EQ(multiset_tst.contains(2334), false);
  ASSERT_EQ(multiset_tst.contains(-1), false);
}

TEST(s21_multiset_test, test_contains_3) {
  s21::multiset<double> multiset_tst = {-123.456, 0.0,      -0.0,
                                        567.890,  12.23543, 96.75};
  std::multiset<double> multiset_std = {-123.456, 0.0,      -0.0,
                                        567.890,  12.23543, 96.75};
  ASSERT_EQ(multiset_tst.contains(-0.0), true);
  ASSERT_EQ(multiset_tst.contains(-123.456), true);
  ASSERT_EQ(multiset_tst.contains(12.23543), true);
  ASSERT_EQ(multiset_tst.contains(-11.2412), false);
  ASSERT_EQ(multiset_tst.contains(12.2), false);
}

TEST(s21_multiset_test, test_contains_4) {
  s21::multiset<std::string> multiset_tst = {"begin", "123-2", "wtf?", "END!"};
  std::multiset<std::string> multiset_std = {"begin", "123-2", "wtf?", "END!"};
  ASSERT_EQ(multiset_tst.contains("begin"), true);
  ASSERT_EQ(multiset_tst.contains("123-2"), true);
  ASSERT_EQ(multiset_tst.contains("END!"), true);
  ASSERT_EQ(multiset_tst.contains("XXXX"), false);
  ASSERT_EQ(multiset_tst.contains(""), false);
}

// =======================
// Test of count
// =======================

TEST(s21_multiset_test, test_count_1) {
  s21::multiset<char> multiset_tst = {'x', 'y', 'z', 'a', 'b', 'a', 'y', 'y'};
  std::multiset<char> multiset_std = {'x', 'y', 'z', 'a', 'b', 'a', 'y', 'y'};
  ASSERT_EQ(multiset_tst.count('f'), multiset_std.count('f'));
  ASSERT_EQ(multiset_tst.count('x'), multiset_std.count('x'));
  ASSERT_EQ(multiset_tst.count('y'), multiset_std.count('y'));
  ASSERT_EQ(multiset_tst.count('b'), multiset_std.count('b'));
  ASSERT_EQ(multiset_tst.count('a'), multiset_std.count('a'));
}

TEST(s21_multiset_test, test_count_2) {
  s21::multiset<int> multiset_tst = {0, 1, 1, 1, 23, 34, 34, 675};
  std::multiset<int> multiset_std = {0, 1, 1, 1, 23, 34, 34, 675};
  ASSERT_EQ(multiset_tst.count(0), multiset_std.count(0));
  ASSERT_EQ(multiset_tst.count(1), multiset_std.count(1));
  ASSERT_EQ(multiset_tst.count(2), multiset_std.count(2));
  ASSERT_EQ(multiset_tst.count(23), multiset_std.count(23));
  ASSERT_EQ(multiset_tst.count(34), multiset_std.count(34));
}

TEST(s21_multiset_test, test_count_3) {
  s21::multiset<double> multiset_tst = {-123.456, 0.0,   -0.0,    567.890,
                                        12.23543, 96.75, 12.23543};
  std::multiset<double> multiset_std = {-123.456, 0.0,   -0.0,    567.890,
                                        12.23543, 96.75, 12.23543};
  ASSERT_EQ(multiset_tst.count(-123.456), multiset_std.count(-123.456));
  ASSERT_EQ(multiset_tst.count(0.0), multiset_std.count(0.0));
  ASSERT_EQ(multiset_tst.count(567.890), multiset_std.count(567.890));
  ASSERT_EQ(multiset_tst.count(12.235435), multiset_std.count(12.235435));
  ASSERT_EQ(multiset_tst.count(96.75), multiset_std.count(96.75));
}

TEST(s21_multiset_test, test_count_4) {
  s21::multiset<std::string> multiset_tst = {"begin", "123-2", "wtf?", "begin",
                                             "END!"};
  std::multiset<std::string> multiset_std = {"begin", "123-2", "wtf?", "begin",
                                             "END!"};
  ASSERT_EQ(multiset_tst.count("begin"), multiset_std.count("begin"));
  ASSERT_EQ(multiset_tst.count("123-2"), multiset_std.count("123-2"));
  ASSERT_EQ(multiset_tst.count("wtf?"), multiset_std.count("wtf?"));
  ASSERT_EQ(multiset_tst.count("END!"), multiset_std.count("END!"));
  ASSERT_EQ(multiset_tst.count("xXx"), multiset_std.count("xXx"));
}

// =======================
// Test of lower_bound
// =======================

TEST(s21_multiset_test, test_lower_bound_1) {
  s21::multiset<char> multiset_tst = {'x', 'y', 'z', 'a', 'b', 'a', 'y', 'y'};
  std::multiset<char> multiset_std = {'x', 'y', 'z', 'a', 'b', 'a', 'y', 'y'};

  s21::multiset<char>::iterator it_tst_1 = multiset_tst.lower_bound('f');
  std::multiset<char>::iterator it_std_1 = multiset_std.lower_bound('f');
  ASSERT_EQ(*it_tst_1, *it_std_1);

  s21::multiset<char>::iterator it_tst_2 = multiset_tst.lower_bound('a');
  std::multiset<char>::iterator it_std_2 = multiset_std.lower_bound('a');
  ASSERT_EQ(*it_tst_2, *it_std_2);

  s21::multiset<char>::iterator it_tst_3 = multiset_tst.lower_bound('b');
  std::multiset<char>::iterator it_std_3 = multiset_std.lower_bound('b');
  ASSERT_EQ(*it_tst_3, *it_std_3);

  s21::multiset<char>::iterator it_tst_4 = multiset_tst.lower_bound('y');
  std::multiset<char>::iterator it_std_4 = multiset_std.lower_bound('y');
  ASSERT_EQ(*it_tst_4, *it_std_4);
}

TEST(s21_multiset_test, test_lower_bound_2) {
  s21::multiset<int> multiset_tst = {0, 1, 1, 1, 23, 34, 34, 675};
  std::multiset<int> multiset_std = {0, 1, 1, 1, 23, 34, 34, 675};

  s21::multiset<int>::iterator it_tst_1 = multiset_tst.lower_bound(0);
  std::multiset<int>::iterator it_std_1 = multiset_std.lower_bound(0);
  ASSERT_EQ(*it_tst_1, *it_std_1);

  s21::multiset<int>::iterator it_tst_2 = multiset_tst.lower_bound(1);
  std::multiset<int>::iterator it_std_2 = multiset_std.lower_bound(1);
  ASSERT_EQ(*it_tst_2, *it_std_2);

  s21::multiset<int>::iterator it_tst_3 = multiset_tst.lower_bound(5);
  std::multiset<int>::iterator it_std_3 = multiset_std.lower_bound(5);
  ASSERT_EQ(*it_tst_3, *it_std_3);

  s21::multiset<int>::iterator it_tst_4 = multiset_tst.lower_bound(34);
  std::multiset<int>::iterator it_std_4 = multiset_std.lower_bound(34);
  ASSERT_EQ(*it_tst_4, *it_std_4);
}

TEST(s21_multiset_test, test_lower_bound_3) {
  s21::multiset<double> multiset_tst = {-123.456, 0.0,   -0.0,    567.890,
                                        12.23543, 96.75, 12.23543};
  std::multiset<double> multiset_std = {-123.456, 0.0,   -0.0,    567.890,
                                        12.23543, 96.75, 12.23543};

  s21::multiset<double>::iterator it_tst_1 = multiset_tst.lower_bound(0.0);
  std::multiset<double>::iterator it_std_1 = multiset_std.lower_bound(0.0);
  ASSERT_EQ(*it_tst_1, *it_std_1);

  s21::multiset<double>::iterator it_tst_2 = multiset_tst.lower_bound(-123.456);
  std::multiset<double>::iterator it_std_2 = multiset_std.lower_bound(-123.456);
  ASSERT_EQ(*it_tst_2, *it_std_2);

  s21::multiset<double>::iterator it_tst_3 =
      multiset_tst.lower_bound(12.235435);
  std::multiset<double>::iterator it_std_3 =
      multiset_std.lower_bound(12.235435);
  ASSERT_EQ(*it_tst_3, *it_std_3);

  s21::multiset<double>::iterator it_tst_4 = multiset_tst.lower_bound(96.75);
  std::multiset<double>::iterator it_std_4 = multiset_std.lower_bound(96.75);
  ASSERT_EQ(*it_tst_4, *it_std_4);
}

TEST(s21_multiset_test, test_lower_bound_4) {
  s21::multiset<std::string> multiset_tst = {"begin", "123-2", "wtf?", "begin",
                                             "END!"};
  std::multiset<std::string> multiset_std = {"begin", "123-2", "wtf?", "begin",
                                             "END!"};

  s21::multiset<std::string>::iterator it_tst_1 =
      multiset_tst.lower_bound("begin");
  std::multiset<std::string>::iterator it_std_1 =
      multiset_std.lower_bound("begin");
  ASSERT_EQ(*it_tst_1, *it_std_1);

  s21::multiset<std::string>::iterator it_tst_2 =
      multiset_tst.lower_bound("123-2");
  std::multiset<std::string>::iterator it_std_2 =
      multiset_std.lower_bound("123-2");
  ASSERT_EQ(*it_tst_2, *it_std_2);

  s21::multiset<std::string>::iterator it_tst_3 =
      multiset_tst.lower_bound("END!");
  std::multiset<std::string>::iterator it_std_3 =
      multiset_std.lower_bound("END!");
  ASSERT_EQ(*it_tst_3, *it_std_3);
}

// =======================
// Test of upper_bound
// =======================

TEST(s21_multiset_test, test_upper_bound_1) {
  s21::multiset<char> multiset_tst = {'x', 'y', 'z', 'a', 'b', 'a', 'y', 'y'};
  std::multiset<char> multiset_std = {'x', 'y', 'z', 'a', 'b', 'a', 'y', 'y'};

  s21::multiset<char>::iterator it_tst_1 = multiset_tst.upper_bound('f');
  std::multiset<char>::iterator it_std_1 = multiset_std.upper_bound('f');
  ASSERT_EQ(*it_tst_1, *it_std_1);

  s21::multiset<char>::iterator it_tst_2 = multiset_tst.upper_bound('a');
  std::multiset<char>::iterator it_std_2 = multiset_std.upper_bound('a');
  ASSERT_EQ(*it_tst_2, *it_std_2);

  s21::multiset<char>::iterator it_tst_3 = multiset_tst.upper_bound('b');
  std::multiset<char>::iterator it_std_3 = multiset_std.upper_bound('b');
  ASSERT_EQ(*it_tst_3, *it_std_3);

  s21::multiset<char>::iterator it_tst_4 = multiset_tst.upper_bound('y');
  std::multiset<char>::iterator it_std_4 = multiset_std.upper_bound('y');
  ASSERT_EQ(*it_tst_4, *it_std_4);
}

TEST(s21_multiset_test, test_upper_bound_2) {
  s21::multiset<int> multiset_tst = {0, 1, 1, 1, 23, 34, 34, 675};
  std::multiset<int> multiset_std = {0, 1, 1, 1, 23, 34, 34, 675};

  s21::multiset<int>::iterator it_tst_1 = multiset_tst.upper_bound(0);
  std::multiset<int>::iterator it_std_1 = multiset_std.upper_bound(0);
  ASSERT_EQ(*it_tst_1, *it_std_1);

  s21::multiset<int>::iterator it_tst_2 = multiset_tst.upper_bound(1);
  std::multiset<int>::iterator it_std_2 = multiset_std.upper_bound(1);
  ASSERT_EQ(*it_tst_2, *it_std_2);

  s21::multiset<int>::iterator it_tst_3 = multiset_tst.upper_bound(5);
  std::multiset<int>::iterator it_std_3 = multiset_std.upper_bound(5);
  ASSERT_EQ(*it_tst_3, *it_std_3);

  s21::multiset<int>::iterator it_tst_4 = multiset_tst.upper_bound(34);
  std::multiset<int>::iterator it_std_4 = multiset_std.upper_bound(34);
  ASSERT_EQ(*it_tst_4, *it_std_4);
}

TEST(s21_multiset_test, test_upper_bound_3) {
  s21::multiset<double> multiset_tst = {-123.456, 0.0,   -0.0,    567.890,
                                        12.23543, 96.75, 12.23543};
  std::multiset<double> multiset_std = {-123.456, 0.0,   -0.0,    567.890,
                                        12.23543, 96.75, 12.23543};

  s21::multiset<double>::iterator it_tst_1 = multiset_tst.upper_bound(0.0);
  std::multiset<double>::iterator it_std_1 = multiset_std.upper_bound(0.0);
  ASSERT_EQ(*it_tst_1, *it_std_1);

  s21::multiset<double>::iterator it_tst_2 = multiset_tst.upper_bound(-123.456);
  std::multiset<double>::iterator it_std_2 = multiset_std.upper_bound(-123.456);
  ASSERT_EQ(*it_tst_2, *it_std_2);

  s21::multiset<double>::iterator it_tst_3 =
      multiset_tst.upper_bound(12.235435);
  std::multiset<double>::iterator it_std_3 =
      multiset_std.upper_bound(12.235435);
  ASSERT_EQ(*it_tst_3, *it_std_3);

  s21::multiset<double>::iterator it_tst_4 = multiset_tst.upper_bound(96.75);
  std::multiset<double>::iterator it_std_4 = multiset_std.upper_bound(96.75);
  ASSERT_EQ(*it_tst_4, *it_std_4);
}

TEST(s21_multiset_test, test_upper_bound_4) {
  s21::multiset<std::string> multiset_tst = {"begin", "123-2", "wtf?", "begin",
                                             "END!"};
  std::multiset<std::string> multiset_std = {"begin", "123-2", "wtf?", "begin",
                                             "END!"};

  s21::multiset<std::string>::iterator it_tst_1 =
      multiset_tst.upper_bound("begin");
  std::multiset<std::string>::iterator it_std_1 =
      multiset_std.upper_bound("begin");
  ASSERT_EQ(*it_tst_1, *it_std_1);

  s21::multiset<std::string>::iterator it_tst_2 =
      multiset_tst.upper_bound("123-2");
  std::multiset<std::string>::iterator it_std_2 =
      multiset_std.upper_bound("123-2");
  ASSERT_EQ(*it_tst_2, *it_std_2);

  s21::multiset<std::string>::iterator it_tst_3 =
      multiset_tst.upper_bound("END!");
  std::multiset<std::string>::iterator it_std_3 =
      multiset_std.upper_bound("END!");
  ASSERT_EQ(*it_tst_3, *it_std_3);
}

// =======================
// Test of equal_range
// =======================

TEST(s21_multiset_test, test_equal_range_1) {
  s21::multiset<char> multiset_tst = {'x', 'y', 'z', 'a', 'b', 'a', 'y', 'y'};
  std::multiset<char> multiset_std = {'x', 'y', 'z', 'a', 'b', 'a', 'y', 'y'};

  std::pair<s21::multiset<char>::iterator, s21::multiset<char>::iterator>
      range_tst_1 = multiset_tst.equal_range('a');
  std::pair<std::multiset<char>::iterator, std::multiset<char>::iterator>
      range_std_1 = multiset_std.equal_range('a');
  s21::multiset<char>::iterator it_tst_1 = range_tst_1.first;
  std::multiset<char>::iterator it_std_1 = range_std_1.first;
  for (; it_tst_1 != range_tst_1.second && it_tst_1 != multiset_tst.end();
       it_tst_1++, it_std_1++)
    ASSERT_EQ(*it_tst_1, *it_std_1);

  std::pair<s21::multiset<char>::iterator, s21::multiset<char>::iterator>
      range_tst_2 = multiset_tst.equal_range('y');
  std::pair<std::multiset<char>::iterator, std::multiset<char>::iterator>
      range_std_2 = multiset_std.equal_range('y');
  s21::multiset<char>::iterator it_tst_2 = range_tst_2.first;
  std::multiset<char>::iterator it_std_2 = range_std_2.first;
  for (; it_tst_2 != range_tst_2.second && it_tst_2 != multiset_tst.end();
       it_tst_2++, it_std_2++)
    ASSERT_EQ(*it_tst_2, *it_std_2);

  std::pair<s21::multiset<char>::iterator, s21::multiset<char>::iterator>
      range_tst_3 = multiset_tst.equal_range('z');
  std::pair<std::multiset<char>::iterator, std::multiset<char>::iterator>
      range_std_3 = multiset_std.equal_range('z');
  s21::multiset<char>::iterator it_tst_3 = range_tst_3.first;
  std::multiset<char>::iterator it_std_3 = range_std_3.first;
  for (; it_tst_3 != range_tst_3.second && it_tst_3 != multiset_tst.end();
       it_tst_3++, it_std_3++)
    ASSERT_EQ(*it_tst_3, *it_std_3);
}

TEST(s21_multiset_test, test_equal_range_2) {
  s21::multiset<int> multiset_tst = {0, 1, 1, 1, 23, 34, 34, 675};
  std::multiset<int> multiset_std = {0, 1, 1, 1, 23, 34, 34, 675};

  std::pair<s21::multiset<int>::iterator, s21::multiset<int>::iterator>
      range_tst_1 = multiset_tst.equal_range(0);
  std::pair<std::multiset<int>::iterator, std::multiset<int>::iterator>
      range_std_1 = multiset_std.equal_range(0);
  s21::multiset<int>::iterator it_tst_1 = range_tst_1.first;
  std::multiset<int>::iterator it_std_1 = range_std_1.first;
  for (; it_tst_1 != range_tst_1.second && it_tst_1 != multiset_tst.end();
       it_tst_1++, it_std_1++)
    ASSERT_EQ(*it_tst_1, *it_std_1);

  std::pair<s21::multiset<int>::iterator, s21::multiset<int>::iterator>
      range_tst_2 = multiset_tst.equal_range(23);
  std::pair<std::multiset<int>::iterator, std::multiset<int>::iterator>
      range_std_2 = multiset_std.equal_range(23);
  s21::multiset<int>::iterator it_tst_2 = range_tst_2.first;
  std::multiset<int>::iterator it_std_2 = range_std_2.first;
  for (; it_tst_2 != range_tst_2.second && it_tst_2 != multiset_tst.end();
       it_tst_2++, it_std_2++)
    ASSERT_EQ(*it_tst_2, *it_std_2);

  std::pair<s21::multiset<int>::iterator, s21::multiset<int>::iterator>
      range_tst_3 = multiset_tst.equal_range(34);
  std::pair<std::multiset<int>::iterator, std::multiset<int>::iterator>
      range_std_3 = multiset_std.equal_range(34);
  s21::multiset<int>::iterator it_tst_3 = range_tst_3.first;
  std::multiset<int>::iterator it_std_3 = range_std_3.first;
  for (; it_tst_3 != range_tst_3.second && it_tst_3 != multiset_tst.end();
       it_tst_3++, it_std_3++)
    ASSERT_EQ(*it_tst_3, *it_std_3);
}

TEST(s21_multiset_test, test_equal_range_3) {
  s21::multiset<double> multiset_tst = {-123.456, 0.0,   -0.0,    567.890,
                                        12.23543, 96.75, 12.23543};
  std::multiset<double> multiset_std = {-123.456, 0.0,   -0.0,    567.890,
                                        12.23543, 96.75, 12.23543};

  std::pair<s21::multiset<double>::iterator, s21::multiset<double>::iterator>
      range_tst_1 = multiset_tst.equal_range(-123.456);
  std::pair<std::multiset<double>::iterator, std::multiset<double>::iterator>
      range_std_1 = multiset_std.equal_range(-123.456);
  s21::multiset<double>::iterator it_tst_1 = range_tst_1.first;
  std::multiset<double>::iterator it_std_1 = range_std_1.first;
  for (; it_tst_1 != range_tst_1.second && it_tst_1 != multiset_tst.end();
       it_tst_1++, it_std_1++)
    ASSERT_EQ(*it_tst_1, *it_std_1);

  std::pair<s21::multiset<double>::iterator, s21::multiset<double>::iterator>
      range_tst_2 = multiset_tst.equal_range(0.0);
  std::pair<std::multiset<double>::iterator, std::multiset<double>::iterator>
      range_std_2 = multiset_std.equal_range(0.0);
  s21::multiset<double>::iterator it_tst_2 = range_tst_2.first;
  std::multiset<double>::iterator it_std_2 = range_std_2.first;
  for (; it_tst_2 != range_tst_2.second && it_tst_2 != multiset_tst.end();
       it_tst_2++, it_std_2++)
    ASSERT_EQ(*it_tst_2, *it_std_2);

  std::pair<s21::multiset<double>::iterator, s21::multiset<double>::iterator>
      range_tst_3 = multiset_tst.equal_range(96.75);
  std::pair<std::multiset<double>::iterator, std::multiset<double>::iterator>
      range_std_3 = multiset_std.equal_range(96.75);
  s21::multiset<double>::iterator it_tst_3 = range_tst_3.first;
  std::multiset<double>::iterator it_std_3 = range_std_3.first;
  for (; it_tst_3 != range_tst_3.second && it_tst_3 != multiset_tst.end();
       it_tst_3++, it_std_3++)
    ASSERT_EQ(*it_tst_3, *it_std_3);
}

TEST(s21_multiset_test, test_equal_range_4) {
  s21::multiset<std::string> multiset_tst = {"begin", "123-2", "wtf?", "begin",
                                             "END!"};
  std::multiset<std::string> multiset_std = {"begin", "123-2", "wtf?", "begin",
                                             "END!"};

  std::pair<s21::multiset<std::string>::iterator,
            s21::multiset<std::string>::iterator>
      range_tst_1 = multiset_tst.equal_range("begin");
  std::pair<std::multiset<std::string>::iterator,
            std::multiset<std::string>::iterator>
      range_std_1 = multiset_std.equal_range("begin");
  s21::multiset<std::string>::iterator it_tst_1 = range_tst_1.first;
  std::multiset<std::string>::iterator it_std_1 = range_std_1.first;
  for (; it_tst_1 != range_tst_1.second && it_tst_1 != multiset_tst.end();
       it_tst_1++, it_std_1++)
    ASSERT_EQ(*it_tst_1, *it_std_1);

  std::pair<s21::multiset<std::string>::iterator,
            s21::multiset<std::string>::iterator>
      range_tst_2 = multiset_tst.equal_range("123-2");
  std::pair<std::multiset<std::string>::iterator,
            std::multiset<std::string>::iterator>
      range_std_2 = multiset_std.equal_range("123-2");
  s21::multiset<std::string>::iterator it_tst_2 = range_tst_2.first;
  std::multiset<std::string>::iterator it_std_2 = range_std_2.first;
  for (; it_tst_2 != range_tst_2.second && it_tst_2 != multiset_tst.end();
       it_tst_2++, it_std_2++)
    ASSERT_EQ(*it_tst_2, *it_std_2);

  std::pair<s21::multiset<std::string>::iterator,
            s21::multiset<std::string>::iterator>
      range_tst_3 = multiset_tst.equal_range("END!");
  std::pair<std::multiset<std::string>::iterator,
            std::multiset<std::string>::iterator>
      range_std_3 = multiset_std.equal_range("END!");
  s21::multiset<std::string>::iterator it_tst_3 = range_tst_3.first;
  std::multiset<std::string>::iterator it_std_3 = range_std_3.first;
  for (; it_tst_3 != range_tst_3.second && it_tst_3 != multiset_tst.end();
       it_tst_3++, it_std_3++)
    ASSERT_EQ(*it_tst_3, *it_std_3);
}