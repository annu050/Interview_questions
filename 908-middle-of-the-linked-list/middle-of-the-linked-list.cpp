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
    ListNode* middleNode(ListNode* head) {
        int cnt=1;
        int pos;
        ListNode * temp=head;
        ListNode * temp1=head;
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }
         if(cnt%2!=0){
            pos=(cnt/2)+1;
            int p=1;
            while(p<pos){
                temp1=temp1->next;
                p++;
            }
            head=temp1;
        }
        else{
            pos=(cnt/2);
             int p=1;
            while(p<pos){
                temp1=temp1->next;
                p++;
            }
            head=temp1;
        }
        return head;
    }
};