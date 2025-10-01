#include <iostream>

using namespace std;

int main() 
{
    long long number;
    cin >> number;

    long long temp = number;
    long long reverse = 0;
    while(temp != 0) {
        int digit = temp % 10;
        reverse = reverse * 10 + digit;
        temp /= 10; 
    }

    cout << reverse + number;
    
    return 0;
}