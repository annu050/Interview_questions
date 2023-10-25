class Solution {
public:
    bool checkIfPangram(string sentence) {
        for(char i='a';i<='z';i++){
            if(sentence.find(i)==string::npos){
                //if no position of the sentence[i] is found then return false
                return false;
            }
        }
        return true;
        
    }
};