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
    int findBottomLeftValue(TreeNode* root) {
        //by bfs
        queue<TreeNode*>q;
        TreeNode* curr=root;
        q.push(curr);
        int maxdepth=-1,depth=0,blv=0;
        while(!q.empty()){
            int n=q.size();
            depth++;
            while(n--){
                curr=q.front();
                q.pop();
                if(maxdepth<depth){
                    maxdepth=depth;
                    blv=curr->val;
                }
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL)q.push(curr->right);
            }
        }
        return blv;
    }
};