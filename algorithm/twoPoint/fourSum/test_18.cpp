#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // 算法思路：双指针
    //          在三数之和的基础上，增加一个循环，固定前两个数，使用双指针找后两个数
    //          注意边界处理以及去重处理
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> result;
        if(nums.size() < 4) return result;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 3; i ++)
        {
            if(i > 0 && nums[i] == nums[i-1]) continue;

            for(int j = i + 1; j < nums.size() - 2; j ++)
            {
                int idxLeft = j + 1;
                int idxRight = nums.size() - 1;

                if(j > i + 1 && nums[j] == nums[j-1]) continue;

                while(idxRight > idxLeft)
                {

                    long long sum = (long long)nums[i] + nums[j] + nums[idxLeft] + nums[idxRight];

                    if(sum > target)
                        idxRight --;
                    else if(sum < target)
                        idxLeft ++;
                    else
                    {
                        result.push_back({nums[i], nums[j], nums[idxLeft], nums[idxRight]});

                        while(idxLeft < idxRight && nums[idxLeft] == nums[idxLeft + 1]) idxLeft ++;
                        while(idxLeft < idxRight && nums[idxRight] == nums[idxRight - 1]) idxRight --;

                        idxLeft ++;
                        idxRight --;
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1000000000, 1000000000, 1000000000, 1000000000};
    int target = 0;
    vector<vector<int>> result = solution.fourSum(nums, target);

    for (const auto& quad : result)
    {
        cout << "[";
        for (int i = 0; i < quad.size(); i++)
        {
            cout << quad[i];
            if (i < quad.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}