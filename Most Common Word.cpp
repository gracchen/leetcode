/*
My Solution:  Runtime: 7ms (beats 73.7%)    Memory: 7.6 MB (beats 85.59%)

https://leetcode.com/problems/most-common-word/description/

Given a string paragraph and a string array of the banned words banned, return the most frequent word that is not banned. It is guaranteed there is at least one word that is not banned, and that the answer is unique.

The words in paragraph are case-insensitive and the answer should be returned in lowercase.

Constraints:

1 <= paragraph.length <= 1000
paragraph consists of English letters, space ' ', or one of the symbols: "!?',;.".
0 <= banned.length <= 100
1 <= banned[i].length <= 10
banned[i] consists of only lowercase English letters.

*/class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        set<char> punc = {'!', '?', '\'', ',', ';', '.', ' '};
        set<string> bans(banned.begin(), banned.end());
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        map<string, size_t> dict;
        int stringStart = 0;

        for (int i = 0; i < paragraph.size();)
        {
            if (punc.find(paragraph[i]) != punc.end())  //if punc
            {
                string currWord = paragraph.substr(stringStart, i-stringStart);
                //cout << currWord << endl;
                if (bans.find(currWord) == bans.end())  //if not banned, record in map
                {
                    if (dict.find(currWord) == dict.end()) dict[currWord] = 1;  //insert
                    else dict[currWord]++;
                }
                i++;
                for (; i < paragraph.size() && (punc.find(paragraph[i]) != punc.end()); i++)    //skip to next non-punc
                    ;
                stringStart = i;
            }
            else
                i++;
        }
        if (punc.find(paragraph[paragraph.length()-1]) == punc.end())
        {
            string currWord = paragraph.substr(stringStart, paragraph.length()-stringStart);
            //cout << currWord << endl;
            if (bans.find(currWord) == bans.end())  //if not banned, record in map
            {
                if (dict.find(currWord) == dict.end()) dict[currWord] = 1;  //insert
                else dict[currWord]++;
            }
        }

        auto ans = dict.begin();

        /*for(auto it = ans; it != dict.end(); ++it)
            cout << it->first << ": " << it->second << "\n";*/

        for(auto it = next(ans); it != dict.end(); ++it)
        {
            if (it->second > ans->second)
                ans = it;
        }

        return ans->first;
    }
};
