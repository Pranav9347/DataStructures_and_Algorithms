// LeetCode Problem: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool is_vowel(char c)
    {
        if(c == 'a' || c == 'e' ||c == 'i' || c == 'o'|| c == 'u')
            return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int i=0, j=0, max_vowels = 0, curr_count = 0;
        while(j<=k-1)
        {
            if(is_vowel(s[j]))
                curr_count++;
            j++;
        }
        max_vowels = curr_count;
        while(j<=s.length())
        {
            if(is_vowel(s[i]))
                curr_count--;
            if(is_vowel(s[j]))
                curr_count++;
            if(curr_count>max_vowels)
                max_vowels = curr_count;
            j++;
            i++;
        }
        return max_vowels;
    }


int main()
{
    string s = "hello";
    int k = 3;
    cout << maxVowels(s,k);
    return 0;
}