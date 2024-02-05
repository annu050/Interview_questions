class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        // use a hash map to store all the indices at which an element occurs
        unordered_map<int, vector<int>> mp;

        // store the sum from beginning to current position in the sum vector
        vector<long long> sum(n);
        
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
            if(i == 0) sum[i] = nums[i];
            else sum[i] = sum[i-1] + nums[i];
        }
        
        // Initialize mx to a very small value
        double mx = LONG_MIN + 100;
        
        // Now find the required target such that the difference between target and nums[i] is k
        // Turns out there are 2 such possible targets for nums[i]
        // Target 1 = nums[i] + k
        // Target 2 = nums[i] - k
        
        for(int i=0; i<n; i++){
            int target = nums[i] + k;
            
            // for this target iterate through all the positions at which it occurs
            for(auto ind: mp[target]){
                
                // if index > i only then take the maximum of (sum till index - sum till i + current element)
                if(ind > i) mx = max(mx, (double)sum[ind] - sum[i] + nums[i]);
            }
            
            // do the above process again for Target 2
            target = nums[i] - k;
            for(auto ind: mp[target]){
                if(ind > i) mx = max(mx, (double)sum[ind] - sum[i] + nums[i]);
            }
        }
        
        // return 0 if no such subarray is found 
        if(mx == LONG_MIN + 100) return 0;
        
        // else return the max sum found
        return mx;
    }
};