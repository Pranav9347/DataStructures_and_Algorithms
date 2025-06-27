// Leetcode: https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips=0;
        bitset<32> bin_a(a);
        bitset<32> bin_b(b);
        bitset<32> bin_c(c);
        for(int i=0;i<32;i++)
        {
            if((bin_a[i] | bin_b[i]) == bin_c[i]) // match
                continue; //no flip required
            else //mismatch
            {
                if(bin_c[i] == 1)
                    flips++;
                else
                {
                    if(bin_a[i]^bin_b[i] == 1)
                        flips++;
                    else flips+=2;
                }
            }
        }
        return flips;
    }
};