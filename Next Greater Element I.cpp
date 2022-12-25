/*
https://leetcode.com/problems/next-greater-element-i/description/

The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

Constraints:

1 <= nums1.length <= nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 104
All integers in nums1 and nums2 are unique.
All the integers of nums1 also appear in nums2.
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        map<int, size_t> hash;
        for (int i = 0; i < nums2.size(); i++)
            hash[nums2[i]] = i;

        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++)
        {
            auto it = hash.find(nums1[i]);
            if (next(it) == hash.end()) ans.push_back(-1); //if no greater element globally
            else
            {
                int i = it->second;
                for (; i < nums2.size(); i++)
                {
                    if (nums2[i] > it->first)
                    {
                        ans.push_back(nums2[i]);
                        i = nums2.size(); //exit loop, found next greater element
                    }
                }
                if (i == nums2.size()) ans.push_back(-1);   //end of nums2 OR not found
            }
        }
        return ans;
    }
};
