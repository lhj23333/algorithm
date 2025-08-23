#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

class Solution {
public:
    // 算法思路：通过 unordered_set 来存储第一个数组的元素，然后遍历第二个数组，查找交集
    // unordered_set 特性：哈希表，查找速度快，适合用于查找交集, 且不允许重复元素
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int> set(nums1.begin(), nums1.end());
        unordered_set<int> res;

        for(int num = 0; num < nums2.size(); num++)
        {
           if(set.find(nums2[num]) != set.end())
           {
               res.insert(nums2[num]);
           }
        }

        return vector<int>(res.begin(), res.end());
    }
};

int main()
{
    Solution solution;
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> result = solution.intersection(nums1, nums2);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}