class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int c=0;
        sort(intervals.begin(),intervals.end());
        int temp=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(temp>intervals[i][0] ){
                c++;
                temp=min(temp,intervals[i][1]);
            }
            else{
                temp=intervals[i][1];
            }
        }
        return c;
    }
};