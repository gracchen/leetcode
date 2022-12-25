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

        if (s == goal)  //if same
        {
            sort(s.begin(), s.end());
            for (int i = 1; i < s.length(); i++)
                if (s[i] == s[i-1]) return true; //has dupe, just swap dupes

            return false; //no dupes, can't swap anything
        }

        int numDiff = 0;
        int wrongIndex1, wrongIndex2;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != goal[i])
            {
                switch(numDiff)
                {
                    case 0:
                        wrongIndex1=i;  //save to swap later
                        break;
                    case 1:
                        wrongIndex2=i;  //save to swap later
                        break;
                    case 2:             //>2 diffs, can't achieve w/ 1 swap
                        return false;
                };
                numDiff++;
            }
        }

        if (numDiff != 2) return false;     //<2 diffs, can't swap, diff ct
        
        //aaaab vs aabaa    yes     yynyn               2 diff (n's)
        //  s       goal

        //wrongIndex1 = 2,  wrongIndex2 = 4   
        //temp = s[2] = a
        //s[2] = s[4] = b
        //s[4] = temp;
        //result:     s=aabaa, which equals goal OK

        //attempt to make same by swapping the two found wrong indexes:
        char temp = s[wrongIndex1];
        s[wrongIndex1] = s[wrongIndex2];
        s[wrongIndex2] = temp; 

        return (s == goal); //if swap didn't work, diff char ct
    }
};
