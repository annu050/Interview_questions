class Solution {
public:
int ispalindrome(int s,int e,const string& c){
    int count=0;
    while(s>=0 && e < c.length() && c[s]==c[e]){
        s--;
        e++;
        count++;
    }
    return count;
}
   int countSubstrings(string s){
    if(s.length()==0)return 0;
    int n=s.length();
    int res=0;
    for(int i=0;i<n;i++){
        //for odd center(i,i)
        //for even center(i,i+1)
        res+=ispalindrome(i,i,s);
        res+=ispalindrome(i,i+1,s);   
    }
    return res;
}

};


//EXPAND AROUND THE CENTERS AND EXPAND
