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
    ListNode* removeZeroSumSublists(ListNode* head) {
        // maintain a prefix sum so at one pointif same prefix sum of 2 no. then there is a sum of 0
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        unordered_map<int,ListNode*>mp;//presfix sum and kis node pe hai vo sum
        mp[0]=dummy;
        ListNode* current=head;
        int currsum=0;
        while(head!=NULL){
            currsum+=head->val;
            if(mp.find(currsum)!=mp.end()){
                ListNode* start=mp[currsum];
                ListNode* temp=start;
                int psum=currsum;
                while(temp!=head){
                    temp=temp->next;
                    psum+=temp->val;
                    if(temp!=head){
                        mp.erase(psum);
                    }
                }
                start->next=head->next;
            }
            else{
                mp[currsum]=head;
            }
            head=head->next;
        }
        return dummy->next;
    }
};