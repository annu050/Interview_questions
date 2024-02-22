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

    int maxLevelSum(TreeNode* root) {
        int currmax=INT_MIN;
        int maxlevel=0;
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int current_sum=0;
            ++level;
            for(int i=q.size();i>0;--i){
                TreeNode* n=q.front();
                q.pop();
                current_sum+=n->val;
                if(n->left!=NULL){
                    q.push(n->left);
                }
                if(n->right!=NULL){
                    q.push(n->right);
                }
            }
            if(current_sum>currmax){
                currmax=current_sum;
                maxlevel=level;
            }
        }
        return maxlevel;
    }
};