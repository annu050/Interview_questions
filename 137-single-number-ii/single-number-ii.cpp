class Solution {
public:
    bool getbit(int n,int pos){
        return ((n & (1<<pos))!=0);
    }
    int setbit(int n,int pos){
        return (n | (1<<pos));
    }
    int unique(vector<int>&arr,int n){
        int res=0;
        for(int i=0;i<32;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                if(getbit(arr[j],i)){
                    sum++;
                }
            }
            if(sum%3!=0){
                res=setbit(res,i);
            }
        }
        return res;
    }
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        return unique(nums,n);
    }
};