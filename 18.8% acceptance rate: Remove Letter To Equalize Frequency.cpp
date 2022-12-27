/* First try for 18.8% acceptance rate question
Performance:
Runtime: beats 100% (0 ms)
Memory:  beats 72.28%  (6.2 MB)

Problem: 
https://leetcode.com/problems/remove-letter-to-equalize-frequency/description/

You are given a 0-indexed string word, consisting of lowercase English letters. You need to select one index and remove the letter at that index from word so that the frequency of every letter present in word is equal.

Return true if it is possible to remove one letter so that the frequency of all letters in word are equal, and false otherwise.

Note:

The frequency of a letter x is the number of times it occurs in the string.
You must remove exactly one letter and cannot chose to do nothing.

Constraints:

2 <= word.length <= 100
word consists of lowercase English letters only.
*/

class Solution {
public:
    bool equalFrequency(string word) {
        map<char,size_t> hash;
        for (int i = 0; i < word.size(); i++)
        {
            if (hash.find(word[i]) == hash.end())
                hash[word[i]] = 1;
            else
                hash[word[i]]++;
        }
        if (hash.size() == 1) return true;
        if (hash.size() == 2) //a:5 b:4  OK   a:4 b:5  OK    a:4 b:4 NO  a:4 b:2 NO  a:10 b:1 OK
        {
            int a = hash.begin()->second;
            int b = next(hash.begin())->second;
            return (min(a,b) + 1 == max(a,b)) || (a == 1 || b == 1);
        }
        
        bool foundTarget = false;
        
        map<char,size_t>::iterator equalFreq;

        if (hash.begin()->second == next(hash.begin())->second || hash.begin()->second == next(next(hash.begin()))->second)
            equalFreq = hash.begin();
        else
            equalFreq = next(hash.begin());

        bool allOnes = (equalFreq->second == 1);

        for (auto it = hash.begin(); it != hash.end(); it++)
        {
            if (it->second == 1+equalFreq->second)
            {
                if (foundTarget) return false;  //if found already, can't have two decrements
                foundTarget = true;
            }
            else if (it->second != equalFreq->second)
            {
                if (it->second == 1)    //then just remove it
                {
                    if (foundTarget) return false;
                    foundTarget = true;
                }
                else    //neither removable nor decrementable, then truly impossible
                    return false;
            }
            //otherwise already equal frequency, okay to keep going
        }
        return (foundTarget || allOnes);    //only reach this point if all same frequency already
        //then okay if not found target but all ones, just remove a one's. 
    }
};
