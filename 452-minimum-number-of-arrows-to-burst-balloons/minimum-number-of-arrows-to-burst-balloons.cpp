class Solution {
public:
    static bool cmp(vector<int>v1,vector<int>v2)
{
        return v1[1]<v2[1];
}   
 int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int end=points[0][1];
        int c=1;
        for(int i=1;i<points.size();i++){
            if(points[i][0]>end){
                c++;
                end=points[i][1];
            }
        }
        return c;
    }
};