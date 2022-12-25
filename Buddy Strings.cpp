/*
https://leetcode.com/problems/buddy-strings/description/

Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

Constraints:

1 <= s.length, goal.length <= 2 * 104
s and goal consist of lowercase letters.
*/

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        //aab vs aab   if same, as long as two same letters, ok
        //abc vs abc   else nope
        
        //aaa vs aaaa       no, diff len
        //aaaab vs aabaa    yes     yynyn               2 diff (n's)
        //aaaab vs aaaac    no, diff char ct            sorted (aaaab) !=  sorted(aaaac)
        //abcde vs edcab    no, 2 swaps:     nnynn      >4 diff

        if (s.length() != goal.length()) return false;  //diff len

        string sSorted = s;
        sort(sSorted.begin(), sSorted.end());
        if (s == goal)  //if same
        {
            for (int i = 1; i < s.length(); i++)
            {
                if (sSorted[i] == sSorted[i-1]) return true; //has dupe, just swap dupes
            }
            return false; //no dupes, can't swap anything
        }

        string gSorted = goal;
        sort(gSorted.begin(), gSorted.end());
        if (sSorted != gSorted) return false; //diff char ct

        int numDiff = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != goal[i])
            {
                if (numDiff > 1) return false;  //>2 diffs, can't achieve w/ 1 swap
                numDiff++;
            }
        }
        return true;
    }
};
