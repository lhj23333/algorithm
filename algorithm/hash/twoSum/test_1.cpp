#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    // 算法思路：查找互补数
    //          使用哈希表存储已遍历的数字及其索引
    //          每次跳转时进行哈希表互补数查找
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> numMap;
        for(int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if(numMap.find(complement) != numMap.end())
            {
                return {numMap[complement], i};
            }

            numMap[nums[i]] = i;
        }
        return {};
    }
};


int main() {
    Solution solution;
    vector<int> res;

    vector<int> nums = {2, 7, 3, 6};
    int target = 9;

    res = solution.twoSum(nums, target);

    if(!res.empty())
    {
        cout << "Indices found: " << res[0] << ", " << res[1] << endl;
    }

    return 0;
}