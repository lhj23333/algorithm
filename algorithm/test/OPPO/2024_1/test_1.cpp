#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isLegal(int number) {
        if (number == 0) return true;
        int num = number;

        vector<int> binary;
        while(num != 0) {
            int temp = num % 2;
            binary.push_back(temp);
            num /= 2;
        }

        int result = 0;
        for (size_t i = binary.size(); i > 0; i++) {
            result = result * 2 + binary[i - 1];
        }
        return result > number;
    }
};

int main() 
{
    int num;
    unordered_map<int, int> map;

    cin >> num;
    for(size_t i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        map[temp] ++;
    }

    Solution solu;
    int result = 0;
    for(auto& pair : map) {
        if(solu.isLegal(pair.first)) {
            result += pair.second;
        } 
    }
    
    cout << result << endl;

    return 0;
}

