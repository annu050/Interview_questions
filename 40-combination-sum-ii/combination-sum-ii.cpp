class Solution {
public:
    void sol(int ind,int target,vector<int>& c,vector<vector<int>>&ans,vector<int>&ds){
        
        if(target==0){
            ans.push_back(ds);
            return;
        }
        
        for(int i=ind;i<c.size();i++){
            if(i>ind && c[i]==c[i-1]){
                continue;//if the no is same at the indexes we don't take them again 
            }
            if(c[i]>target)break;//
            ds.push_back(c[i]);
            sol(i+1,target-c[i],c,ans,ds);
            ds.pop_back();

        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());//so that we pick in sorted order i.e will come in lexicographical order
        vector<vector<int>>ans;
        vector<int>ds;
        sol(0,target,candidates,ans,ds);
        return ans;
    }
};