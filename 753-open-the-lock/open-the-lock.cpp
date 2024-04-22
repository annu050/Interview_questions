class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int n=deadends.size();
        unordered_set<string>dead(deadends.begin(),deadends.end());
        if(dead.find("0000")!=dead.end())return -1;
        int res=0;
        queue<string>q({"0000"});
        unordered_set<string>visited;
        while(!q.empty()){
            int levelsize=q.size();
            while(levelsize--){
                string up,down;
                string current=q.front();
                q.pop();
                if(current==target){
                    return res;
                }
                for(int i=0;i<4;i++){
                    up=down=current;
                    char upch=up[i],downch=down[i];
                    up[i]=(upch=='9'? '0': upch+1);
                    down[i]=(downch=='0'? '9': downch-1);
                    if(visited.find(up)==visited.end() && dead.find(up)==dead.end()){
                        q.push(up);
                        visited.insert(up);
                    }
                    if(visited.find(down)==visited.end() && dead.find(down)==dead.end()){
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
            res++;
        }
        return -1;
    }
};