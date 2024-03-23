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
    void reorderList(ListNode* head) {
        ListNode* temp=head;
        stack<ListNode*>st;
        int size=0;
        while(temp!=NULL){
            size++;
            st.push(temp);
            temp=temp->next;
        }
        ListNode* start=head;
        for(int i=0;i<size/2;i++){
            ListNode* node=st.top();
            st.pop();
            node->next=start->next;
            start->next=node;
            start=start->next->next;
        }
        start->next=NULL;
    }
};