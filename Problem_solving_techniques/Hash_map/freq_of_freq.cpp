// Leetcode: https://leetcode.com/problems/determine-if-two-strings-are-close/

#include <iostream>
#include <unordered_map>
using namespace std;

bool closeStrings(string word1, string word2) {
    if(word1.size() != word2.size()) return false;
    unordered_map<char, int> letter_count1, letter_count2;
    for (char c : word1) {
        letter_count1[c]++;
    }
    for (char c : word2) {
        letter_count2[c]++;
    }
    // Perform key-check(if all keys are same)
    unordered_map<char, int>::iterator itr;
    if(letter_count1.size()!=letter_count2.size())
        return false;
    for(itr=letter_count1.begin();itr!=letter_count1.end();itr++)
    {
        if(!letter_count2.count(itr->first))
            return false;
    }
    //If code comes till here, Key-wise map are same!
    //Key-equivalent maps should be checked for value similarity
    //The value set must be same
    unordered_map<int, int> count_of_count1, count_of_count2;
    
    for(itr=letter_count1.begin();itr!=letter_count1.end();itr++)
    {
        if(!count_of_count1.count(itr->second))
            count_of_count1[itr->second]=1;
        else
            count_of_count1[itr->second]++;
    }
    for(itr=letter_count2.begin();itr!=letter_count2.end();itr++)
    {
        if(!count_of_count2.count(itr->second))
            count_of_count2[itr->second]=1;
        else
            count_of_count2[itr->second]++;
    }
    unordered_map<int, int>::iterator itr1;
    if(count_of_count1.size()!=count_of_count2.size())
        return false;
    for(itr1=count_of_count1.begin();itr1!=count_of_count1.end();itr1++)
    {
        if(!count_of_count2.count(itr1->first) || (itr1->second)!=count_of_count2[itr1->first])
            return false;
    }
    return true;
}

int main()
{
    cout<<boolalpha;
    cout<<closeStrings("bbcbaa","abcaca");

    return 0;
}