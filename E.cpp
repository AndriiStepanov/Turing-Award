#include "task.hpp"

const vector<string> test_inputs { "e001.in" };

void solve(std::istream& in, std::ostream& out) {
    int x, y;
    in >> x >> y;
    out << x ^ y;
}
