class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int n = nums.size();
        std::vector<int> dp(n, 1);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        return *std::max_element(dp.begin(), dp.end());
    }
};









//23 test cases passed
// class Solution {
// public:
// int removeDuplicates(vector<int> &Y)
// {
//     int k = 0;
//     for (int i = 1; i < Y.size(); i++)
//     {
//         if (Y[i] != Y[k]) {
//             Y[++k] = Y[i];
//         }
//     }
 
//     // return length of subarray containing all distinct characters
//     return k + 1;
// }
// int lis(vector<int>&arr,vector<int>&sa,int m,int n){
//     if(m==0||n==0){
//         return 0;
//     }
//     if(arr[m-1]==sa[n-1]){
//         return 1+lis(arr,sa,m-1,n-1);
//     }
//     else{
//         return max(lis(arr,sa,m-1,n),lis(arr,sa,m,n-1));
//     }
// }
//     int lengthOfLIS(vector<int>& nums) {
//     int m=nums.size();
//     int n=m;
//     vector<int>sa(nums);
//     sort(sa.begin(),sa.end());
//     n = removeDuplicates(sa);
//     int a=lis(nums,sa,m,n);
//     return a;
//     }
// };