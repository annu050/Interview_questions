class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int subatmostk=atmostk(nums,k);//contain all the unique elements subarray till k i.e 1,12,121,1212,23,3 inka size 12-5=7
        int subrk=atmostk(nums,k-1);
        return (subatmostk-subrk);
    }
    int atmostk(vector<int>& nums,int k){
        int n=nums.size();
        unordered_map<int,int>mp;
        int l=0,ans=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0)mp.erase(nums[l]);
                l++;
            }
            ans+=i-l+1;
        }
        return ans;
    }
};