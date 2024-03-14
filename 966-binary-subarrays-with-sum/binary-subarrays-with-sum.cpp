class Solution {
public:
    int atmost(vector<int>nums,int goals){
        int n=nums.size();
        int sum=0,l=0,ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>goals && l<=i){
                sum-=nums[l];
                l++;
            }
            ans+=i-l+1;//sizes of all subarrays
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        //TLE at end test case
        // int l=0,r=0;
        // int sum=0;
        // int cnt=0;
        // for(l=0;l<n;l++){
        //     int sum=0;
        //     for(r=l;r<n;r++){
        //         sum+=nums[r];
        //         if(sum==goal){
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt;
        // ..for this where we can't find ending cond.use this method
        // where extactly n=atmost(n)-atmost(n-1)
        // atmost n where find no. of subarrays where size=2 and 
        // exactly(2)=1 2 3 - 1 2 will give 3 as ans.
        // saari window ki size add and then subtract from those window sizes where subarray is not equal to goal
        return atmost(nums,goal)-atmost(nums,goal-1);
    }
};