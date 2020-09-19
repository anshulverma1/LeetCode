/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
Note that 1 does not map to any letters.

Example:
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

Time Complexity: O(4^N)
Space Complexity: O(4^N) //Could be done in O(1) using the return vector as a queue, but the concept of queue in important.
*/

class Solution {
public:
        
    vector<string> letterCombinations(string digits) 
    {
        vector<string> ref{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        
        if(digits == "")return res;
        queue<string> q;
        
        for(int i = 0; i < ref[digits[0] - '0'].length(); i++) 
        {
            string t = "";
            t += ref[digits[0] - '0'][i];
            q.push(t);
        }
        
        for(int i = 1; i < digits.length(); i++)
        {
            int ind = digits[i] - '0';
            string chars = ref[ind];
            int qLen = q.size();
            for(int j = 0; j < qLen; j++)
            {
                string temp = q.front(); q.pop();
                for(int k = 0; k < chars.length(); k++) q.push(temp + chars[k]);
            }
        }
        
        while(!q.empty())
        {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
