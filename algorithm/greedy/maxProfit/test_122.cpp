#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() < 2) return 0;

        int result = 0;
        int up = 0;
        for(size_t i = 1; i < prices.size(); i++) {
            int temp = prices[i] - prices[i - 1];
            if(temp > 0) up += temp;
            else {
                result += up;
                up = 0;
            }
        }

        return result + up;
    }
};  

static void printVector(const vector<int>& v) {
    cout << "[";
    for(size_t i = 0; i < v.size(); ++i) {
        if(i) cout << ", ";
        cout << v[i];
    }
    cout << "]";
}

int main()
{
    Solution sol;
    struct Test { vector<int> prices; int expected; };
    vector<Test> tests = {
        { {}, 0 },
        { {5}, 0 },
        { {7,1,5,3,6,4}, 7 },
        { {7,6,4,3,1}, 0 },
        { {1,2,3,4,5}, 4 },
        { {3,3,5,0,0,3,1,4}, 8 },
        { {2,1,2,0,1}, 2 },
        { {1,1,1,1}, 0 }
    };

    int pass = 0;
    for(size_t i = 0; i < tests.size(); ++i) {
        int got = sol.maxProfit(const_cast<vector<int>&>(tests[i].prices));
        cout << "Test " << (i+1) << ": input = ";
        printVector(tests[i].prices);
        cout << " | expected = " << tests[i].expected << " | got = " << got;
        if(got == tests[i].expected) {
            cout << " => Correct";
            ++pass;
        } else {
            cout << " => Wrong";
        }
        cout << "\n";
    }

    cout << "Summary: " << pass << " / " << tests.size() << " tests passed.\n";
    return 0;
}