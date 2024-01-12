class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> vowels={'a','e','i','o','u','A','E','I','O','U'};
        int c=0;
        int mid=s.length()/2;
        for(int i=0;i<mid;i++){
            char chara=s[i];
            char charb=s[mid+i];
            if(vowels.count(chara))c++;
            if(vowels.count(charb))c--;
        }
        return c==0;

    }
};