class Solution {
public:
    string minWindow(string s, string t) {
        //sliding window problem
        if(t==""){
            return "";
        }
        unordered_map<char,int> countt;
        unordered_map<char,int> window;
        for(int i=0;i<t.length();i++){
            countt[t[i]]++;
        }
        int have=0,need=countt.size();//distinct character size
        int ans_size=INT_MAX;//length of min. window substring
        vector<int> ans;//to store the indices of substring
        int left=0;
        //iterate through right pointer
        for(int right=0;right<s.length();right++){
            window[s[right]]++;
            if(countt.find(s[right])!=countt.end() && window[s[right]] == countt[s[right]]){
                have++;
            }
            while(have==need){
                if((right-left+1)<ans_size){
                    ans={left,right};
                    ans_size=right-left+1;
                }
                // Decrease the count of the character going out of the window
                window[s[left]]--;
                // If the character is a part of string t and its count in the window becomes less than its count in t, decrease the have count
                if(countt.find(s[left])!=countt.end() && window[s[left]]<countt[s[left]]){
                    have--;
                }
                left++;//shrink the sliding window
            }
        }
        return ans_size!=INT_MAX? s.substr(ans[0],ans[1]-ans[0]+1):"";

    }
};