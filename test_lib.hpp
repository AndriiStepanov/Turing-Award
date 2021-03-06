#ifndef TEST_LIB
#define TEST_LIB

#include "lib.hpp"
#include "problem.hpp"

void run_test(const Problem& problem, std::istream& in, std::ostream& out) {
  int tests_number;
  in >> tests_number;

  for (int i = 0; i < tests_number; i++) {
    problem.solve(in, out);
  }
}

void run_test_files(const Problem& problem,
                    const std::string in_str, const std::string out_str) {
  std::ifstream in(in_str);
  std::ofstream out(out_str);

  std::ostream &log = std::clog;
  log << "start running with file " + in_str + "\n";
  std::clock_t start_time = clock();

  run_test(problem, in, out);

  std::clock_t finish_time = clock();
  long double elapsed_time = (long double)(finish_time - start_time) / CLOCKS_PER_SEC;

  log << ("end running into file:  " + out_str + " time: " +
          std::to_string(elapsed_time) + "s\n") << std::flush;

  system(("zip -r ans/" + problem.prefix + ".zip " + out_str).c_str());
}

void run_console_tests(const std::vector<Problem> &problems) {
  for (auto problem : problems) {
    problem.solve(std::cin, std::cout);
  }
}

void run_tests(const std::vector<Problem> &problems) {
  auto remove_following_dir = [](const std::string path) -> std::string {
    auto begin = path.begin();
    for (; *begin != '/'; ++begin) { continue; }
    std::string str;
    for (auto it = std::next(begin); it != path.end(); ++it) { str += *it; }
    return str;
  };

  auto following_dir = [](const std::string path) -> std::string {
    auto end = path.begin();
    for (; *end != '/'; ++end) { continue; }
    std::string str;
    for (auto it = path.begin(); it != end; ++it) { str += *it; }
    return str;
  };

  std::vector<std::thread> problems_threads;
  problems_threads.reserve(problems.size());

  for (auto problem : problems) {
    std::vector<std::thread> threads;
    threads.reserve(problem.inputs().size());
    std::string out_files_via_string = "";

    for (auto [in_str, out_str] : problem.inputs()) {
      out_files_via_string += " " + out_str;
      threads.emplace_back(run_test_files, problem, in_str, out_str);
    }

    for (auto& thread : threads) {
      thread.join();
    }

    if (!problem.inputs().empty()) {
    }
  }

  for (auto& problem_thread : problems_threads) {
    problem_thread.join();
  }
}

#endif
