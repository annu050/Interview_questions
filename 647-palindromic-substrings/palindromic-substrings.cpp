class Solution {
public:
    bool ispalindrome(string ans){
        string q=ans;
        reverse(q.begin(),q.end());
        if(q==ans){
            return true;
        }
        return false;
    }
    int countSubstrings(string s) {
        int count = 0;

        for (int l = 0; l < s.size(); l++) {
            string ans = "";
            for (int r = l; r < s.size(); r++) {
                ans += s[r];
                if (ispalindrome(ans)) {
                    count++;
                }
            }
        }

        return count;
    }
};