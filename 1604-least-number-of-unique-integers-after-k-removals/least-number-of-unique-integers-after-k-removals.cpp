class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>c;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            c[arr[i]]++;
        }
        //store the frequencies in the different array
        vector<int>v;
        int cnt=0;
        for(auto a:c){
            v.push_back(a.second);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            if(k>v[i]){
                k=k-v[i];
                v[i]=0;
            }
            else{
                v[i]=v[i]-k;
                k=0;
            }
            if(v[i]!=0)ans++;
        }
        return ans;
    }
};