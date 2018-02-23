#ifndef TEST_LIB
#define TEST_LIB
#include "lib.hpp"

enum class run_option {
    run, skip
};

enum class io_option {
    file, console
};

typedef function<void(istream&, ostream&)> solve_function;

struct problem {
    string file_name;
    run_option run_type;
    io_option io_type;
    vector<pair<int, int>> tests;
    solve_function solve;
};

void run_tests(vector<problem>& problems) {
    freopen("../ans/stdout.txt", "w", stdout);
    auto run = [](solve_function solve, istream& in, ostream& out) {
        int tests_number;
        in >> tests_number;
        for (int i = 0; i < tests_number; i++) {
            solve(in, out);
        }
    };
    auto get_number = [](int id) {
        string result = to_string(id);
        if (result.length() == 1) {
            result = "0" + result;
        }
        return result;
    };
    for (problem p : problems) {
        if (p.run_type == run_option::skip) continue;
        if (p.io_type == io_option::console) {
            run(p.solve, cin, cout);
        } else if (p.io_type == io_option::file) {
            set<int> tests_set;
            for (pair<int, int> interval : p.tests) {
                for (int i = interval.first; i <= interval.second; i++) {
                    tests_set.insert(i);
                }
            }
            string answers = "";
            for (int test_id : tests_set) {
                string name = p.file_name + get_number(test_id);
                ifstream in("../in/" + name + ".in");
                ofstream out("../ans/" + name + ".ans");
                answers += " ../ans/" + name + ".ans";
                cout << "start run in file " + name + ".in" << endl;
                double start_time = clocks();
                run(p.solve, in, out);
                cout << "end run in file " + name + ".in time: " << clocks() - start_time << "s" << endl;
                system(("zip -r ../ans/submission" + answers).c_str());
            }
        }
    }
}
#endif