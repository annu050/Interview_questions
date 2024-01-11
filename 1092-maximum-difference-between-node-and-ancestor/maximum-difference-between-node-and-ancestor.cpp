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
    int ans=0;
    void diff(TreeNode* root,int maxval,int minval){
        if(!root){
            return ;
        }
        ans=max(ans,max(abs(maxval-root->val),abs(minval-root->val)));
        minval = min(minval, root->val);
        maxval = max(maxval, root->val);
        diff(root->left,maxval,minval);
        diff(root->right,maxval,minval);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int maxval=root->val, minval=root->val;
        diff(root,maxval,minval);
        return ans;
    }
};