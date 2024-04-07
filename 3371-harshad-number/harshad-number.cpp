class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int n=x;
        int ans,res=0;
        while(n!=0){
            ans=n%10;
            res=res+ans;
            n=n/10;
        }
        if(x%res==0){
            return res;

        }
        return -1;
    }
};