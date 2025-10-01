#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    // 回溯法超时
    bool backtracking(vector<int> &nums, size_t startIndex, size_t step) {
        if((step == 0 && startIndex < nums.size() - 1) || startIndex > nums.size() - 1) return false;
        if(step >= nums.size() - 1 - startIndex ) return true;

        for(size_t i = 1; i <= step; i ++) {
            startIndex += i;
            if(backtracking(nums, startIndex, nums[startIndex])) return true;
            startIndex -= i;
        }
        return false;
    }

public:
    // bool canJump(vector<int> &nums) {
    //     if(nums.size() == 1) return true;
    //     return backtracking(nums, 0, nums[0]);
    // }

    bool canJump(vector<int> &nums) {
        if(nums.size() == 1) return true;

        size_t cover = 0;
        for(size_t i = 0; i <= cover; i ++) {
            cover = max(cover, i + nums[i]);
            if(cover >= nums.size() - 1) return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    std::vector<std::pair<std::vector<int>, bool>> tests = {
        {{2,3,1,1,4}, true},
        {{3,2,1,0,4}, false},
        {{0}, true},
        {{0,1}, false},
        {{2,0,0}, true}
    };

    for (size_t i = 0; i < tests.size(); ++i) {
        auto &input = tests[i].first;
        bool expected = tests[i].second;
        bool actual = sol.canJump(input);

        std::cout << "Test " << (i + 1) << ": input = [";
        for (size_t j = 0; j < input.size(); ++j) {
            if (j) std::cout << ",";
            std::cout << input[j];
        }
        std::cout << "], actual = " << (actual ? "true" : "false")
                  << ", expected = " << (expected ? "true" : "false")
                  << " -> " << (actual == expected ? "PASS" : "FAIL") << std::endl;
    }

    return 0;
}