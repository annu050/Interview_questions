class Solution {
public:
    string reverseOnlyLetters(string s) {
        string a=s;
        string ans="";
        stack<char> st;
        for(auto x:s){
            if(x>='a'&& x<='z' || x>='A' && x<='Z'){
                st.push(x);
            }
        }
        for(auto y:a){
            if(y>='a'&& y<='z' || y>='A' && y<='Z'){
                ans+=st.top();
                st.pop();
            }
            else{
                ans+=y;
            }
        }
        return ans;
    }
};