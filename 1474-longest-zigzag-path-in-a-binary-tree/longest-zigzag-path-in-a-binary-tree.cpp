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
    int maxpath=0;
    void solve(TreeNode* root,int steps,bool goleft){
        if(root==NULL){
            return;
        }
        maxpath=max(maxpath,steps);
        if(goleft==true){
            solve(root->left,steps+1,false);//left ke baad instruct to go right by false variable
            solve(root->right,1,true);//if it didn't go right then start from beginning 1
        }
        else{
            solve(root->right,steps+1,true);
            solve(root->left,1,false);
        }
    }
    int longestZigZag(TreeNode* root) {
        //ek baar left jaayenge ek baaar right so detect that with dir when false-right true-left
        solve(root,0,true);
        solve(root,0,false);
        return maxpath;
    }
};