class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,0);
        stack<int>st;
        st.push(0);
        for(int i=1;i<n;i++){
            if(temperatures[st.top()]<temperatures[i]){
                while(!st.empty() && temperatures[st.top()]<temperatures[i]){
                    ans[st.top()]=i-st.top();
                    st.pop();
                }
            }
            st.push(i);
        }
        return ans;
    }
};