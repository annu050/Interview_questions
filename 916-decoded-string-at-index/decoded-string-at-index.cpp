class Solution {
public:
    string decodeAtIndex(string s, int k) {
        //first calculate the size of the string that can be formed
        long long n = 0;
        for (char c : s) {
            if (isdigit(c)) {
                n *= (c - '0');
            } else {
                n++;
            }
        }
        string res="";
        // int ans=k%n;
        // if(ans==0){
        //     res+=s[0];
        //     return res;
        // }
        
        
        for(int i=s.length()-1;i>=0;i--){
            if(isdigit(s[i])){
                n=n/(s[i]-'0');
                k=k%n; //Reduce k to be within the current string length
            }
            else{
                if(k==0 || n==k){
                    res+=s[i];
                    return res;
                }
                n--;
            }
           
        }
        return res;
    }
};