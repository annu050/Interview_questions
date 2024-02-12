class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //if occur more than n/2 times then it should cross mid element too so sort the array first
        // sort(nums.begin(),nums.end());
        // int n=nums.size();
        // return nums[n/2];


        //moore's voting algorithm
        int el,cnt=0;
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                cnt=1;
                el=nums[i];
            }
            else if(nums[i]==el){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==el){
                cnt++;
            }
        }
        if(cnt>nums.size()/2){
            return el;
        }
        return -1;
    }
};

// int n = nums.size();
//         unordered_map<int, int> m;
        
//         for(int i = 0; i < n; i++){
//             m[nums[i]]++;
//         }
//         n = n/2;
//         for(auto x: m){
//             if(x.second > n){
//                 return x.first;
//             }
//         }
//         return 0;