#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, int> twoSumCount(vector<int>& numA, vector<int>& numB)
    {
        unordered_map<int, int> res;

        for(int i = 0; i < numA.size(); i ++)
        {
            for(int j = 0; j < numB.size(); j ++)
            {
                res[numA[i] + numB[j]] ++;
            }
        }

        return res;
    }

public:
    // 算法思路：四数相加为零计数
    //          采用哈希表进行分组之和存储，将四数之和转换为两数之和问题
    //          遍历其一哈希表，在另一哈希表中查找对应互补数即可
    //          采用 map -> 需存储在分组时，分组后的参数和及其出现次数
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
    {
        int res = 0;

        unordered_map<int, int> numMap1 = twoSumCount(nums1, nums2);
        unordered_map<int, int> numMap2 = twoSumCount(nums3, nums4);

        for(auto& pair : numMap1)
        {
            int val = pair.first;
            int cnt = pair.second;
            int complement = 0 - val;

            if(numMap2.find(complement) != numMap2.end())
            {
                res += cnt * numMap2[complement];
            }
        }
        
        return res;
    }
};

int main() {
    Solution solution;
    int res;

    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {-2, -1};
    vector<int> nums3 = {-1, 2};
    vector<int> nums4 = {0, 2};

    res = solution.fourSumCount(nums1, nums2, nums3, nums4);

    cout << "Count of tuples: " << res << endl;

    return 0;
}