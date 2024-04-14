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
    int sum=0;
    void sol(TreeNode* root){
        if(!root)return;
        if(root->left !=NULL && root->left->left==NULL && root->left->right==NULL){
            sum+=root->left->val;
        }
        sol(root->left);
        sol(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        sol(root);
        return sum;
    }
};