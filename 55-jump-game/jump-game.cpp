class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxreach=0;
        for(int i=0;i<nums.size();i++){
            if(i>maxreach){
                return false;// if there is a case of 0 then for loop will go further but nums[i]=0 cant jump.
            }
            maxreach=max(maxreach,nums[i]+i);//to go to a reachable point in less time

        }
        return true;
    }
};