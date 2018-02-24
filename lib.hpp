#ifndef LIB
#define LIB

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")

#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

    // C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#define all(v) (v).begin(), (v).end()
#define uniq(v) sort(all(v)); v.resize(unique(all(v)) - v.begin())

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;

inline double clocks() { return clock() * 1.0 / CLOCKS_PER_SEC; }
inline int system(const std::string str) { return system(str.c_str()); }

template<class T1, class T2>
std::ostream &operator<<(std::ostream &out, const std::pair<T1, T2> &a) {
  out << "(" << a.first << "," << a.second << ")";
  return out;
}

template<class T1, class T2>
std::istream& operator >> (std::istream& in, std::pair<T1, T2>& p) {
  return in >> p.first >> p.second;
}

template<class T1, class T2>
std::ostream &operator<<(std::ostream &out, const std::vector<T1, T2> &a) {
  bool f = 0;
  out << "[";
  for (auto &x : a) {
    if (f) out << ",";
    f = 1;
    out << x;
  }
  out << "]";
  return out;
}

template<class T1, class T2>
std::istream& operator >> (std::istream& in, std::vector<T1, T2>& a) {
  for (int i = 0; i < a.size(); i++) {
    in >> a[i];
  }
  return in;
}

template<class T1, class T2>
std::ostream &operator<<(std::ostream &out, const std::set<T1, T2> &a) {
  bool f = 0;
  out << "{";
  for (auto &x : a) {
    if (f) out << ",";
    f = 1;
    out << x;
  }
  out << "}";
  return out;
}

template<class T1, class T2>
std::ostream &operator<<(std::ostream &out, const std::multiset<T1, T2> &v) {
  bool f = 1;
  out << "[";
  for (auto &i : v) {
    if (!f)out << ", ";
    out << i;
    f = 0;
  }
  return out << "]";
}

template<class T1, class T2>
std::ostream &operator<<(std::ostream &out, std::priority_queue<T1, T2> v) {
  bool f = 1;
  out << "[";
  while (!v.empty()) {
    auto x = v.top();
    v.pop();
    if (!f) out << ", ";
    f = 0;
    out << x;
  }
  return out << "]";
}

template<class T1, class T2, class T3>
std::ostream &operator<<(std::ostream &out, const std::map<T1, T2, T3> &a) {
  bool f = 0;
  out << "{";
  for (auto &x : a) {
    if (f) out << ",";
    f = 1;
    out << x.first << ":" << x.second;
  }
  out << "}";
  return out;
}

template<class T1, class T2>
std::ostream &operator<<(std::ostream &out, const std::multimap<T1, T2> &v) {
  bool f = 1;
  out << "[";
  for (auto &ii : v) {
    if (!f)out << ", ";
    out << "(" << ii.first << " -> " << ii.second << ") ";
    f = 0;
  }
  return out << "]";
}

#endif
