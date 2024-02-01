class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& arr, int k) {
        int n=arr.size(),j=0;
        if (n % 3 != 0)
            return vector<vector<int>>();
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans(n/3, vector<int>(3));
        
        for(int i=0;i<n;i+=3){
            if (i + 2 < n && arr[i + 2] - arr[i] <= k) {
                ans[j] = { arr[i], arr[i + 1], arr[i + 2] };
                j++;
            }
            else {
                return vector<vector<int>>();
            }
        }
        return ans;

    }
};