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
    int d(TreeNode* root,int* height){
        if(root==NULL){
            *height=0;
            return 0;
        }
        int lh=0,rh=0;
        int ld=d(root->left,&lh);
        int rd=d(root->right,&rh);
        int currdiam=lh+rh+1;
        *height=max(lh,rh)+1;
        return max(currdiam,max(ld,rd));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int height=0;
        int diam=d(root,&height);
        return diam-1;
    }
};