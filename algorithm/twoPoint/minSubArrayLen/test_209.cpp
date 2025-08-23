#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 子数组：连续非空数组
    // 思路：双指针实现滑动窗口获取最小子数组
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int result = INT_MAX;
        int indexLeft = 0, indexRight = 0;;
        int sum = 0;
        int subArrayLength = 0;

        // 快指针负责更新窗口右区间
        for(; indexRight < nums.size(); indexRight ++)
        {
            // 每次右区间更新将数组纳入窗口中
            sum += nums[indexRight];

            // 当窗口总和大于或等于 target 时，注意使用 while 以缩小区间
            while(sum >= target) {
                // 记录当前窗口长度
                subArrayLength = indexRight - indexLeft + 1;
                // 并与当前记录最小长度 result 进行比较，更新最小长度
                if(subArrayLength <= result)
                {
                    result = subArrayLength;
                }

                // 同时缩减左边界，试探最小区间范围
                sum -= nums[indexLeft ++];
            }
        }

        if(result == INT_MAX)
            return 0; 
        else
            return result;
    }
};

int main()
{
    Solution solut;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    cout << solut.minSubArrayLen(target, nums) << endl;

    return 0;
}