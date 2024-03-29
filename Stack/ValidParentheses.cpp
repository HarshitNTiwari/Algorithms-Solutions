/*
Author: Harshit Tiwari
Date: 19-07-2022
https://leetcode.com/problems/valid-parentheses/
*/


class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                st.push(s[i]);
            if(s[i]==')'){
                if(st.empty() || st.top()!='(')
                    return false;
                else 
                    st.pop();
            }
            else if(s[i]=='}'){
                if(st.empty() || st.top()!='{')
                    return false;
                else 
                    st.pop();
            }
            else if(s[i]==']'){
                if(st.empty() || st.top()!='[')
                    return false;
                else 
                    st.pop();
            }
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};