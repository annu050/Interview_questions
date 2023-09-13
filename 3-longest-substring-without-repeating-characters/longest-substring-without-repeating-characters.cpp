class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n=s.length();
        if(n==0)
            return 0;
        set<char> st;
        int maxsize=0;
        int i=0,j=0;
        while(j<n)
        {
            if(st.count(s[j])==0)
            {
                st.insert(s[j]);
                maxsize=max(maxsize,(int)st.size());
                j++;
            }
            else
            {
                st.erase(s[i]);
                i++;
            }
        }
        return maxsize;




        
    //     int n=s.length();
    //     if(n==0)
    //         return 0;
    //     int start=0,end=0;
    //     int maxi=0;
    //     set<char> sets;
    //    while(start<s.size()){
    //        auto it=sets.find(s[start]);
    //         if(it==sets.end()){// if character not found in set then insert
    //             sets.insert(s[start]);
    //             maxi=max(maxi,(int)sets.size());
    //             start++;
    //         }
    //         else{//if found then erase as repeating
    //             sets.erase(s[start]);
    //             end++;
    //         }
    //     }
    //     return maxi;
    }
};