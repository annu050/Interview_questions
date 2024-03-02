class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>a(nums.size());
        // for(int i=0;i<nums.size();i++){
        //     a.push_back(nums[i]*nums[i]);
        // }
        // sort(a.begin(),a.end());
        // return a;

        // O(N) Solution
        int l=0,r=nums.size()-1;
        for(int k=nums.size()-1;k>=0;k--){
            if(abs(nums[r])>abs(nums[l])){
                a[k]=nums[r]*nums[r];
                r--;
            }
            else{
                a[k]=nums[l]*nums[l];
                l++;
            }
        }
        return a;
        
    }
};