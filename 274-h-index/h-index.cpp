class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size(),i;
        sort(citations.begin(),citations.end());// 0 1 3 5 6// std::less
        for(i=1;i<=citations.size();i++){
            if(citations[n-i]<i){ //at citations[3]=3 so as soon as we reach citations[2]=1 ans i=3 then we will break as we have already reached.
                break;
            }
        }
        return i-1;
    }
};