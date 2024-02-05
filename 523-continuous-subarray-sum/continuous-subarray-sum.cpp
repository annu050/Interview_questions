class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int sum=0,rem=0;
        mp.insert(make_pair(0, -1));
        for(int i=0;i<n;i++){
            sum+=nums[i];
            rem=sum%k;
            if(mp.find(rem)!=mp.end()){
                if(i-mp[rem]>=2){
                    return true;
                }
            }
            mp.insert(make_pair(rem,i));
        }
        return false;
    }
};