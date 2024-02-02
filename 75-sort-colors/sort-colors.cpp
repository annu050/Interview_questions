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

//dutch national flag
// int low=0,mid=0,high=nums.size()-1;
// while(mid<=high){
//     if(nums[mid]==0){
//         swap(nums[low],nums[mid]);
//         mid++;
//         low++;
//     }
//     else if(nums[mid]==1){
//         mid++;
//     }
//     else{
//         swap(nums[mid],nums[high]);
//         high--;
//     }
// }