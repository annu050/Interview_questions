class Solution {
public:
    string simplifyPath(string path) {
        int n=path.size();
        stack<string>st;
        
        int i=0;
        while(i<n){
            while(i<n && path[i]=='/'){
                i++;
            }
            string ans="";
            while( i<n && path[i]!='/'){
                ans+=path[i];
                i++;
            }
            if(ans==".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else if(ans!="." && !ans.empty()){
                st.push(ans);
            }

            
        }
        string str="";
        while(!st.empty()){
            str="/"+st.top()+str;
            st.pop();
        }
        return str.empty() ? "/": str;
    }
};
