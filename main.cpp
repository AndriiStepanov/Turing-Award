#include "lib.hpp"
#include "config.hpp"
#include "test_lib.hpp"
#include "problem.hpp"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Problem a{ "row", { 1, 10 }, A::solve };
  Problem b{ "election", { 1, 0 }, B::solve };
  Problem c{ "crossword", { 1, 0 }, C::solve };
  Problem d{ "legacy", { 1, 0 }, D::solve };
  Problem e{ "rocks", { 1, 0 }, E::solve };

  run_tests({a, b, c, d, e});

  return 0;
}
