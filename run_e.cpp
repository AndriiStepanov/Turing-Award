#include "task.hpp"

const vector<pair<string, string>> test_data =
[](string pref, vector<int> indexes) {
    vector<pair<string, string>> inputs;
    for (auto index : indexes) {
        string base_string = pref + std::to_string(index);
        inputs.push_back({base_string + ".in", base_string + ".out"});
    }
    return inputs;
}("e00", {1, 2, 3});
