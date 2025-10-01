#include <iostream>

using namespace std;

int main (){
    long long n;
    cin >> n;
    int m;
    cin >> m;

    long long result = n / m;
    if(n % m == 0) result ++;

    cout << result << endl;

    return 0;
}