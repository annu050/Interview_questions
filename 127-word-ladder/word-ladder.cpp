class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>s(wordList.begin(),wordList.end());
        s.erase(beginWord);
        while(!q.empty()){
            string temp=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(temp==endWord)return steps;
            for(int i=0;i<temp.size();i++){
                char org=temp[i];
                for(char ch='a';ch<='z';ch++){
                    temp[i]=ch;
                    if(s.find(temp)!=s.end()){
                        s.erase(temp);
                        q.push({temp,steps+1});
                    }
                }
                temp[i]=org;
            }
        }
        return 0;

    }
};