#ifndef LIB
#define LIB
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define uniq(v) sort(all(v)); v.resize(unique(all(v)) - v.begin())

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
inline double clocks() { return clock() * 1.0 / CLOCKS_PER_SEC; }

template<class T1, class T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &a) {
  out << "(" << a.first << "," << a.second << ")";
  return out;
}

template<class T1, class T2>
istream &operator>>(istream &in, pair<T1, T2> &p) {
  return in >> p.first >> p.second;
}

template<class T1, class T2>
ostream &operator<<(ostream &out, const vector<T1, T2> &a) {
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
istream &operator>>(istream &in, vector<T1, T2> &a) {
  for (int i = 0; i < a.size(); i++) {
    in >> a[i];
  }
  return in;
}

template<class T1, class T2>
ostream &operator<<(ostream &out, const set<T1, T2> &a) {
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
ostream &operator<<(ostream &out, const multiset<T1, T2> &v) {
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
ostream &operator<<(ostream &out, priority_queue<T1, T2> v) {
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
ostream &operator<<(ostream &out, const map<T1, T2, T3> &a) {
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
ostream &operator<<(ostream &out, const multimap<T1, T2> &v) {
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
