/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       if(head==NULL){
           return NULL;
       }
       unordered_map<Node*,Node*>ans;
       Node* curr=head;
       while(curr!=NULL){
           ans[curr]=new Node(curr->val);
           curr=curr->next;
       }
       curr=head;
       while(curr!=NULL){
           ans[curr]->next=ans[curr->next];
           ans[curr]->random=ans[curr->random];
           curr=curr->next;
       }
       return ans[head];
    }
};