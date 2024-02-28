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
class BSTIterator {
public:
    stack<TreeNode*>st;
    void pushall(TreeNode* root){
        //for(;root!=NULL ; st.push(root), root=root->left);
        while(root!=NULL){
            st.push(root);
            root=root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushall(root);
    }
    
    int next() {
        //tells inorder of the element
        //insert a roots left all elements into a stack and pop as we find next and if there is right present after traversing node then add that to the stack as well
        TreeNode* temp=st.top();
        st.pop();
        pushall(temp->right);
        return temp->val;

    }
    
    bool hasNext() {
        //tells if in inorder a root has next element present or not
        return !st.empty();
    }

};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */