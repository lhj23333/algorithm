#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool canAdjustString(string str, int n) {
        int len = str.length();
        int aCount = 0;
        
        for(char c : str) {
            if(c == 'a') aCount++;
        }
        
        if(aCount < n) return false;
        
        vector<int> bSegments;
        int currentBCount = 0;
        
        for(int i = 0; i < len; i++) {
            if(str[i] == 'b') {
                currentBCount++;
            } else {
                if(currentBCount > 0) {
                    bSegments.push_back(currentBCount);
                    currentBCount = 0;
                }
            }
        }
        if(currentBCount > 0) {
            bSegments.push_back(currentBCount);
        }
        
        int minAdjustments = 0;
        for(int segmentLength : bSegments) {
            if(segmentLength > 1) {
                minAdjustments += (segmentLength - 1 + 1) / 2;
            }
        }
        
        return minAdjustments <= n;
    }
};

int main() {
    Solution sol;
    string str;
    int n;
    
    cin >> str >> n;
    
    if(sol.canAdjustString(str, n)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}