class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int c=0,mini=0;
        int n=target.size();
        stack<int>st;
        int min=target[0];
        st.push(min);
        int ans=min;
        for(int i=1;i<n;i++){
            if(!st.empty() && st.top()<target[i]){
                int diff=target[i]-st.top();
                ans+=diff;
                st.pop();
            }
            st.push(target[i]);
        }
        return ans;
    }
};