class Solution {
public:
    bool canform(string word,vector<int> c){
        vector<int> anu(26,0);
        for(char ch : word){
            int x=ch-'a';
            anu[x]++;
            if(anu[x]>c[x]){
                return false;
            }

        }
        return true;
    }
    int countCharacters(vector<string>& words, string chars) {
        vector<int> c(26,0);
        for(char ch: chars){
            c[ch-'a']++;
        }
        int sum=0;
        for(auto x: words){
            if(canform(x,c)){
                sum+=x.length();
            }  
        }
        return sum;

        // int sum=0;
        // for(int i=0;i<words.size();i++){
        //     string anu=words[i];
        //     int c=0;
        //     for(auto x:anu){
        //         for(auto y: chars){
        //             if(x==y){
        //                 c++;
        //                 break;
        //             }
        //         }
        //         if (c==anu.size()){
        //             sum+=c;
        //         }
        //     }
        // }
        // return sum;
    }
};