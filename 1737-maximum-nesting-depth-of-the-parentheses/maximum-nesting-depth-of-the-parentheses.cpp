class Solution {
public:
    int maxDepth(string s) {
        int n=s.length();
        int maxi=0;
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                int x=st.size();
                maxi=max(maxi,x);
                st.pop();
            }
        }
        return maxi;
    }
};