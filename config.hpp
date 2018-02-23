#ifndef CONFIG
#define CONFIG
#include "lib.hpp"
#include "test_lib.hpp"

namespace A {
#include "sources/A.cpp"
};
namespace B {
#include "sources/B.cpp"
};
namespace C {
#include "sources/C.cpp"
};
namespace D {
#include "sources/D.cpp"
};
namespace E {
#include "sources/E.cpp"
};

const std::vector<Problem> all_problems{
  { "row", { 1, 10 }, A::solve },
  { "election", { 1, 0 }, B::solve },
  { "crossword", { 1, 0 }, C::solve },
  { "legacy", { 1, 0 }, D::solve },
  { "rocks", { 1, 0 }, E::solve },
};
#endif
