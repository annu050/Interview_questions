class Solution {
public:
//greedy take maximum power to add when reducing score so sort to take that power from end and utilize small powers from front
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score=0,maxscore=0;
        int n=tokens.size();
        sort(tokens.begin(),tokens.end());
        int s=0,e=n-1;
        while(s<=e){
            if(power>=tokens[s]){
                power-=tokens[s];
                score+=1;
                s++;
                maxscore=max(maxscore,score);
            }
            else if(score>=1){
                score-=1;
                power+=tokens[e];
                e--;
            }
            else{
                return maxscore;
            }
        }
        return maxscore;
    }
};