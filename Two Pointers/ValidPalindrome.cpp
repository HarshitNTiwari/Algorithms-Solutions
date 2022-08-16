/*
Author: Harshit Tiwari
Date: 19-07-2022
https://leetcode.com/problems/valid-palindrome/
*/


class Solution {
public:
    bool isPalindrome(string s) {
        int i=0, j=s.size()-1;
        while(i<j){
            if(!isalnum(s[i])){
                i++;
                continue;
            }
            if(!isalnum(s[j])){
                j--;
                continue;
            }
            if(tolower(s[i]) != tolower(s[j]))
                return false;
            i++; j--;
        }
        return  true;
    }
};