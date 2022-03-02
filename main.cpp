#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1055;

/*
Example 1:
Input: source = “abc”, target = “abcbc”
Output: 2
Explanation: The target “abcbc” can be formed by “abc” and “bc”,
which are subsequences of source “abc”.
*/
tuple<string, string, int>
testFixture1()
{
  return make_tuple("abc", "abcbc", 2);
}

/*
Example 2:
Input: source = “abc”, target = “acdbc”
Output: -1
Explanation: The target string cannot be constructed
from the subsequences of source string due to the
character “d” in target string.
*/
tuple<string, string, int>
testFixture2()
{
  return make_tuple("abc", "acdbc", -1);
}

/*
Example 3:
Input: source = “xyz”, target = “xzyxz”
Output: 3
Explanation: The target string can be constructed as follows “xz” + “y” + “xz”.
*/
tuple<string, string, int>
testFixture3()
{
  return make_tuple("xyz", "xzyxz", 3);
}

tuple<string, string, int>
testFixture4()
{
  return make_tuple("abcde", "abce", 1);
}

void test1()
{
  auto f = testFixture1();
  auto s = get<0>(f);
  auto t = get<1>(f);
  cout << "Test 1 - exepct to see " << to_string(get<2>(f)) << endl;
  auto result = Solution::shortestWay(get<0>(f), get<1>(f));
  cout << "result: " << to_string(result) << endl;
}

void test2()
{
  auto f = testFixture2();
  auto s = get<0>(f);
  auto t = get<1>(f);
  cout << "Test 2 - exepct to see " << to_string(get<2>(f)) << endl;
  auto result = Solution::shortestWay(get<0>(f), get<1>(f));
  cout << "result: " << to_string(result) << endl;
}

void test3()
{
  auto f = testFixture3();
  auto s = get<0>(f);
  auto t = get<1>(f);
  cout << "Test 1 - exepct to see " << to_string(get<2>(f)) << endl;
  auto result = Solution::shortestWay(get<0>(f), get<1>(f));
  cout << "result: " << to_string(result) << endl;
}

void test4()
{
  auto f = testFixture4();
  auto s = get<0>(f);
  auto t = get<1>(f);
  cout << "Test 1 - exepct to see " << to_string(get<2>(f)) << endl;
  auto result = Solution::shortestWay(get<0>(f), get<1>(f));
  cout << "result: " << to_string(result) << endl;
}

main()
{
  test1();
  test2();
  test3();
  test4();
  return 0;
}