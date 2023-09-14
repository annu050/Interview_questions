class Solution {
public:
    void recurpermute(int index,vector<int>& nums,vector<vector<int>>& ans){
        if(nums.size()==index){
            ans.push_back(nums);
            return ;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            recurpermute(index+1,nums,ans);
            swap(nums[index],nums[i]);
    }
    
}

    vector<vector<int>> permute(vector<int>& nums) {
        //total permutation= n! 
        vector<vector<int>> ans;
        recurpermute(0,nums,ans);
        return ans;
        }
    
};