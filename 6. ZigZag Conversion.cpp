/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);

Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    string convert(string s, int numRows) 
    {  
        if(numRows == 1) return s;
        vector<string> T(numRows, "");
        string res = "";
        int dir = 0, row = 0;
        for(int i = 0; i < s.length(); i++)
        {
            T[row]+=(s[i]);
            if(dir == 0 && row == numRows-1) dir = 1;
            else if(dir == 1 && row == 0) dir = 0;
            if(dir == 0) row++;
            else row--;
        }
        for(int i = 0; i < numRows; i++) res+=T[i];
        return res;
        
    }
};
