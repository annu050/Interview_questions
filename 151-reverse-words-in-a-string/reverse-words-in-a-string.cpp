class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string temp="";
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                temp+=s[i];
            }
            else if(s[i]==' ' && temp!=""){
                ans=temp+" "+ans; //this will add the previously added at the last 
                temp="";
            }
            else{
                continue;
            }
        }
        if(temp!=""){
            ans=temp+" "+ans; 
        }
        return ans.substr(0,ans.size()-1);
     
            
        
       
    }
};