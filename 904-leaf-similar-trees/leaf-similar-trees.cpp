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
    void leaves(TreeNode* root, vector<int> &v)
    {
        if(root!=NULL)
        {
            leaves(root->left, v);
            if(root->left == NULL && root->right == NULL)
            {
                v.push_back(root->val);
            }
            leaves(root->right,v);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a,b;
        leaves(root1,a);
        leaves(root2,b);
        return a==b;
        
    }
};