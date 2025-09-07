#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
// 算法思路：优先级队列（小顶堆）
//          1. 进行元素频率统计（unordered_map)
//          2. 维护 k 大小小顶堆
private:
    class myComparison {
    public:
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) {
            return lhs.second > rhs.second;
        }
    };

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.empty()) return {};
        unordered_map<int, int> map;
        priority_queue<pair<int, int>, vector<pair<int, int>>, myComparison> pri_que;

        for (size_t i = 0; i < nums.size(); i++) {
            map[nums[i]] ++;
        }

        for(unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it ++) {
            pri_que.push(*it);
            if(pri_que.size() > k){
                pri_que.pop();
            }
        }

        size_t actuallK = (k > map.size()) ? map.size() : k;
        vector<int> result(actuallK);
        for (size_t i = actuallK; i-- > 0;) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> result = sol.topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}