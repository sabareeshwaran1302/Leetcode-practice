/*

Problem Link : https://leetcode.com/problems/longest-substring-without-repeating-characters/
Problem 3 : Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without duplicate characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.



*/
class Solution {
    #include<unordered_map>
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char,int>mp; // map that stores the character and its index where it was last seen
        int l=0,r=0,maxlength=0;
        int n=s.length();
        while(r<n)
        {
            if(mp.find(s[r]) != mp.end() && (mp[s[r]] >= l))
            {//does the current character exist in the map && is it in the current window

                l=mp[s[r]] +1; // moving the left pointer to the right of the last seen index of the current character
            }
            int len = r-l+1; // length of the current window
            maxlength = max(len,maxlength);
            mp[s[r]] = r; // updating the last seen index of the current character
            r=r+1;
        }
        return maxlength;  
    }
};