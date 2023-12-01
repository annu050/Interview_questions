class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string aa="";
        string bb="";
        for(string x:word1){
            aa+=x;
        }
        for(string x:word2){
            bb+=x;
        }
        if(aa==bb){
            return true;
        }
        else{
            false;
        }
        return false;
    }
};