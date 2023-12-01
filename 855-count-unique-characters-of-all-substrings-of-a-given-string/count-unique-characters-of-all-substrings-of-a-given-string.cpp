class Solution {
public:
    int uniqueLetterString(string s) {
        //since 26 characters are there so create a hash map to store
        vector<vector<int>> hash(26);
        int n=s.size();
        for(int i=0;i<26;i++){
            //push -1 as starting index for all 26 char
            hash[i].push_back(-1);
        }
        //store index of each char inside map
        for(int i=0;i<n;i++){
            hash[s[i]-'A'].push_back(i);
        }
        //push last index to determine end of char in string
        for(int i=0;i<26;i++){
            hash[i].push_back(n);
        }
        //take sum from left side and right side
        long long sum=0;
        for(int i=0;i<26;i++){
            for(int j=1;j<hash[i].size()-1;j++){
                sum+=(hash[i][j]-hash[i][j-1])*(hash[i][j+1]-hash[i][j]);//left side* right side
            }
        }
        return sum;
    }
};


