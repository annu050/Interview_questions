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
       if(!head){
           return nullptr ;
       }
       Node* curr=head;
       while(curr){
           Node* newn=new Node(curr->val);
           newn->next=curr->next;
           curr->next=newn;
           curr=newn->next;
       }
       curr=head;
       while(curr){
           if(curr->random){
               curr->next->random=curr->random->next;
           }
           curr=curr->next->next;
       }
       Node* oldhead=head;
       Node* newhead=head->next;
       Node* currold=oldhead;
       Node* currnew=newhead;
       while(currold){
           currold->next=currold->next->next;
           currnew->next=currnew->next ? currnew->next->next:nullptr;
           currold = currold->next;
           currnew=currnew->next; 
       }
       return newhead;
    }
};

// if(head==NULL){
//            return NULL;
//        }
//        unordered_map<Node*,Node*>ans;
//        Node* curr=head;
//        while(curr!=NULL){
//            ans[curr]=new Node(curr->val);
//            curr=curr->next;
//        }
//        curr=head;
//        while(curr!=NULL){
//            ans[curr]->next=ans[curr->next];
//            ans[curr]->random=ans[curr->random];
//            curr=curr->next;
//        }
//        return ans[head];