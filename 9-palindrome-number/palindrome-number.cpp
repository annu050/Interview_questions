class Solution {
public:
    bool isPalindrome(int x) {
        string a = to_string(x);
        string s=a;
        reverse(a.begin(),a.end());
        if(s==a)
        {
            return true;
        }
        else{
            return false;
        }
    }
};