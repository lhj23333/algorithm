#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 但凸凹数组排序思路：无序数组 -> 两对有序数组进行头尾双指针比较排序
    // 凸数组 -> 比较低值，凹数组 -> 比较高值
    vector<int> sortedSquares(vector<int>& nums)
    {
        vector<int> sortNums(nums.size());
        int index = nums.size() - 1;

        for(int i = 0; i < nums.size(); i ++)
        {
            nums[i] = nums[i] * nums[i];
        }

        int index_left = 0;
        int index_right = nums.size() - 1;
        
        for(; index_left <= index_right;)
        {
            if(nums[index_left] > nums[index_right])
            {
                sortNums[index --] = nums[index_left];
                index_left ++;
            }
            else
            {
                sortNums[index --] = nums[index_right];
                index_right --;
            }
        }

        return sortNums;
    }
};

int main()
{
    Solution solut;

    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> result = solut.sortedSquares(nums);

    for(int i = 0; i < nums.size(); i ++)
    {
        cout << result[i] << " "; 
    }
    cout << endl;

    return 0;
}
