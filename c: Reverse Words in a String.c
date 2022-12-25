/*https://leetcode.com/problems/reverse-words-in-a-string/

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.

*/

char * reverseWords(char * s){
    int n = strlen(s) + 1; 
    //!!!!!!!  NEED extra byte for null termination!!!!  otherwise errors

    char* tokens[strlen(s)];    //my "stack"
    char *token = strtok(s, " ");   //get 1st word

    int i = 0;
    for (; token; i++)
    {
        //printf("%s\n", token);
        tokens[i] = token;  //store
        token = strtok(NULL, " ");  //get next word
    }

    char res[n];
    char temp[n];

    strcpy(res, tokens[--i]);
    for (i--; i >= 0; i--)  //traverse "stack"
    {
        //printf("tokens[%d]=%s\n", i, tokens[i]);
        strcpy(temp, res);
        sprintf(res, "%s %s", temp, tokens[i]);
        //refuses to work: strcat(res, tokens[i]);
    }
    //printf("%s\n", res);
    strcpy(s, res);
    return s;
}
