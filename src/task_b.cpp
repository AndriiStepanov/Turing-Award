//
//  task_b.cpp
//  Turing-Award
//
//  Created by Denys Smirnov on 22.02.2018.
//  Copyright © 2018 Denys Smirnov. All rights reserved.
//

#include "task.hpp"

void solve(std::istream& in_stream, std::ostream& out_stream) {
    int a, b;
    in_stream >> a >> b;
    out_stream << a * b << '\n';
}
