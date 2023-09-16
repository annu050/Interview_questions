class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int z=0,o=0,t=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                z++;
            }
            if(nums[i]==1){
                o++;
            }
            if(nums[i]==2){
                t++;
            }
        }
        int  i=0;
        while(z--){
            nums[i]=0;
            i++;
        }
        while(o--){
            nums[i]=1;
            i++;
        }
        while(t--){
            nums[i]=2;
            i++;
        }
        
    }
};