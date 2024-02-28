class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int llv=1;
        int cval=0;
        while(cval<label){
            cval+=llv;//15
            llv=llv*2;//16
        }
        llv=llv/2;
        vector<int>ans;
        while(label!=1){
            ans.push_back(label);
            int comp=(3*llv-label-1);
            int parent=comp/2;
            label=parent;
            llv/=2;
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};