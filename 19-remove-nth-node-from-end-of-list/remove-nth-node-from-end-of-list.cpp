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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start=head;
        ListNode* ahead=head;
        while(n--){
            ahead=ahead->next;
        }
        if(ahead==NULL){
            return head->next;
        }
        while(ahead->next!=NULL){
            ahead=ahead->next;
            start=start->next;
            
        }
        ListNode* temp=start->next;
        start->next=start->next->next;
        delete(temp);
        return head;
    }
};