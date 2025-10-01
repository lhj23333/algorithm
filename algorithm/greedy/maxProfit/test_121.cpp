#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() == 1) return 0;
        int maxProf = INT_MIN;
        int prof = 0;

        for(int i = 1; i < prices.size(); i++) {
            prof += prices[i] - prices[i - 1];
            if(prof < 0) prof = 0;
            maxProf = max(maxProf, prof);
        }
        return maxProf;
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Basic case with profit
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    int result1 = solution.maxProfit(prices1);
    cout << "Test 1: [7,1,5,3,6,4] -> Result: " << result1 << " (Expected: 5)" << endl;
    
    // Test case 2: Decreasing prices (no profit)
    vector<int> prices2 = {7, 6, 4, 3, 1};
    int result2 = solution.maxProfit(prices2);
    cout << "Test 2: [7,6,4,3,1] -> Result: " << result2 << " (Expected: 0)" << endl;
    
    // Test case 3: Single element
    vector<int> prices3 = {5};
    int result3 = solution.maxProfit(prices3);
    cout << "Test 3: [5] -> Result: " << result3 << " (Expected: 0)" << endl;
    
    // Test case 4: Two elements with profit
    vector<int> prices4 = {1, 5};
    int result4 = solution.maxProfit(prices4);
    cout << "Test 4: [1,5] -> Result: " << result4 << " (Expected: 4)" << endl;
    
    // Test case 5: Two elements with loss
    vector<int> prices5 = {5, 1};
    int result5 = solution.maxProfit(prices5);
    cout << "Test 5: [5,1] -> Result: " << result5 << " (Expected: 0)" << endl;
    
    // Test case 6: Multiple peaks
    vector<int> prices6 = {1, 2, 3, 0, 2};
    int result6 = solution.maxProfit(prices6);
    cout << "Test 6: [1,2,3,0,2] -> Result: " << result6 << " (Expected: 2)" << endl;
    
    return 0;
}
