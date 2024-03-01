class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        // sort(s.rbegin(),s.rend());
        // for(int i=s.size()-1;i>=0;i--){
        //     if(s[i]=='1')swap(s[i],s[s.size()-1]);
        // }
        // return s;
        int cnt1=0,cnt0=0;
        for(auto x:s){
            if(x=='0')cnt0++;
            else cnt1++;
        }
        string ans=string(cnt1-1,'1')+string(cnt0,'0')+'1';
        return ans;
    }
};