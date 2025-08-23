#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // 算法思路：三数之和
    //          先排序再双指针
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i ++)
        {
            if(nums[i] > 0) break;

            // 第一层去重:
            // 注意是 nums[i-1]，而不是 nums[i+1]，二者意义不同
            // nums[i-1] 是向前比对，是否已经发生重复
            // nums[i+1] 是向后比对，抛弃后续所有相同元素
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int idxLeft = i + 1;
            int idxRight = nums.size() - 1;

            while(idxRight > idxLeft)
            {
                int sum = nums[i] + nums[idxLeft] + nums[idxRight];
                
                if(sum > 0)
                    idxRight --;
                else if (sum < 0)
                    idxLeft ++;
                else {
                    res.push_back({nums[i], nums[idxLeft], nums[idxRight]});

                    // 第二层去重：跳过重复元素组合
                    while (idxLeft < idxRight && nums[idxLeft] == nums[idxLeft + 1]) idxLeft ++;
                    while (idxLeft < idxRight && nums[idxRight] == nums[idxRight - 1]) idxRight --;
                    idxLeft ++;
                    idxRight --;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0};
    vector<vector<int>> res = solution.threeSum(nums);

    for(const auto& triplet : res) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }

    return 0;
}