class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string p=" ";
        int flag=0;
        for(int i=0;i<words.size();i++){
            if(words[i]!=" "){
                p=words[i];
                reverse(words[i].begin(),words[i].end());
                if(words[i]==p){
                    flag=1;
                    break;
                }
            }
        }
        return flag==0?"":p;
       
    }
};