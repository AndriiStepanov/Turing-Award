#ifndef problem_h
#define problem_h

#include "lib.hpp"

struct Problem {

  const std::string prefix;
  const std::pair<size_t, size_t> range;
  void (*solve_ptr)(std::istream&, std::ostream&);

  using TestFiles = std::pair<std::string, std::string>;
  auto inputs() const -> std::vector<TestFiles>;

  void solve(std::istream& in, std::ostream& out) const;
  auto check(std::istream& sol, std::ostream& judge) -> bool;

};

void Problem::solve(std::istream &in, std::ostream &out) const {
  solve_ptr(in, out);
}

auto Problem::inputs() const -> std::vector<TestFiles> {
  const size_t all_digits = [max = range.second]() {
    size_t answer = 0;
    for (size_t x = max; x > 0; ++answer, x /= 10) { continue; }
    return answer;
  }();

  auto fixed_length = [all_digits](int number) -> std::string {
    std::string base = std::to_string(number);
    for (; base.size() < all_digits; base = "0" + base) { continue; }
    return base;
  };

  std::vector<TestFiles> files;
  for (size_t test_num = range.first; test_num <= range.second; ++test_num) {
    std::string base_filename = prefix + fixed_length(test_num);
    files.push_back({
      "in/" +  base_filename + ".in",
      "out/" + base_filename + ".out",
    });
  }

  return files;
}

#endif /* problem_h */
