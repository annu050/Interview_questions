class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        int num3=INT_MIN;
        // brute force mein O(N^3) and will give time complexity error
        stack<int>st;
        //first fix for num3 and num2 and if you find any no. less than num3 then return true
        for(int i=n-1;i>=0;i--){
            if(nums[i]<num3){
                return true;
            }
            while(!st.empty() && st.top()<nums[i]){
                num3=st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};