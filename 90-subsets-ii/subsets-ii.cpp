class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        int p=1<<n;
        vector<vector<int>> ans;
        unordered_set<string>seen;
        sort(nums.begin(),nums.end());
        for(int i=0;i<p;i++){
            vector<int>temp;
            string hash="";
            for(int j=0;j<n;j++){
                if((1<<j) & i){
                    temp.push_back(nums[j]);
                    hash+=to_string(nums[j]);
                }
            }
            if(seen.find(hash)==seen.end()){
                ans.push_back(temp);
                seen.insert(hash);
            }
        }
        return ans;
    }
};