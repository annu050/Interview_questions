// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
class Solution {
public:
    TreeNode* find(TreeNode* root, int start){
        if(root==NULL){
            return NULL;
        }
        if(root->val==start){
            return root;
        }
        else{
            TreeNode* search=find(root->left,start);
            if(!search){
                search=find(root->right,start);
            }
            return search; 
        }
    }
    void findparent(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent){
        if(!root)return;
        if(root->left){
            parent[root->left]=root;
            
        }
        if(root->right){
            parent[root->right]=root;
            
        }
        findparent(root->left,parent);
        findparent(root->right,parent);
    }
    int amountOfTime(TreeNode* root, int start) {
        int time=0;
        unordered_map<TreeNode*,TreeNode*> parent;
        findparent(root,parent);//find parent of each node
        TreeNode* target=find(root,start);//find start node
        unordered_map<TreeNode*,bool>vis;
        queue<TreeNode*> q;
        q.push(target);

        vis[target]=true;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto front=q.front();
                q.pop();
                vis[front]=true;
                if(front->left and !vis[front->left]){
                    q.push(front->left);
                    vis[front->left]=true;
                }
                if(front->right && !vis[front->right]){
                    q.push(front->right);
                    vis[front->right]=true;
                }
                if(parent[front] && !vis[parent[front]]){
                    q.push(parent[front]);
                    vis[parent[front]]=true;
                }
                
            }
            time++;

        }
        return time-1;
        

    }
};
