class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //doing prefix and suffix sum 
        int n=nums.size(),prod=1;
        vector<int> ans(n),p(n),s(n);
        for(int i=0;i<n;i++){
            prod*=nums[i];//cumilitive product
            p[i]=prod;
        }
        prod=1;
        for(int i=n-1;i>=0;i--){
            prod*=nums[i];//cumilitive product
            s[i]=prod;
        }
        ans[0]=s[1];
        ans[n-1]=p[n-2];
        for(int i=1;i<n-1;i++){
            ans[i]=p[i-1]*s[i+1];
        }
        return ans;
    }
};