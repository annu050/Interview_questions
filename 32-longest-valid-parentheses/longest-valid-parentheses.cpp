class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        int a=0,b=0,ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                a++;
            }
            else{
                b++;
            }
            if(a==b){
                ans=max(ans,a*2);
            }
            else if(b>a){
                a=0;
                b=0;
            }
        }
        a=0;
        b=0;
        for(int i=s.length()-1;i>=0;i--){
             if(s[i]=='('){
                a++;
            }
            else{
                b++;
            }
            if(a==b){
                ans=max(ans,a*2);
            }
            else if(a>b){
                a=0;
                b=0;
            }
        }
       return ans; 
    }
};