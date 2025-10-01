#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> result;

        size_t hash[27] = {};
        for(size_t i = 0; i < s.size(); i ++) {
            hash[s[i] - 'a'] = i;
        }
        
        size_t left = 0;
        size_t right = 0;
        for(size_t i = 0; i < s.size(); i++) {
            right = max(right, hash[s[i] - 'a']);
            if(i == right) {
                result.push_back((int)(i - left + 1));
                left = right + 1;
            }
        }
        return result;
    }
};

void testPartitionLabels() {
    Solution sol;

    // Test 1: Example from LeetCode
    string s1 = "ababcbacadefegdehijhklij";
    vector<int> expected1 = {9,7,8};
    vector<int> result1 = sol.partitionLabels(s1);
    cout << (result1 == expected1 ? "PASS" : "FAIL") << " Test 1" << endl;

    // Test 2: All unique characters
    string s2 = "abcdef";
    vector<int> expected2 = {1,1,1,1,1,1};
    vector<int> result2 = sol.partitionLabels(s2);
    cout << (result2 == expected2 ? "PASS" : "FAIL") << " Test 2" << endl;

    // Test 3: All same character
    string s3 = "aaaaa";
    vector<int> expected3 = {5};
    vector<int> result3 = sol.partitionLabels(s3);
    cout << (result3 == expected3 ? "PASS" : "FAIL") << " Test 3" << endl;

    // Test 4: Two partitions
    string s4 = "eccbbbbdec";
    vector<int> expected4 = {10};
    vector<int> result4 = sol.partitionLabels(s4);
    cout << (result4 == expected4 ? "PASS" : "FAIL") << " Test 4" << endl;

    // Test 5: Empty string
    string s5 = "";
    vector<int> expected5 = {};
    vector<int> result5 = sol.partitionLabels(s5);
    cout << (result5 == expected5 ? "PASS" : "FAIL") << " Test 5" << endl;

    // Test 6: Single character
    string s6 = "z";
    vector<int> expected6 = {1};
    vector<int> result6 = sol.partitionLabels(s6);
    cout << (result6 == expected6 ? "PASS" : "FAIL") << " Test 6" << endl;
}

int main() {
    testPartitionLabels();
    return 0;
}
