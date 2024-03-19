class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int mp[26];
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]-'A']++;
        }
        priority_queue<int>p;
        for(int i=0;i<26;i++){
            if(mp[i]>0){
                p.push(mp[i]);
            }
        }
        int time=0;
        while(!p.empty()){
            vector<int>temp;
            for(int i=0;i<n+1;i++){
                if(!p.empty()){
                    int freq=p.top();
                    p.pop();
                    freq--;
                    temp.push_back(freq);
                }
                
            }
            for(int i=0;i<temp.size();i++){
                if(temp[i]>0){
                    p.push(temp[i]);
                }
            }
            if(!p.empty()){
                time+=n+1;
            }
            else{
                time+=temp.size();
            }
        }
        return time;
    }
};