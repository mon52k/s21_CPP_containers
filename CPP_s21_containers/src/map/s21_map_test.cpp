#include "s21_map.h"

#include <gtest/gtest.h>

#include <map>

// =======================
// Test of default constructor
// =======================

TEST(s21_map_test, test_default_constructor_1) {
  s21::map<int, char> map_tst;
  std::map<int, char> map_std;
  ASSERT_EQ(map_tst.size(), map_std.size());
  ASSERT_EQ(map_tst.empty(), map_std.empty());
}

TEST(s21_map_test, test_default_constructor_2) {
  s21::map<char, int> map_tst;
  std::map<char, int> map_std;
  ASSERT_EQ(map_tst.size(), map_std.size());
  ASSERT_EQ(map_tst.empty(), map_std.empty());
}

TEST(s21_map_test, test_default_constructor_3) {
  s21::map<double, double> map_tst;
  std::map<double, double> map_std;
  ASSERT_EQ(map_tst.size(), map_std.size());
  ASSERT_EQ(map_tst.empty(), map_std.empty());
}

TEST(s21_map_test, test_default_constructor_4) {
  s21::map<std::string, std::string> map_tst;
  std::map<std::string, std::string> map_std;
  ASSERT_EQ(map_tst.size(), map_std.size());
  ASSERT_EQ(map_tst.empty(), map_std.empty());
}

TEST(s21_map_test, test_default_constructor_5) {
  s21::map<int, std::string> map_tst;
  std::map<int, std::string> map_std;
  ASSERT_EQ(map_tst.size(), map_std.size());
  ASSERT_EQ(map_tst.empty(), map_std.empty());
}

// =======================
// Test of map constructor
// =======================

TEST(s21_map_test, test_map_constructor_1) {
  s21::map<char, char> map_tst = {
      {'a', 'a'}, {'b', 'z'}, {'b', 'x'}, {'x', 'z'}};
  std::map<char, char> map_std = {
      {'a', 'a'}, {'b', 'z'}, {'b', 'x'}, {'x', 'z'}};
  ASSERT_EQ(map_tst.size(), map_std.size());
  ASSERT_EQ(map_tst.empty(), map_std.empty());
}

TEST(s21_map_test, test_map_constructor_2) {
  s21::map<int, char> map_tst = {{0, 'a'}, {1, '!'}, {500, 'a'}, {-500, 'X'}};
  std::map<int, char> map_std = {{0, 'a'}, {1, '!'}, {500, 'a'}, {-500, 'X'}};
  ASSERT_EQ(map_tst.size(), map_std.size());
  ASSERT_EQ(map_tst.empty(), map_std.empty());
}

TEST(s21_map_test, test_map_constructor_3) {
  s21::map<double, double> map_tst = {
      {-123.456, 0.0}, {-0.0, 567.890}, {123.456, 10.10}};
  std::map<double, double> map_std = {
      {-123.456, 0.0}, {-0.0, 567.890}, {123.456, 10.10}};
  ASSERT_EQ(map_tst.size(), map_std.size());
  ASSERT_EQ(map_tst.empty(), map_std.empty());
}

TEST(s21_map_test, test_map_constructor_4) {
  s21::map<int, std::string> map_tst = {
      {1, "begin"}, {3, "123-2"}, {0, "wtf?"}, {-1, "END!"}};
  std::map<int, std::string> map_std = {
      {1, "begin"}, {3, "123-2"}, {0, "wtf?"}, {-1, "END!"}};
  ASSERT_EQ(map_tst.size(), map_std.size());
  ASSERT_EQ(map_tst.empty(), map_std.empty());
}

TEST(s21_map_test, test_map_constructor_5) {
  s21::map<std::string, double> map_tst = {{"begin", 342.212},
                                           {"123-2", 0.0},
                                           {"wtf?", -0.0},
                                           {"END!", 22301.222343123}};
  std::map<std::string, double> map_std = {{"begin", 342.212},
                                           {"123-2", 0.0},
                                           {"wtf?", -0.0},
                                           {"END!", 22301.222343123}};
  ASSERT_EQ(map_tst.size(), map_std.size());
  ASSERT_EQ(map_tst.empty(), map_std.empty());
}

// =======================
// Test of copy constructor
// =======================

TEST(s21_map_test, test_copy_constructor_1) {
  s21::map<char, char> map_tst_src = {
      {'a', 'a'}, {'b', 'z'}, {'b', 'x'}, {'x', 'z'}};
  s21::map<char, char> map_tst_dst(map_tst_src);
  s21::map<char, char>::iterator it_src = map_tst_src.begin();
  s21::map<char, char>::iterator it_dst = map_tst_dst.begin();
  for (; it_src != map_tst_src.end(); it_src++, it_dst++)
    ASSERT_EQ(*it_src, *it_dst);
}

TEST(s21_map_test, test_copy_constructor_2) {
  s21::map<int, char> map_tst_src = {
      {0, 'a'}, {1, '!'}, {500, 'a'}, {-500, 'X'}};
  s21::map<int, char> map_tst_dst(map_tst_src);
  s21::map<int, char>::iterator it_src = map_tst_src.begin();
  s21::map<int, char>::iterator it_dst = map_tst_dst.begin();
  for (; it_src != map_tst_src.end(); it_src++, it_dst++)
    ASSERT_EQ(*it_src, *it_dst);
}

TEST(s21_map_test, test_copy_constructor_3) {
  s21::map<double, int> map_tst_src = {
      {-123.456, 0}, {-0.0, 567}, {123.456, 10}, {0.0, 1}};
  s21::map<double, int> map_tst_dst(map_tst_src);
  s21::map<double, int>::iterator it_src = map_tst_src.begin();
  s21::map<double, int>::iterator it_dst = map_tst_dst.begin();
  for (; it_src != map_tst_src.end(); it_src++, it_dst++)
    ASSERT_EQ(*it_src, *it_dst);
}

TEST(s21_map_test, test_copy_constructor_4) {
  s21::map<int, std::string> map_tst_src = {
      {1, "begin"}, {3, "123-2"}, {0, "wtf?"}, {-1, "END!"}};
  s21::map<int, std::string> map_tst_dst(map_tst_src);
  s21::map<int, std::string>::iterator it_src = map_tst_src.begin();
  s21::map<int, std::string>::iterator it_dst = map_tst_dst.begin();
  for (; it_src != map_tst_src.end(); it_src++, it_dst++)
    ASSERT_EQ(*it_src, *it_dst);
}

TEST(s21_map_test, test_copy_constructor_5) {
  s21::map<std::string, double> map_tst_src = {{"begin", 342.212},
                                               {"123-2", 0.0},
                                               {"wtf?", -0.0},
                                               {"END!", 22301.222343123}};
  s21::map<std::string, double> map_tst_dst(map_tst_src);
  s21::map<std::string, double>::iterator it_src = map_tst_src.begin();
  s21::map<std::string, double>::iterator it_dst = map_tst_dst.begin();
  for (; it_src != map_tst_src.end(); it_src++, it_dst++)
    ASSERT_EQ(*it_src, *it_dst);
}

// =======================
// Test of assignment constructor
// =======================

TEST(s21_map_test, test_assign_constructor_1) {
  s21::map<char, char> map_tst = {
      {'a', 'a'}, {'b', 'z'}, {'b', 'x'}, {'x', 'z'}};
  s21::map<char, char> map_tst_src = {
      {'a', 'a'}, {'b', 'z'}, {'b', 'x'}, {'x', 'z'}};
  s21::map<char, char> map_tst_dst = std::move(map_tst_src);
  s21::map<char, char>::iterator it = map_tst.begin();
  s21::map<char, char>::iterator it_dst = map_tst_dst.begin();
  for (; it != map_tst.end(); it++, it_dst++) ASSERT_EQ(*it, *it_dst);
}

TEST(s21_map_test, test_assign_constructor_2) {
  s21::map<int, char> map_tst = {{0, 'a'}, {1, '!'}, {500, 'a'}, {-500, 'X'}};
  s21::map<int, char> map_tst_src = {
      {0, 'a'}, {1, '!'}, {500, 'a'}, {-500, 'X'}};
  s21::map<int, char> map_tst_dst = std::move(map_tst_src);
  s21::map<int, char>::iterator it = map_tst.begin();
  s21::map<int, char>::iterator it_dst = map_tst_dst.begin();
  for (; it != map_tst.end(); it++, it_dst++) ASSERT_EQ(*it, *it_dst);
}

TEST(s21_map_test, test_assign_constructor_3) {
  s21::map<double, int> map_tst = {
      {-123.456, 0}, {-0.0, 567}, {123.456, 10}, {0.0, 1}};
  s21::map<double, int> map_tst_src = {
      {-123.456, 0}, {-0.0, 567}, {123.456, 10}, {0.0, 1}};
  s21::map<double, int> map_tst_dst = std::move(map_tst_src);
  s21::map<double, int>::iterator it = map_tst.begin();
  s21::map<double, int>::iterator it_dst = map_tst_dst.begin();
  for (; it != map_tst.end(); it++, it_dst++) ASSERT_EQ(*it, *it_dst);
}

TEST(s21_map_test, test_assign_constructor_4) {
  s21::map<int, std::string> map_tst = {
      {1, "begin"}, {3, "123-2"}, {0, "wtf?"}, {-1, "END!"}};
  s21::map<int, std::string> map_tst_src = {
      {1, "begin"}, {3, "123-2"}, {0, "wtf?"}, {-1, "END!"}};
  s21::map<int, std::string> map_tst_dst = std::move(map_tst_src);
  s21::map<int, std::string>::iterator it = map_tst.begin();
  s21::map<int, std::string>::iterator it_dst = map_tst_dst.begin();
  for (; it != map_tst.end(); it++, it_dst++) ASSERT_EQ(*it, *it_dst);
}

TEST(s21_map_test, test_assign_constructor_5) {
  s21::map<std::string, double> map_tst = {{"begin", 342.212},
                                           {"123-2", 0.0},
                                           {"wtf?", -0.0},
                                           {"END!", 22301.222343123}};
  s21::map<std::string, double> map_tst_src = {{"begin", 342.212},
                                               {"123-2", 0.0},
                                               {"wtf?", -0.0},
                                               {"END!", 22301.222343123}};
  s21::map<std::string, double> map_tst_dst = std::move(map_tst_src);
  s21::map<std::string, double>::iterator it = map_tst.begin();
  s21::map<std::string, double>::iterator it_dst = map_tst_dst.begin();
  for (; it != map_tst.end(); it++, it_dst++) ASSERT_EQ(*it, *it_dst);
}

// =======================
// Test of insert_1
// =======================

TEST(s21_map_test, test_insert_1_1) {
  s21::map<char, char> map_tst = {
      {'a', 'a'}, {'b', 'z'}, {'e', 'x'}, {'x', 'z'}};
  std::map<char, char> map_std = {
      {'a', 'a'}, {'b', 'z'}, {'e', 'x'}, {'x', 'z'}};
  std::pair<s21::map<char, char>::iterator, bool> it_tst_result =
      map_tst.insert({'c', 'd'});
  std::pair<std::map<char, char>::iterator, bool> it_std_result =
      map_std.insert({'c', 'd'});
  ASSERT_EQ(it_tst_result.second, it_std_result.second);
  ASSERT_EQ(*(it_tst_result.first), *(it_std_result.first));

  s21::map<char, char>::iterator it_tst = map_tst.begin();
  std::map<char, char>::iterator it_std = map_std.begin();
  for (; it_tst != map_tst.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_map_test, test_insert_1_2) {
  s21::map<int, char> map_tst = {{0, 'a'}, {1, '!'}, {500, 'a'}, {-500, 'X'}};
  std::map<int, char> map_std = {{0, 'a'}, {1, '!'}, {500, 'a'}, {-500, 'X'}};
  std::pair<s21::map<int, char>::iterator, bool> it_tst_result =
      map_tst.insert({55, 'V'});
  std::pair<std::map<int, char>::iterator, bool> it_std_result =
      map_std.insert({55, 'V'});
  ASSERT_EQ(it_tst_result.second, it_std_result.second);
  ASSERT_EQ(*(it_tst_result.first), *(it_std_result.first));

  it_tst_result = map_tst.insert({500, 'r'});
  it_std_result = map_std.insert({500, 'r'});
  ASSERT_EQ(it_tst_result.second, it_std_result.second);
  ASSERT_EQ(*(it_tst_result.first), *(it_std_result.first));

  s21::map<int, char>::iterator it_tst = map_tst.begin();
  std::map<int, char>::iterator it_std = map_std.begin();
  for (; it_tst != map_tst.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_map_test, test_insert_1_3) {
  s21::map<double, int> map_tst = {
      {-123.456, 0}, {-0.0, 567}, {123.456, 10}, {0.0, 1}};
  std::map<double, int> map_std = {
      {-123.456, 0}, {-0.0, 567}, {123.456, 10}, {0.0, 1}};
  std::pair<s21::map<double, int>::iterator, bool> it_tst_result =
      map_tst.insert({123.4561, 32464});
  std::pair<std::map<double, int>::iterator, bool> it_std_result =
      map_std.insert({123.4561, 32464});
  ASSERT_EQ(it_tst_result.second, it_std_result.second);
  ASSERT_EQ(*(it_tst_result.first), *(it_std_result.first));

  it_tst_result = map_tst.insert({-123.456, 666});
  it_std_result = map_std.insert({-123.456, 666});
  ASSERT_EQ(it_tst_result.second, it_std_result.second);
  ASSERT_EQ(*(it_tst_result.first), *(it_std_result.first));

  s21::map<double, int>::iterator it_tst = map_tst.begin();
  std::map<double, int>::iterator it_std = map_std.begin();
  for (; it_tst != map_tst.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_map_test, test_insert_1_4) {
  s21::map<int, std::string> map_tst = {
      {1, "begin"}, {3, "123-2"}, {0, "wtf?"}, {-1, "END!"}};
  std::map<int, std::string> map_std = {
      {1, "begin"}, {3, "123-2"}, {0, "wtf?"}, {-1, "END!"}};
  std::pair<s21::map<int, std::string>::iterator, bool> it_tst_result =
      map_tst.insert({2, "xXx"});
  std::pair<std::map<int, std::string>::iterator, bool> it_std_result =
      map_std.insert({2, "xXx"});
  ASSERT_EQ(it_tst_result.second, it_std_result.second);
  ASSERT_EQ(*(it_tst_result.first), *(it_std_result.first));

  it_tst_result = map_tst.insert({2, "--> .!."});
  it_std_result = map_std.insert({2, "--> .!."});
  ASSERT_EQ(it_tst_result.second, it_std_result.second);
  ASSERT_EQ(*(it_tst_result.first), *(it_std_result.first));

  s21::map<int, std::string>::iterator it_tst = map_tst.begin();
  std::map<int, std::string>::iterator it_std = map_std.begin();
  for (; it_tst != map_tst.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_map_test, test_insert_1_5) {
  s21::map<std::string, double> map_tst = {{"begin", 342.212},
                                           {"123-2", 0.0},
                                           {"wtf?", -0.0},
                                           {"END!", 22301.222343123}};
  std::map<std::string, double> map_std = {{"begin", 342.212},
                                           {"123-2", 0.0},
                                           {"wtf?", -0.0},
                                           {"END!", 22301.222343123}};
  std::pair<s21::map<std::string, double>::iterator, bool> it_tst_result =
      map_tst.insert({"xXx", 23.11});
  std::pair<std::map<std::string, double>::iterator, bool> it_std_result =
      map_std.insert({"xXx", 23.11});
  ASSERT_EQ(it_tst_result.second, it_std_result.second);
  ASSERT_EQ(*(it_tst_result.first), *(it_std_result.first));

  it_tst_result = map_tst.insert({"123-2", 23.11});
  it_std_result = map_std.insert({"123-2", 23.11});
  ASSERT_EQ(it_tst_result.second, it_std_result.second);
  ASSERT_EQ(*(it_tst_result.first), *(it_std_result.first));

  s21::map<std::string, double>::iterator it_tst = map_tst.begin();
  std::map<std::string, double>::iterator it_std = map_std.begin();
  for (; it_tst != map_tst.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

// =======================
// Test of insert_2
// =======================

TEST(s21_map_test, test_insert_2_1) {
  s21::map<char, char> map_tst = {
      {'a', 'a'}, {'b', 'z'}, {'e', 'x'}, {'x', 'z'}};

  std::pair<s21::map<char, char>::iterator, bool> it_tst_result =
      map_tst.insert('c', 'd');
  ASSERT_EQ(it_tst_result.second, true);
  it_tst_result = map_tst.insert('e', 'f');
  ASSERT_EQ(it_tst_result.second, false);

  ASSERT_EQ(map_tst.contains('a'), true);
  ASSERT_EQ(map_tst.at('a'), 'a');
  ASSERT_EQ(map_tst['a'], 'a');
  ASSERT_EQ(map_tst.contains('b'), true);
  ASSERT_EQ(map_tst.at('b'), 'z');
  ASSERT_EQ(map_tst['b'], 'z');
  ASSERT_EQ(map_tst.contains('c'), true);
  ASSERT_EQ(map_tst.at('c'), 'd');
  ASSERT_EQ(map_tst['c'], 'd');
  ASSERT_EQ(map_tst.contains('e'), true);
  ASSERT_EQ(map_tst.at('e'), 'x');
  ASSERT_EQ(map_tst['e'], 'x');
  ASSERT_EQ(map_tst.contains('x'), true);
  ASSERT_EQ(map_tst.at('x'), 'z');
  ASSERT_EQ(map_tst['x'], 'z');
  ASSERT_EQ(map_tst.contains('d'), false);
  ASSERT_EQ(map_tst.contains('i'), false);
}

TEST(s21_map_test, test_insert_2_2) {
  s21::map<int, char> map_tst = {{0, 'a'}, {1, '!'}, {500, 'a'}, {-500, 'X'}};

  std::pair<s21::map<int, char>::iterator, bool> it_tst_result =
      map_tst.insert(55, 'V');
  ASSERT_EQ(it_tst_result.second, true);
  it_tst_result = map_tst.insert(500, 'r');
  ASSERT_EQ(it_tst_result.second, false);

  ASSERT_EQ(map_tst.contains(0), true);
  ASSERT_EQ(map_tst.at(0), 'a');
  ASSERT_EQ(map_tst[0], 'a');
  ASSERT_EQ(map_tst.contains(1), true);
  ASSERT_EQ(map_tst.at(1), '!');
  ASSERT_EQ(map_tst[1], '!');
  ASSERT_EQ(map_tst.contains(55), true);
  ASSERT_EQ(map_tst.at(55), 'V');
  ASSERT_EQ(map_tst[55], 'V');
  ASSERT_EQ(map_tst.contains(500), true);
  ASSERT_EQ(map_tst.at(500), 'a');
  ASSERT_EQ(map_tst[500], 'a');
  ASSERT_EQ(map_tst.contains(-500), true);
  ASSERT_EQ(map_tst.at(-500), 'X');
  ASSERT_EQ(map_tst[-500], 'X');
  ASSERT_EQ(map_tst.contains(1000), false);
  ASSERT_EQ(map_tst.contains(-1), false);
}

TEST(s21_map_test, test_insert_2_3) {
  s21::map<double, int> map_tst = {
      {-123.456, 0}, {-0.0, 567}, {123.456, 10}, {0.0, 1}};

  std::pair<s21::map<double, int>::iterator, bool> it_tst_result =
      map_tst.insert(123.4561, 32464);
  ASSERT_EQ(it_tst_result.second, true);
  it_tst_result = map_tst.insert(-123.456, 666);
  ASSERT_EQ(it_tst_result.second, false);

  ASSERT_EQ(map_tst.contains(-123.456), true);
  ASSERT_EQ(map_tst.at(-123.456), 0);
  ASSERT_EQ(map_tst[-123.456], 0);
  ASSERT_EQ(map_tst.contains(-0.0), true);
  ASSERT_EQ(map_tst.at(-0.0), 567);
  ASSERT_EQ(map_tst[-0.0], 567);
  ASSERT_EQ(map_tst.contains(123.456), true);
  ASSERT_EQ(map_tst.at(123.456), 10);
  ASSERT_EQ(map_tst[123.456], 10);
  ASSERT_EQ(map_tst.contains(123.4561), true);
  ASSERT_EQ(map_tst.at(123.4561), 32464);
  ASSERT_EQ(map_tst[123.4561], 32464);
  ASSERT_EQ(map_tst.contains(2.9), false);
  ASSERT_EQ(map_tst.contains(-1.0), false);
}

TEST(s21_map_test, test_insert_2_4) {
  s21::map<int, std::string> map_tst = {
      {1, "begin"}, {3, "123-2"}, {0, "wtf?"}, {-1, "END!"}};

  std::pair<s21::map<int, std::string>::iterator, bool> it_tst_result =
      map_tst.insert(2, "xXx");
  ASSERT_EQ(it_tst_result.second, true);
  it_tst_result = map_tst.insert(2, "yYy");
  ASSERT_EQ(it_tst_result.second, false);

  ASSERT_EQ(map_tst.contains(-1), true);
  ASSERT_EQ(map_tst.at(-1), "END!");
  ASSERT_EQ(map_tst[-1], "END!");
  ASSERT_EQ(map_tst.contains(0), true);
  ASSERT_EQ(map_tst.at(0), "wtf?");
  ASSERT_EQ(map_tst[0], "wtf?");
  ASSERT_EQ(map_tst.contains(1), true);
  ASSERT_EQ(map_tst.at(1), "begin");
  ASSERT_EQ(map_tst[1], "begin");
  ASSERT_EQ(map_tst.contains(2), true);
  ASSERT_EQ(map_tst.at(2), "xXx");
  ASSERT_EQ(map_tst[2], "xXx");
  ASSERT_EQ(map_tst.contains(3), true);
  ASSERT_EQ(map_tst.at(3), "123-2");
  ASSERT_EQ(map_tst[3], "123-2");
  ASSERT_EQ(map_tst.contains(6), false);
  ASSERT_EQ(map_tst.contains(9), false);
}

TEST(s21_map_test, test_insert_2_5) {
  s21::map<std::string, double> map_tst = {{"begin", 342.212},
                                           {"123-2", 0.0},
                                           {"wtf?", -0.0},
                                           {"END!", 22301.222343123}};

  std::pair<s21::map<std::string, double>::iterator, bool> it_tst_result =
      map_tst.insert("xXx", 23.11);
  ASSERT_EQ(it_tst_result.second, true);
  it_tst_result = map_tst.insert("xXx", 25.52);
  ASSERT_EQ(it_tst_result.second, false);

  ASSERT_EQ(map_tst.contains("123-2"), true);
  ASSERT_EQ(map_tst.at("123-2"), 0.0);
  ASSERT_EQ(map_tst["123-2"], 0.0);
  ASSERT_EQ(map_tst.contains("begin"), true);
  ASSERT_EQ(map_tst.at("begin"), 342.212);
  ASSERT_EQ(map_tst["begin"], 342.212);
  ASSERT_EQ(map_tst.contains("END!"), true);
  ASSERT_EQ(map_tst.at("END!"), 22301.222343123);
  ASSERT_EQ(map_tst["END!"], 22301.222343123);
  ASSERT_EQ(map_tst.contains("wtf?"), true);
  ASSERT_EQ(map_tst.at("wtf?"), -0.0);
  ASSERT_EQ(map_tst["wtf?"], -0.0);
  ASSERT_EQ(map_tst.contains("xXx"), true);
  ASSERT_EQ(map_tst.at("xXx"), 23.11);
  ASSERT_EQ(map_tst["xXx"], 23.11);
  ASSERT_EQ(map_tst.contains("yYy"), false);
  ASSERT_EQ(map_tst.contains("---"), false);
}

// =======================
// Test of insert_or_assign
// =======================

TEST(s21_map_test, test_insert_or_assign_1) {
  s21::map<char, char> map_tst = {
      {'a', 'a'}, {'b', 'z'}, {'e', 'x'}, {'x', 'z'}};

  std::pair<s21::map<char, char>::iterator, bool> it_tst_result =
      map_tst.insert_or_assign('c', 'd');
  ASSERT_EQ(it_tst_result.second, true);
  it_tst_result = map_tst.insert_or_assign('e', 'f');
  ASSERT_EQ(it_tst_result.second, false);

  ASSERT_EQ(map_tst.contains('a'), true);
  ASSERT_EQ(map_tst.at('a'), 'a');
  ASSERT_EQ(map_tst['a'], 'a');
  ASSERT_EQ(map_tst.contains('b'), true);
  ASSERT_EQ(map_tst.at('b'), 'z');
  ASSERT_EQ(map_tst['b'], 'z');
  ASSERT_EQ(map_tst.contains('c'), true);
  ASSERT_EQ(map_tst.at('c'), 'd');
  ASSERT_EQ(map_tst['c'], 'd');
  ASSERT_EQ(map_tst.contains('e'), true);
  ASSERT_EQ(map_tst.at('e'), 'f');
  ASSERT_EQ(map_tst['e'], 'f');
  ASSERT_EQ(map_tst.contains('x'), true);
  ASSERT_EQ(map_tst.at('x'), 'z');
  ASSERT_EQ(map_tst['x'], 'z');
  ASSERT_EQ(map_tst.contains('d'), false);
  ASSERT_EQ(map_tst.contains('i'), false);
}

TEST(s21_map_test, test_insert_or_assign_2) {
  s21::map<int, char> map_tst = {{0, 'a'}, {1, '!'}, {500, 'a'}, {-500, 'X'}};

  std::pair<s21::map<int, char>::iterator, bool> it_tst_result =
      map_tst.insert_or_assign(55, 'V');
  ASSERT_EQ(it_tst_result.second, true);
  it_tst_result = map_tst.insert_or_assign(500, 'r');
  ASSERT_EQ(it_tst_result.second, false);

  ASSERT_EQ(map_tst.contains(0), true);
  ASSERT_EQ(map_tst.at(0), 'a');
  ASSERT_EQ(map_tst[0], 'a');
  ASSERT_EQ(map_tst.contains(1), true);
  ASSERT_EQ(map_tst.at(1), '!');
  ASSERT_EQ(map_tst[1], '!');
  ASSERT_EQ(map_tst.contains(55), true);
  ASSERT_EQ(map_tst.at(55), 'V');
  ASSERT_EQ(map_tst[55], 'V');
  ASSERT_EQ(map_tst.contains(500), true);
  ASSERT_EQ(map_tst.at(500), 'r');
  ASSERT_EQ(map_tst[500], 'r');
  ASSERT_EQ(map_tst.contains(-500), true);
  ASSERT_EQ(map_tst.at(-500), 'X');
  ASSERT_EQ(map_tst[-500], 'X');
  ASSERT_EQ(map_tst.contains(1000), false);
  ASSERT_EQ(map_tst.contains(-1), false);
}

TEST(s21_map_test, test_insert_or_assign_3) {
  s21::map<double, int> map_tst = {
      {-123.456, 0}, {-0.0, 567}, {123.456, 10}, {0.0, 1}};

  std::pair<s21::map<double, int>::iterator, bool> it_tst_result =
      map_tst.insert_or_assign(123.4561, 32464);
  ASSERT_EQ(it_tst_result.second, true);
  it_tst_result = map_tst.insert_or_assign(-123.456, 666);
  ASSERT_EQ(it_tst_result.second, false);

  ASSERT_EQ(map_tst.contains(-123.456), true);
  ASSERT_EQ(map_tst.at(-123.456), 666);
  ASSERT_EQ(map_tst[-123.456], 666);
  ASSERT_EQ(map_tst.contains(-0.0), true);
  ASSERT_EQ(map_tst.at(-0.0), 567);
  ASSERT_EQ(map_tst[-0.0], 567);
  ASSERT_EQ(map_tst.contains(123.456), true);
  ASSERT_EQ(map_tst.at(123.456), 10);
  ASSERT_EQ(map_tst[123.456], 10);
  ASSERT_EQ(map_tst.contains(123.4561), true);
  ASSERT_EQ(map_tst.at(123.4561), 32464);
  ASSERT_EQ(map_tst[123.4561], 32464);
  ASSERT_EQ(map_tst.contains(2.9), false);
  ASSERT_EQ(map_tst.contains(-1.0), false);
}

TEST(s21_map_test, test_insert_or_assign_4) {
  s21::map<int, std::string> map_tst = {
      {1, "begin"}, {3, "123-2"}, {0, "wtf?"}, {-1, "END!"}};

  std::pair<s21::map<int, std::string>::iterator, bool> it_tst_result =
      map_tst.insert_or_assign(2, "xXx");
  ASSERT_EQ(it_tst_result.second, true);
  it_tst_result = map_tst.insert_or_assign(2, "yYy");
  ASSERT_EQ(it_tst_result.second, false);

  ASSERT_EQ(map_tst.contains(-1), true);
  ASSERT_EQ(map_tst.at(-1), "END!");
  ASSERT_EQ(map_tst[-1], "END!");
  ASSERT_EQ(map_tst.contains(0), true);
  ASSERT_EQ(map_tst.at(0), "wtf?");
  ASSERT_EQ(map_tst[0], "wtf?");
  ASSERT_EQ(map_tst.contains(1), true);
  ASSERT_EQ(map_tst.at(1), "begin");
  ASSERT_EQ(map_tst[1], "begin");
  ASSERT_EQ(map_tst.contains(2), true);
  ASSERT_EQ(map_tst.at(2), "yYy");
  ASSERT_EQ(map_tst[2], "yYy");
  ASSERT_EQ(map_tst.contains(3), true);
  ASSERT_EQ(map_tst.at(3), "123-2");
  ASSERT_EQ(map_tst[3], "123-2");
  ASSERT_EQ(map_tst.contains(6), false);
  ASSERT_EQ(map_tst.contains(9), false);
}

TEST(s21_map_test, test_insert_or_assign_5) {
  s21::map<std::string, double> map_tst = {{"begin", 342.212},
                                           {"123-2", 0.0},
                                           {"wtf?", -0.0},
                                           {"END!", 22301.222343123}};

  std::pair<s21::map<std::string, double>::iterator, bool> it_tst_result =
      map_tst.insert_or_assign("xXx", 23.11);
  ASSERT_EQ(it_tst_result.second, true);
  it_tst_result = map_tst.insert_or_assign("xXx", 25.52);
  ASSERT_EQ(it_tst_result.second, false);

  ASSERT_EQ(map_tst.contains("123-2"), true);
  ASSERT_EQ(map_tst.at("123-2"), 0.0);
  ASSERT_EQ(map_tst["123-2"], 0.0);
  ASSERT_EQ(map_tst.contains("begin"), true);
  ASSERT_EQ(map_tst.at("begin"), 342.212);
  ASSERT_EQ(map_tst["begin"], 342.212);
  ASSERT_EQ(map_tst.contains("END!"), true);
  ASSERT_EQ(map_tst.at("END!"), 22301.222343123);
  ASSERT_EQ(map_tst["END!"], 22301.222343123);
  ASSERT_EQ(map_tst.contains("wtf?"), true);
  ASSERT_EQ(map_tst.at("wtf?"), -0.0);
  ASSERT_EQ(map_tst["wtf?"], -0.0);
  ASSERT_EQ(map_tst.contains("xXx"), true);
  ASSERT_EQ(map_tst.at("xXx"), 25.52);
  ASSERT_EQ(map_tst["xXx"], 25.52);
  ASSERT_EQ(map_tst.contains("yYy"), false);
  ASSERT_EQ(map_tst.contains("---"), false);
}

// =======================
// Test of erase
// =======================

TEST(s21_map_test, test_erase_1) {
  s21::map<char, char> map_tst = {
      {'a', 'a'}, {'b', 'z'}, {'e', 'x'}, {'x', 'z'}};
  std::map<char, char> map_std = {
      {'a', 'a'}, {'b', 'z'}, {'e', 'x'}, {'x', 'z'}};
  s21::map<char, char>::iterator it_tst_temp = map_tst.begin();
  std::map<char, char>::iterator it_std_temp = map_std.begin();
  map_tst.erase(it_tst_temp);
  map_std.erase(it_std_temp);

  s21::map<char, char>::iterator it_tst = map_tst.begin();
  std::map<char, char>::iterator it_std = map_std.begin();
  for (; it_tst != map_tst.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_map_test, test_erase_2) {
  s21::map<int, char> map_tst = {{0, 'a'}, {1, '!'}, {500, 'a'}, {-500, 'X'}};
  std::map<int, char> map_std = {{0, 'a'}, {1, '!'}, {500, 'a'}, {-500, 'X'}};
  s21::map<int, char>::iterator it_tst_temp = map_tst.end();
  std::map<int, char>::iterator it_std_temp = map_std.end();
  it_tst_temp--;
  it_std_temp--;
  map_tst.erase(it_tst_temp);
  map_std.erase(it_std_temp);

  s21::map<int, char>::iterator it_tst = map_tst.begin();
  std::map<int, char>::iterator it_std = map_std.begin();
  for (; it_tst != map_tst.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_map_test, test_erase_3) {
  s21::map<double, int> map_tst = {
      {-123.456, 0}, {-0.0, 567}, {123.456, 10}, {0.0, 1}};
  std::map<double, int> map_std = {
      {-123.456, 0}, {-0.0, 567}, {123.456, 10}, {0.0, 1}};
  s21::map<double, int>::iterator it_tst_in = map_tst.begin();
  std::map<double, int>::iterator it_std_in = map_std.begin();
  for (int i = 0; i < 2; i++) it_tst_in++;
  for (int i = 0; i < 2; i++) it_std_in++;
  map_tst.erase(it_tst_in);
  map_std.erase(it_std_in);

  s21::map<double, int>::iterator it_tst = map_tst.begin();
  std::map<double, int>::iterator it_std = map_std.begin();
  for (; it_tst != map_tst.end(); it_tst++, it_std++) {
    ASSERT_EQ(*it_tst, *it_std);
  }
}

TEST(s21_map_test, test_erase_4) {
  s21::map<int, std::string> map_tst = {{1, "begin"}};
  std::map<int, std::string> map_std = {{1, "begin"}};
  s21::map<int, std::string>::iterator it_tst_temp = map_tst.begin();
  std::map<int, std::string>::iterator it_std_temp = map_std.begin();
  map_tst.erase(it_tst_temp);
  map_std.erase(it_std_temp);
  ASSERT_EQ(map_tst.empty(), map_std.empty());
}

TEST(s21_map_test, test_erase_5) {
  s21::map<std::string, double> map_tst = {{"begin", 342.212},
                                           {"123-2", 0.0},
                                           {"wtf?", -0.0},
                                           {"END!", 22301.222343123}};
  std::map<std::string, double> map_std = {{"begin", 342.212},
                                           {"123-2", 0.0},
                                           {"wtf?", -0.0},
                                           {"END!", 22301.222343123}};
  s21::map<std::string, double>::iterator it_tst_in = map_tst.begin();
  std::map<std::string, double>::iterator it_std_in = map_std.begin();
  for (int i = 0; i < 2; i++) it_tst_in++;
  for (int i = 0; i < 2; i++) it_std_in++;
  map_tst.erase(it_tst_in);
  map_std.erase(it_std_in);

  s21::map<std::string, double>::iterator it_tst = map_tst.begin();
  std::map<std::string, double>::iterator it_std = map_std.begin();
  for (; it_tst != map_tst.end(); it_tst++, it_std++) {
    ASSERT_EQ(*it_tst, *it_std);
  }
}

// =======================
// Test of merge
// =======================

TEST(s21_map_test, test_merge_1) {
  s21::map<char, char> map_tst_1 = {
      {'a', 'a'}, {'b', 'z'}, {'e', 'x'}, {'x', 'z'}};
  s21::map<char, char> map_tst_2;
  std::map<char, char> map_std_1 = {
      {'a', 'a'}, {'b', 'z'}, {'e', 'x'}, {'x', 'z'}};
  std::map<char, char> map_std_2;
  map_tst_1.merge(map_tst_2);
  map_std_1.merge(map_std_2);

  s21::map<char, char>::iterator it_tst = map_tst_1.begin();
  std::map<char, char>::iterator it_std = map_std_1.begin();
  for (; it_tst != map_tst_1.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_map_test, test_merge_2) {
  s21::map<int, char> map_tst_1;
  s21::map<int, char> map_tst_2 = {{0, 'a'}, {1, '!'}, {500, 'a'}, {-500, 'X'}};
  std::map<int, char> map_std_1;
  std::map<int, char> map_std_2 = {{0, 'a'}, {1, '!'}, {500, 'a'}, {-500, 'X'}};
  map_tst_1.merge(map_tst_2);
  map_std_1.merge(map_std_2);

  s21::map<int, char>::iterator it_tst = map_tst_1.begin();
  std::map<int, char>::iterator it_std = map_std_1.begin();
  for (; it_tst != map_tst_1.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_map_test, test_merge_3) {
  s21::map<double, int> map_tst_1 = {
      {-123.456, 0}, {-0.0, 567}, {123.456, 10}, {1.1, 1}};
  s21::map<double, int> map_tst_2 = {{12.23543, 96}};
  std::map<double, int> map_std_1 = {
      {-123.456, 0}, {-0.0, 567}, {123.456, 10}, {1.1, 1}};
  std::map<double, int> map_std_2 = {{12.23543, 96}};
  map_tst_1.merge(map_tst_2);
  map_std_1.merge(map_std_2);

  s21::map<double, int>::iterator it_tst = map_tst_1.begin();
  std::map<double, int>::iterator it_std = map_std_1.begin();
  for (; it_tst != map_tst_1.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_map_test, test_merge_4) {
  s21::map<int, std::string> map_tst_1 = {
      {1, "begin"}, {3, "123-2"}, {0, "wtf?"}, {-1, "END!"}};
  std::map<int, std::string> map_std_1 = {
      {1, "begin"}, {3, "123-2"}, {0, "wtf?"}, {-1, "END!"}};
  map_tst_1.merge(map_tst_1);
  map_std_1.merge(map_std_1);

  s21::map<int, std::string>::iterator it_tst = map_tst_1.begin();
  std::map<int, std::string>::iterator it_std = map_std_1.begin();
  for (; it_tst != map_tst_1.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_map_test, test_merge_5) {
  s21::map<std::string, double> map_tst_1 = {{"begin", 342.212},
                                             {"123-2", 0.0},
                                             {"wtf?", -0.0},
                                             {"END!", 22301.222343123}};
  s21::map<std::string, double> map_tst_2 = {{"few", 12.23543},
                                             {"fop21", 0.18792}};
  std::map<std::string, double> map_std_1 = {{"begin", 342.212},
                                             {"123-2", 0.0},
                                             {"wtf?", -0.0},
                                             {"END!", 22301.222343123}};
  std::map<std::string, double> map_std_2 = {{"few", 12.23543},
                                             {"fop21", 0.18792}};
  map_tst_1.merge(map_tst_2);
  map_std_1.merge(map_std_2);

  s21::map<std::string, double>::iterator it_tst = map_tst_1.begin();
  std::map<std::string, double>::iterator it_std = map_std_1.begin();
  for (; it_tst != map_tst_1.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

// =======================
// Test of swap
// =======================

TEST(s21_map_test, test_swap_1) {
  s21::map<char, char> map_tst_1 = {
      {'a', 'a'}, {'b', 'z'}, {'e', 'x'}, {'x', 'z'}};
  s21::map<char, char> map_tst_2;
  std::map<char, char> map_std_1 = {
      {'a', 'a'}, {'b', 'z'}, {'e', 'x'}, {'x', 'z'}};
  std::map<char, char> map_std_2;
  map_tst_1.swap(map_tst_2);
  map_std_1.swap(map_std_2);
  s21::map<char, char>::iterator it_tst_1 = map_tst_1.begin();
  std::map<char, char>::iterator it_std_1 = map_std_1.begin();
  for (; it_tst_1 != map_tst_1.end(); it_tst_1++, it_std_1++)
    ASSERT_EQ(*it_tst_1, *it_std_1);

  s21::map<char, char>::iterator it_tst_2 = map_tst_2.begin();
  std::map<char, char>::iterator it_std_2 = map_std_2.begin();
  for (; it_tst_2 != map_tst_2.end(); it_tst_2++, it_std_2++)
    ASSERT_EQ(*it_tst_2, *it_std_2);
}

TEST(s21_map_test, test_swap_2) {
  s21::map<int, char> map_tst_1;
  s21::map<int, char> map_tst_2 = {{0, 'a'}, {1, '!'}, {500, 'a'}, {-500, 'X'}};
  std::map<int, char> map_std_1;
  std::map<int, char> map_std_2 = {{0, 'a'}, {1, '!'}, {500, 'a'}, {-500, 'X'}};
  map_tst_1.swap(map_tst_2);
  map_std_1.swap(map_std_2);
  s21::map<int, char>::iterator it_tst_1 = map_tst_1.begin();
  std::map<int, char>::iterator it_std_1 = map_std_1.begin();
  for (; it_tst_1 != map_tst_1.end(); it_tst_1++, it_std_1++)
    ASSERT_EQ(*it_tst_1, *it_std_1);

  s21::map<int, char>::iterator it_tst_2 = map_tst_2.begin();
  std::map<int, char>::iterator it_std_2 = map_std_2.begin();
  for (; it_tst_2 != map_tst_2.end(); it_tst_2++, it_std_2++)
    ASSERT_EQ(*it_tst_2, *it_std_2);
}

TEST(s21_map_test, test_swap_3) {
  s21::map<double, int> map_tst_1 = {
      {-123.456, 0}, {-0.0, 567}, {123.456, 10}, {1.1, 1}};
  s21::map<double, int> map_tst_2 = {{12.23543, 96}};
  std::map<double, int> map_std_1 = {
      {-123.456, 0}, {-0.0, 567}, {123.456, 10}, {1.1, 1}};
  std::map<double, int> map_std_2 = {{12.23543, 96}};
  map_tst_1.swap(map_tst_2);
  map_std_1.swap(map_std_2);
  s21::map<double, int>::iterator it_tst_1 = map_tst_1.begin();
  std::map<double, int>::iterator it_std_1 = map_std_1.begin();
  for (; it_tst_1 != map_tst_1.end(); it_tst_1++, it_std_1++)
    ASSERT_EQ(*it_tst_1, *it_std_1);

  s21::map<double, int>::iterator it_tst_2 = map_tst_2.begin();
  std::map<double, int>::iterator it_std_2 = map_std_2.begin();
  for (; it_tst_2 != map_tst_2.end(); it_tst_2++, it_std_2++)
    ASSERT_EQ(*it_tst_2, *it_std_2);
}

TEST(s21_map_test, test_swap_4) {
  s21::map<int, std::string> map_tst_1 = {
      {1, "begin"}, {3, "123-2"}, {0, "wtf?"}, {-1, "END!"}};
  std::map<int, std::string> map_std_1 = {
      {1, "begin"}, {3, "123-2"}, {0, "wtf?"}, {-1, "END!"}};
  map_tst_1.swap(map_tst_1);
  map_std_1.swap(map_std_1);

  s21::map<int, std::string>::iterator it_tst = map_tst_1.begin();
  std::map<int, std::string>::iterator it_std = map_std_1.begin();
  for (; it_tst != map_tst_1.end(); it_tst++, it_std++)
    ASSERT_EQ(*it_tst, *it_std);
}

TEST(s21_map_test, test_swap_5) {
  s21::map<std::string, double> map_tst_1 = {{"begin", 342.212},
                                             {"123-2", 0.0},
                                             {"wtf?", -0.0},
                                             {"END!", 22301.222343123}};
  s21::map<std::string, double> map_tst_2 = {{"few", 12.23543},
                                             {"fop21", 0.18792}};
  std::map<std::string, double> map_std_1 = {{"begin", 342.212},
                                             {"123-2", 0.0},
                                             {"wtf?", -0.0},
                                             {"END!", 22301.222343123}};
  std::map<std::string, double> map_std_2 = {{"few", 12.23543},
                                             {"fop21", 0.18792}};
  map_tst_1.swap(map_tst_2);
  map_std_1.swap(map_std_2);
  s21::map<std::string, double>::iterator it_tst_1 = map_tst_1.begin();
  std::map<std::string, double>::iterator it_std_1 = map_std_1.begin();
  for (; it_tst_1 != map_tst_1.end(); it_tst_1++, it_std_1++)
    ASSERT_EQ(*it_tst_1, *it_std_1);

  s21::map<std::string, double>::iterator it_tst_2 = map_tst_2.begin();
  std::map<std::string, double>::iterator it_std_2 = map_std_2.begin();
  for (; it_tst_2 != map_tst_2.end(); it_tst_2++, it_std_2++)
    ASSERT_EQ(*it_tst_2, *it_std_2);
}