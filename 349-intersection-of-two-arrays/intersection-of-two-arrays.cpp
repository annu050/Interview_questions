class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> a;
        vector<int> ans;
        for(int i:nums1){
            for(int j:nums2){
                if(i==j){
                    a.insert(i);
                }
            }
        }
        for(int i:a){
            ans.push_back(i);
        }
        return ans;
    }
};