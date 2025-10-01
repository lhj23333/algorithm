#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    long long countK(string str) {
        if(str.size() == 0) return 0;
        long long ret = 0;
 
        char pair = str[0];
        while(pair != str[str.size() - 1]) {
            ret += pair - 'a';
        }
        return ret;
    }


};

int main()
{
    int num;
    cin >> num;

    Solution sol;

    for(size_t i = 0; i < num; i ++) {
        long long n, m, k;
        cin >> n >> m >> k;
        string temp;
        cin >> temp;
        cout << sol.process(temp, n, m, k) << endl;
    }

    return 0;
}