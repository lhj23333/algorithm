#include <iostream>
#include <string>

void big_divide(const char* dividend, const char* divisor, char* quotient, char* remainder) {
    long long divd = 0, divs = 0;
    int i = 0;
    
    while (dividend[i] != '\0' && dividend[i] >= '0' && dividend[i] <= '9') {
        divd = divd * 10 + (dividend[i] - '0');
        i++;
    }
    
    i = 0;
    while (divisor[i] != '\0' && divisor[i] >= '0' && divisor[i] <= '9') {
        divs = divs * 10 + (divisor[i] - '0');
        i++;
    }
    
    if (divs != 0) {
        long long quot = divd / divs;
        long long rem = divd % divs;
        
        // Convert quotient to string
        i = 0;
        do {
            quotient[i++] = (quot % 10) + '0';
            quot /= 10;
        } while (quot > 0);
        quotient[i] = '\0';
        // Reverse quotient string
        int len = i;
        for (int j = 0; j < len / 2; j++) {
            char temp = quotient[j];
            quotient[j] = quotient[len - 1 - j];
            quotient[len - 1 - j] = temp;
        }
        
        // Convert remainder to string
        i = 0;
        do {
            remainder[i++] = (rem % 10) + '0';
            rem /= 10;
        } while (rem > 0);
        remainder[i] = '\0';
        // Reverse remainder string
        len = i;
        for (int j = 0; j < len / 2; j++) {
            char temp = remainder[j];
            remainder[j] = remainder[len - 1 - j];
            remainder[len - 1 - j] = temp;
        }
    } else {
        quotient[0] = '\0';
        remainder[0] = '\0';
    }
}

int main() {
    const char* test_dividend = "2312321323132323783742462878420948943122324324342343412321321321";
    const char* test_divisor = "12323233245";
    char quot[20] = {0};
    char rem[20] = {0};
    
    big_divide(test_dividend, test_divisor, quot, rem);
    
    std::cout << "Quotient: " << quot << std::endl;
    std::cout << "Remainder: " << rem << std::endl;
    
    return 0;
}