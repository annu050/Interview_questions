class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int a=0,b=0;
        if(n==1){
            return nums[0];
        }
        for(int i=0;i<n-1;i++){
            if(i%2==0){
                a=max(nums[i]+a,b);
            }
            else{
                b=max(nums[i]+b,a);
            }
        }
        int ans=max(a,b);
        a=0;
        b=0;
        for(int i=1;i<n;i++){
            if(i%2==0){
                a=max(nums[i]+a,b);
            }
            else{
                b=max(nums[i]+b,a);
            }
        }
        ans=max(ans,a);
        ans=max(ans,b);
        return ans;
    }
};