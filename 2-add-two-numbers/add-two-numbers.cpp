/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* root){
        ListNode* curr=root;
        ListNode* prev=NULL;
        ListNode* next;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        root=prev;
        return root;
    }

    void insertAtTail(ListNode* &head, ListNode* &tail, int val) {
        
        ListNode* temp = new ListNode(val);
        //empty list
        if(head == NULL) {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail -> next = temp;
            tail = temp;
        }
    }
    
   ListNode* add(ListNode* first, ListNode* second) {
        int carry = 0;
        
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        
        while(first != NULL || second != NULL || carry != 0) {
            
            int val1 = 0;
            if(first != NULL)
                val1 = first -> val;
                
            int val2 = 0;
            if(second !=NULL)
                val2 = second -> val;
            
            
            int sum = carry + val1 + val2;
            
            int digit = sum%10;
            
            //create node and add in answer Linked List
            insertAtTail(ansHead, ansTail, digit);
            
            carry = sum/10;
            if(first != NULL)
                first = first -> next;
            
            if(second != NULL)
                second = second -> next;
        }
        return ansHead;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=add(l1,l2);
        return ans;
        // int k=0,p=0,sum=0;
        // ListNode* add=NULL; 
        // // l1=reverse(l1);
        // // l2=reverse(l2);
        // while(l1!=NULL){
        //     k=k*10+l1->val;//30+4=34 340+2=342
        //     l1=l1->next;
        // }
        // while(l2!=NULL){
        //     p=p*10+l2->val;
        //     l2=l2->next;
        // }
        // sum=k+p;
        //         add= new ListNode;
        //         add->next=NULL;
        //     while(sum>0){
        //         sum=sum%10;
        //         add->val=sum;//7 0 8
        //         sum=sum/10; //80
        //         add=add->next;
        //     }
        
       
        // return add;


    }
};