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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       //a dummy node if we have to reverse from start
       ListNode * dummy= new ListNode(0);
       dummy->next=head;
       ListNode * prev=dummy;
       ListNode * curr=head;
       for(int i=0;i<left-1;i++){//loop running 1 times acc to ex 1
           prev=prev->next;
           curr=curr->next;
       }
       ListNode * sub=curr;
       ListNode* pre=NULL;
       for(int i=0;i<=right-left;i++){
            ListNode* next = curr->next;
            curr->next = pre;
            pre=curr;
            curr=next;
       }
       prev->next=pre;
       sub->next=curr;
       return dummy->next;

        

        

    }
};