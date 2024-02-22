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
    unordered_map<long,int>mp;
    int count=0;
    void countsum(TreeNode* root, int target,long sum){
        if(!root)return;
        sum+=root->val;
        if(sum==target)count++;
        if(mp.find(sum-target)!=mp.end()){
            count+=mp[sum-target];
        }
        mp[sum]++;
        countsum(root->left,target,sum);
        countsum(root->right,target,sum);
        mp[sum]--;//After visiting the left and right subtree, we have to reduce this path sum count from map since we are leaving this path

    }
    int pathSum(TreeNode* root, int targetSum) {
        countsum(root,targetSum,0);
        return count;
    }
};