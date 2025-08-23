#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 快慢双指针
    // 快指针负责搜索所需添加元素，慢指针负责更新元素，最后慢指针大小即删除后数组大小
    int removeElement(vector<int>& nums, int val)
    {
        int index_fast = 0;
        int index_low = 0;

        for(; index_fast < nums.size(); index_fast ++)
        {
            if(nums[index_fast] != val){
                nums[index_low] = nums[index_fast];
                index_low ++;
            }
        }

        return index_low;
    }
};

int main(){
    Solution solut;
    int ret;

    vector<int> nums = {};
    int val = 0;

    ret = solut.removeElement(nums, val);

    cout << ret << endl;
    for(int i = 0; i < ret; i ++)
    {
        cout << nums[i] << "";
    } 
    cout << "\n" << endl;

    return 0;
}