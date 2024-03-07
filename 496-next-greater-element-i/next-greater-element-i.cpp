class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        unordered_map<int,int>mp;
        for(auto x:nums2){
            while(!st.empty() && st.top()<x){
                mp[st.top()]=x;
                st.pop();
            }
            st.push(x);
        }
        vector<int>ans;
        for(int n:nums1){
            ans.push_back(mp.count(n)?mp[n]:-1);
        }
        return ans;

    }
};