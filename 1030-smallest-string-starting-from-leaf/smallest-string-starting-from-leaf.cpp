/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string ans="~";//it is like int max for string
    void path(TreeNode* root,string s){
        if(!root)return ;
        if(!root->left && !root->right){
            ans=min(ans,char(root->val+'a')+s);
        }
        path(root->left,char(root->val+'a')+s);
        path(root->right,char(root->val+'a')+s);
    }
    string smallestFromLeaf(TreeNode* root) {
        path(root,"");
        return ans;
    }
};