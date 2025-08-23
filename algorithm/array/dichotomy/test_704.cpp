#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 循环不变量原则： 区间定义不变 -> 区间：左闭右闭
    int search(vector<int>& nums, int target){
        int index_l = 0; 
        int index_r = nums.size() - 1; // 区间定义：index_r 需为搜索区间边界

        // 区间定义：当 index_l == index_r 不违法
        while (index_l <= index_r)
        {
            int middle = (index_l + index_r) / 2;
            
            if (nums[middle] > target)
            {
                index_r = middle - 1;   // 区间定义：middle 索引位置已进行判断，则不入更新区间范围
            }
            else if (nums[middle] < target)
            {
                index_l = middle + 1;
            }
            else
            {
                return middle;
            }
        }
        return -1;
    }
};

int main(){
    Solution solut;
    
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    cout << solut.search(nums, target) << endl;

    return 0;
}