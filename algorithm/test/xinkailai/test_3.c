#include <stdio.h>
#include <string.h>

const char* ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                      "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", 
                      "seventeen", "eighteen", "nineteen"};

const char* tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

const char* thousands[] = {"", "thousand", "million", "billion"};

void convertHundreds(int num, char* result) {
    if (num >= 100) {
        strcat(result, ones[num / 100]);
        strcat(result, " hundred");
        if (num % 100 != 0) {
            strcat(result, " ");
        }
    }
    
    num %= 100;
    if (num >= 20) {
        strcat(result, tens[num / 10]);
        if (num % 10 != 0) {
            strcat(result, "-");
            strcat(result, ones[num % 10]);
        }
    } else if (num > 0) {
        strcat(result, ones[num]);
    }
}

void numberToWords(long long num, char* result) {
    if (num == 0) {
        strcpy(result, "zero");
        return;
    }
    
    if (num < 0) {
        strcpy(result, "negative ");
        num = -num;
    } else {
        strcpy(result, "");
    }
    
    int groups[4] = {0};
    int groupIndex = 0;
    
    while (num > 0) {
        groups[groupIndex] = num % 1000;
        num /= 1000;
        groupIndex++;
    }
    
    char temp[1000] = "";
    int first = 1;
    
    for (int i = 3; i >= 0; i--) {
        if (groups[i] != 0) {
            if (!first) {
                strcat(temp, " ");
            }
            
            char groupStr[100] = "";
            convertHundreds(groups[i], groupStr);
            strcat(temp, groupStr);
            
            if (i > 0) {
                strcat(temp, " ");
                strcat(temp, thousands[i]);
            }
            first = 0;
        }
    }
    
    strcat(result, temp);
}

int main() {
    long long num;
    char result[1000];
    
    printf("请输入一个长整型数字: ");
    scanf("%lld", &num);
    
    numberToWords(num, result);
    
    printf("英文翻译: %s\n", result);
    
    return 0;
}