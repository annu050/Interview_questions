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
    ListNode *mergetwolists(ListNode * l1,ListNode * l2){
        if(l1==nullptr){
            return l2;
        }
        if(l2==nullptr){
            return l1;
        }
        if(l1->val<=l2->val){
            l1->next=mergetwolists(l1->next,l2);
            return l1;
        }
        else{
            l2->next=mergetwolists(l1,l2->next);
            return l2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return nullptr;
        }
        while(lists.size()>1){
            lists.push_back(mergetwolists(lists[0],lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
};


//2 put in array ad sort then call convert function convert(arr) as this will retun the head of the linked list
//3 use of priority queue
// ListNode* mergeKLists(vector<ListNode*>& lists)
//     {
//         priority_queue<int,vector<int>,greater<int>>p;
//         for(int i=0;i<lists.size();i++)
//         {
//             ListNode*temp=lists[i];
//             while(temp!=NULL)
//             {
//                 p.push(temp->val);
//                 temp=temp->next;
//             }
//         }  
//         ListNode*ans=NULL;
//         ListNode*current=NULL;
//         if(!p.empty())
//         {
//             ans = new ListNode(p.top());
//             p.pop();
//             current = ans;
//         }
//         while(!p.empty())
//         {
//             ListNode*temp=new ListNode(p.top());
//             current->next=temp;
//             current=current->next;
//             p.pop();
            
//         }
//         return ans;
//     }