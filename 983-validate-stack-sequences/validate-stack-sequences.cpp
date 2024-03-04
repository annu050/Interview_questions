class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int pu=pushed.size();
        int po=popped.size();
        stack<int>st;
        int k=0;
        for(int i=0;i<pu;i++){
            if(pushed[i]!=popped[k]){
                st.push(pushed[i]);
            }
            else{
                if(pushed[i]==popped[k]){
                    st.push(pushed[i]);
                }
                while(!st.empty() && st.top()==popped[k]){
                    
                    st.pop();
                    k++;
                }
            }
            
        }
        return st.empty();
    }
};