class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int p=0,e=n-1;
        while(p<e){
            char prefix=s[p];
            char end=s[e];
            if(prefix==end){
                while(p<=e && s[p]==prefix){
                    p++;
                }
                while(p<e && s[e]==end){
                    e--;
                }

            }
            else{
                break;
            }

        }
        
        return e-p+1;

    }
};