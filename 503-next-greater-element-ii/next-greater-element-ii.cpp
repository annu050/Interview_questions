class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //we take 2n elements instead of single n
        int n=nums.size();
        vector<int>v(nums.size(),-1);
        stack<int>st;
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && nums[i%n]>=st.top()){
                st.pop();
            }
            if(!st.empty() && i<n){
                v[i]=st.top();
            }
            st.push(nums[i%n]);
        }
        return v;
    }
};