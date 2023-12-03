class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        //we can move diagnally and calculate by subtracting the points
        int count=0;
        auto p1= points[0];
        for(int i=1;i<points.size();i++){
            auto p2=points[i];
            int x=p2[0]-p1[0];
            int y=p2[1]-p1[1];
            //we will take the max of the above two for the moves to move
            count+=max(abs(x),abs(y));
            p1=p2;//to subtract the p3 from p2
        }
        return count;
    }
};