#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int result;

    // 暴力递归，超出时间限制
    void traversal(vector<int>& gas, vector<int>& cost, size_t startGas, size_t startIndex, size_t cap) {
        if(startIndex == gas.size()) {
            result = startGas;
            return ;
        }

        size_t curGas = (startGas + startIndex) % gas.size();
        cap += gas[curGas];
        if(cap >= cost[curGas]) {
            traversal(gas, cost, startGas, startIndex + 1, cap - cost[curGas]);
        }
    }

public:
    // int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    //     result = -1;
    //     for(size_t i = 0; i < gas.size(); i ++) {
    //         traversal(gas, cost, i, 0, 0);
    //     }

    //     return result;
    // }

    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int minNetCap = INT_MAX;
        int endCap = 0;

        for(size_t i = 0; i < gas.size(); i ++) {
            int netCap = gas[i] - cost[i];
            endCap += netCap;
            minNetCap = min(minNetCap, endCap);
        }

        if(endCap < 0) return -1;
        if(minNetCap >= 0) return 0;    

        for(size_t i = gas.size() - 1; i >= 0; i --) {
            minNetCap += gas[i] - cost[i];
            if(minNetCap >= 0) return i;
        }
        return -1;
    }
};

int expectedCanCompleteCircuit(const std::vector<int>& gas, const std::vector<int>& cost) {
    int n = (int)gas.size();
    int total = 0, tank = 0, start = 0;
    for (int i = 0; i < n; ++i) {
        int diff = gas[i] - cost[i];
        total += diff;
        tank += diff;
        if (tank < 0) {
            tank = 0;
            start = i + 1;
        }
    }
    if (total < 0) return -1;
    return start % n;
}

int main() {
    std::vector<std::pair<std::vector<int>, std::vector<int>>> tests = {
        {{1,2,3,4,5}, {3,4,5,1,2}}, // expect 3
        {{2,3,4}, {3,4,3}},         // expect -1
        {{5}, {4}},                 // expect 0
        {{1}, {2}},                 // expect -1
        {{5,1,2,3,4}, {4,4,1,5,1}}, // expect 4
    };

    for (size_t i = 0; i < tests.size(); ++i) {
        const auto& gas = tests[i].first;
        const auto& cost = tests[i].second;
        Solution sol;
        int actual = sol.canCompleteCircuit(const_cast<std::vector<int>&>(gas), const_cast<std::vector<int>&>(cost));
        int expect = expectedCanCompleteCircuit(gas, cost);
        std::cout << "Test " << (i+1) << ": actual = " << actual << ", expected = " << expect << std::endl;
    }
    return 0;
}
