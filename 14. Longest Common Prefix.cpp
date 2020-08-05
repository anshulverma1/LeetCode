/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: ["dog","racecar","car"]
Output: ""

Note: All given inputs are in lowercase letters a-z.

Time Complexity: O(N)
Space Complexity: O(1) [Solution 1] / O(N) [Solution 2]
*/

//Solution 1
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string prefix="";
        if(strs.size()==0)  return prefix;
        
        for(int k=0; k<strs[0].size(); k++){
            int i=1;
            for(; i<strs.size() && strs[i].size()>k; i++){
                if(strs[i][k]!=strs[0][k])
                    return prefix;
            }
            if(i==strs.size()) prefix+=strs[0][k];
        }
        return prefix;
        
    }
};

//Solution 2 : Trie
struct trieNode
{
    int wordsHere;
    vector<trieNode*> children;
    trieNode()
    {
        wordsHere = 0;
        children.resize(26, nullptr);
    }
};



class Solution {
private:
    trieNode *root = new trieNode();
    void insert(string &word, trieNode* node)
    {
        for(char c : word)
        {
            if(!node->children[c - 'a']) node->children[c - 'a'] = new trieNode();
            node = node->children[c-'a'];
            node->wordsHere++;
        }
        
    }
    
    string getLCP(trieNode* node, int totalWords)
    {
        for(int i = 0; i < 26; i++)
        {
            if(node->children[i] && (node->children[i])->wordsHere == totalWords)
            {
                string res = (char)(i + 'a') + getLCP(node->children[i], totalWords);
                return res;
            }
        }
        return "";
    }

    
public:
    
    string longestCommonPrefix(vector<string>& strs) 
    {
        if(strs.size() == 0) return "";
        for(int i = 0; i < strs.size(); i++) insert(strs[i], root);
        return getLCP(root, strs.size());        
    }
};
