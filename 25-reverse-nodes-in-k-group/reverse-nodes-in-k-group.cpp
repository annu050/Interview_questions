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

    int getlength(ListNode * head){
        int len=0;
        ListNode * temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        return len;
    }
    ListNode * rev(ListNode *head,int k,int len){
         if(head==NULL || len<k || head->next==NULL||k==1){
            return head;
        }
        //reverse first K nodes
        ListNode *next=NULL;
        ListNode *prev=NULL;
        ListNode *curr=head;
        int count=0;
        while(curr!=NULL && count<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        //reverse remaining nodes using recursion
        if(next!=NULL){
            head->next=rev(next,k,(len-k));
        }
        //return head of LL
        head=prev;
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len=getlength(head);
        return rev(head,k,len);
    }
};