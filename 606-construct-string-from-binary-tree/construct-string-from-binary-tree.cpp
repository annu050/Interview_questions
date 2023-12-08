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
    void st(stringstream &ans,TreeNode* temp){
        if(temp==NULL){
           return; 
        }
        
        ans<<temp->val;
        if(temp->left!=NULL || temp->right!=NULL){
            ans<<"(";
            st(ans,temp->left);
            ans<<")";
        }
        if(temp->right!=NULL){
            ans<<"(";
            st(ans,temp->right);
            ans<<")";
        }
        
        
    }
    string tree2str(TreeNode* root) {
        TreeNode* temp=root;
        stringstream ans;
        st(ans,temp);
        return ans.str();
    }
};