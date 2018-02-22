#include "task.hpp"

using Seconds = long double;

auto time_run_test(std::istream& in, std::ostream& out) -> Seconds;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (auto [in, out] : test_data) {
        std::fstream file_in(in, std::ios_base::in);
        std::fstream file_out(out, std::ios_base::out);

        std::clog << "Finished with " << in << " in " << std::flush << std::fixed
        << time_run_test(file_in, file_out) << "s to " << out << std::endl;
    }

    return 0;
}

auto time_run_test(std::istream& in, std::ostream& out) -> Seconds {
    std::clock_t start = clock();
    solve(in, out);
    std::clock_t finish = clock();
    return (Seconds)(finish - start) / CLOCKS_PER_SEC;
}
