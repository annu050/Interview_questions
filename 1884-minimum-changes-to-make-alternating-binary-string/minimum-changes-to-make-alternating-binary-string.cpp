class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int c=0;
        if(n==1)return 0;
        for(int i=0;i<n;i++){
            if(i%2==0 && s[i]=='1')c++;//1
            if(i%2==1 && s[i]=='0')c++;//1
        }
        return min(c,n-c);//n-c is for 1010 ...series
        
    }
};