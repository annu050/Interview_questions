class Solution {
public:
    int pivotInteger(int n) {
        int tsum=0;
        for(int i=1;i<=n;i++){
            tsum+=i;
        }
        int presum=0;
        for(int i=1;i<=n;i++){
            presum+=i;
            if(tsum-presum+i==presum){
                return i;
            }
        }
        return -1;
    }
};