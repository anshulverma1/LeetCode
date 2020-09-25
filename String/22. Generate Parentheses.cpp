/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

Time Complexity: O(4^N)
Space Complexity: O(4^N)
*/

class Solution {
public:
    void genPar(vector<string> &res, string &temp, int open, int closed, int max)
    {
        if(open == max && closed == max)
        {
            res.push_back(temp);
            return;
        }
        if(open < max)
        {
            temp.push_back('(');
            genPar(res, temp, open+1, closed, max);
            temp.pop_back();
        }
        if(closed < open)
        {
            temp.push_back(')');
            genPar(res, temp, open, closed+1, max);
            temp.pop_back();
        }
    }    
    
    
    vector<string> generateParenthesis(int n) 
    {
        vector<string> res;
        string temp = "";
        genPar(res, temp, 0, 0, n);
        return res;
    }
};
