class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        do{
            //move slow once and fast twice
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        fast=nums[0];
        while(slow!=fast){
            //after this move slow and fast only once so we can find the duplicate
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};