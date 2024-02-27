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
    TreeNode* prev,*first,*second;
    void inorder(TreeNode* root){
        if(!root)return;
        inorder(root->left);
        if(prev!=NULL && root->val<prev->val){
            if(first==nullptr){
                first=prev;
            }
            second=root;
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        //use of inorder to sort the tree
        if(!root)return;
        inorder(root);
        swap(first->val,second->val);

    }
};