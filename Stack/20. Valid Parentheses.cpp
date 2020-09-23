/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
  1. Open brackets must be closed by the same type of brackets.
  2. Open brackets must be closed in the correct order.

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    bool isValid(string s) 
    {
        stack <char> st;
        unordered_map<char,char> mp = {{')','('}, {']','['}, {'}','{'}};
        for(int i=0;i<s.length();i++)
        {
            if( s[i]=='(' || s[i]=='[' || s[i]=='{')st.push(s[i]);
            else
            {
                if(!st.empty())
                {
                    if(st.top() == mp[s[i]])st.pop();
                    else return false;
                }
                else return false;
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};
