#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // bool lemonadeChange(vector<int> &bills) {
    //     bool result = true;
    //     unordered_map<int, int> map;

    //     for(int i = 0; i < bills.size(); i ++) {
    //         if(bills[i] > 5) {
    //             int changesNums = bills[i] / 5 - 1;
    //             if(map[10] * 2 + map[5] < changesNums) {
    //                 result = false;
    //                 break;
    //             } else {             
    //                 while(map[10] > 0 && changesNums > 1) {
    //                     map[10] --;
    //                     changesNums -= 2;
    //                 }
    //                 while(map[5] > 0 && changesNums > 0) {
    //                     map[5] --;
    //                     changesNums --;
    //                 }
    //                 if(changesNums > 0) {
    //                     result = false;
    //                     break;
    //                 }
    //             }
    //         }
    //         map[bills[i]] ++;
    //     }
    //     return result;
    // }

    bool lemonadeChange(vector<int> &bills) {
        int five = 0, ten = 0, twenty = 0;
        for (int bill : bills) {
            switch(bill) {
                case 5:
                    five ++;
                    break;
                case 10:
                    if(five <= 0) return false;
                    five --;
                    ten ++;
                    break;
                case 20:
                    if(five > 0 && ten > 0) {
                        ten --;
                        five --;
                    }
                    else if(five > 3) five -= 3;
                    else return false;
                    break;
                default:
                    break;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    
    // Test case 1: [5,5,5,10,20]
    vector<int> bills1 = {5,5,5,10,20};
    bool result1 = solution.lemonadeChange(bills1);
    cout << "Test 1: [5,5,5,10,20] -> " << (result1 ? "true" : "false") << " (Expected: true)" << endl;
    
    // Test case 2: [5,5,10,10,20]
    vector<int> bills2 = {5,5,10,10,20};
    bool result2 = solution.lemonadeChange(bills2);
    cout << "Test 2: [5,5,10,10,20] -> " << (result2 ? "true" : "false") << " (Expected: false)" << endl;
    
    // Test case 3: [5,5,10]
    vector<int> bills3 = {5,5,10};
    bool result3 = solution.lemonadeChange(bills3);
    cout << "Test 3: [5,5,10] -> " << (result3 ? "true" : "false") << " (Expected: true)" << endl;
    
    // Test case 4: [10,10]
    vector<int> bills4 = {10,10};
    bool result4 = solution.lemonadeChange(bills4);
    cout << "Test 4: [10,10] -> " << (result4 ? "true" : "false") << " (Expected: false)" << endl;
    
    // Test case 5: [5]
    vector<int> bills5 = {5};
    bool result5 = solution.lemonadeChange(bills5);
    cout << "Test 5: [5] -> " << (result5 ? "true" : "false") << " (Expected: true)" << endl;
    
    // Test case 6: [5,5,5,5,20,20,20,20,20,20,20,20,20,20,20]
    vector<int> bills6 = {5,5,5,5,20,20,20,20,20,20,20,20,20,20,20};
    bool result6 = solution.lemonadeChange(bills6);
    cout << "Test 6: [5,5,5,5,20,20,20,20,20,20,20,20,20,20,20] -> " << (result6 ? "true" : "false") << " (Expected: false)" << endl;
    
    return 0;
}
