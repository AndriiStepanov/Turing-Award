#ifndef CONFIG
#define CONFIG
#include "lib.hpp"
#include "test_lib.hpp"
#include "sources/A.hpp"
#include "sources/B.hpp"
#include "sources/C.hpp"
#include "sources/D.hpp"
#include "sources/E.hpp"

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
        },
        {
                "crossword",
                run_option::skip,
                io_option::file,
                {{1, 10}},
                solve_c
        },
        {
                "legacy",
                run_option::skip,
                io_option::file,
                {{1, 10}},
                solve_d
        },
        {
                "rocks",
                run_option::skip,
                io_option::file,
                {{1, 10}},
                solve_e
        },
};
#endif
