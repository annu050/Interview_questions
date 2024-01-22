class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n+1,0);
        int m=0,d=0;
        for(int i=0;i<nums.size();i++){
            ans[nums[i]]++;
        }
        for(int i=1;i<ans.size();i++){
            if(ans[i]==2)d=i;
            if(ans[i]==0)m=i;
        }

        return {d,m};
    }
};