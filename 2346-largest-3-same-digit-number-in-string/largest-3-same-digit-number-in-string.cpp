class Solution {
public:
    string largestGoodInteger(string num) {
        char b;
        string a="";
        int c=1,ans=0,flag=0;
        for(int i=0;i<num.size()-1;i++){
            if(num[i]==num[i+1]){
                b=num[i];
                c++;
            }
            else{
                c=1;
            }
            if(c==3){
                c=1;
                ans=max((b-'0'),ans);
                flag=1;
            }
        }
        if(flag==0){
            return "";
        }
        a=to_string(ans);
        a=a+a+a;
        return a;
        
       
    }
};