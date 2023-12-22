class Solution {
public:
    int maxScore(string s) {
        int left=0,maxi=0;
        int right=count(s.begin(),s.end(),'1');
        for(int i=0;i<s.length()-1;i++){//as we cannot have empty subset
            left+=(s[i]=='0');
            right-=(s[i]=='1');
            maxi=max(maxi,left+right);
        }
        return maxi;
        // int maxi=0,z=0,o=0;
        // string left="";
        // for(int i=0;i<s.size();i++){
        //     o=0;
        //     z=0;
        //     left+=s[i];
        //     for(int k=0;k<left.size();k++){
        //         if(left[k]=='0'){
        //             z++;
        //             continue;
        //         }
        //     }
        //     for(int j=i+1;j<s.size();j++){
        //         if(s[j]==1){
        //             o++;
        //             continue;
        //         }
        //     }
        //     maxi=max(maxi,(z+o));
        // }
        // return maxi;
    }
};