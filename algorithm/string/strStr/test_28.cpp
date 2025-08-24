#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<size_t> getNext(const string &pattern)
    {
        if(pattern.empty()) return {};

        vector<size_t> next(pattern.size(), 0);
        size_t j = 0, i = 1;

        for(; i < pattern.size(); i++)
        {
            while(j > 0 && pattern[i] != pattern[j]) j = next[j - 1];
            if(pattern[i] == pattern[j]) j ++;

            next[i] = j;
        }
       return next;
    }

public:
    int strStr(string haystack, string needle)
    {
        if(needle.empty() || haystack.empty()) return -1;

        vector<size_t> next = getNext(needle);
        size_t i = 0, j = 0;

        for(; i < haystack.size(); i ++)
        {
            while(j > 0 && haystack[i] != needle[j]) j = next[j - 1];
            if(haystack[i] == needle[j]) j ++;

            if(j == needle.size())
            {
                return (int)(i - j + 1);
            }
        }
        return -1;
    }
};

int main()
{
    Solution solut;

    string haystack = "sadbutsad";
    string needle = "sad";
    int result = solut.strStr(haystack, needle);
    cout << "Result: " << result << endl;

    return 0;
}

