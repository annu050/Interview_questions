class Solution {
public:
    int longestIdealString(string s, int k) {
        //time complexity error
        // int n=s.length();
        // vector<int> v(n,1);
        // int result=1;
        // for(int i=0;i<n;i++){
        //     for(int j=i-1;j>=0;j--){
        //         if(abs(s[i]-s[j])<=k){//lis s[j]<s[i]
        //             v[i]=max(v[i],v[j]+1);
        //         }
        //     }
        //     result=max(result,v[i]);
        // }
        // return result;
        int n=s.length();
        vector<int>v(26,0);
        int result=0;
        for(int i=0;i<n;i++){
            int curr=s[i]-'a';
            int left=max(0,curr-k);
            int right=min(25,curr+k);
            int longest=0;
            for(int j=left;j<=right;j++){
                longest=max(longest,v[j]);
            }
            v[curr]=max(v[curr],longest+1);
            result=max(result,v[curr]);
        }
        return result;
    }
};