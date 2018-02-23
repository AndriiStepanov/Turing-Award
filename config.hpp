#ifndef CONFIG
#define CONFIG
#include "lib.hpp"
#include "test_lib.hpp"
#include "sources/A.hpp"
#include "sources/B.hpp"

vector<problem> problems {
        {
                "row",
                run_option::run,
                io_option::file,
                {{1, 10}},
                solve_a
        },
        {
                "election",
                run_option::skip,
                io_option::file,
                {{1, 10}},
                solve_b
        }
};
#endif