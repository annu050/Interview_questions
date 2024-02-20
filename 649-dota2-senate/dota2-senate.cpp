class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>r,d;
        for(int i=0;i<senate.size();i++){
            if(senate[i]=='R'){
                r.push(i);
            }
            else{
                d.push(i);
            }
        }
        while(!r.empty() && !d.empty()){
            int ra=r.front();
            r.pop();
            int di=d.front();
            d.pop();
            if(ra<di){
                r.push(ra+senate.length());//add that removed element at end
            }
            else{
                d.push(di+senate.length());
            }
        }
        if(r.empty()){
            return "Dire";
        }
        else{
            return "Radiant";
        }
    }
};