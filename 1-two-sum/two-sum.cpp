class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //brute
        // vector<int> a;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]+nums[j]==target){
        //             a.push_back(i);
        //             a.push_back(j);//return {i,j}
        //             break;
        //         }
        //     }
        // }
       
        // return a;
//two pointer

 vector<pair<int, int>> v;
        vector<int> v2;
        pair<int, int> p;
        for(int i=0; i<nums.size(); i++){
            p.first = nums[i];
            p.second = i;
            v.push_back(p);
        }
        sort(v.begin(), v.end());
        auto it = v.begin(), it2 = v.end();
        it2 --;
        while(it < it2){
            int sum = it->first + it2->first;
            if(sum == target){
                v2.push_back(it->second);
                v2.push_back(it2->second);
                return v2;
            }
            else if(sum < target)
                it ++;
            else 
                it2 --;
        }
            
        return v2;
    }
};


//  unordered_map<int, int> cache;
//         vector<int> answer;
        
//         for (size_t i = 0; i < nums.size(); ++i)
//         {
//             int needed_num = target - nums[i];
            
//             if (cache.find(needed_num) != cache.end())
//             {
//                 // We found it
//                 answer.push_back(cache[needed_num]);
//                 answer.push_back(i);
//                 return answer;
//             }
//             else
//             {
//                 // Didn't find it
//                 cache.insert(make_pair(nums[i], i));
//             }
//         }
//         return answer;