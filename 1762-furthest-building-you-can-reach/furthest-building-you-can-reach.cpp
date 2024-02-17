class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size(),i;
        priority_queue<int,vector<int>,greater<int>>jumps;
        for( i=0;i<n-1;i++){
            if(heights[i+1]<=heights[i] ){
                continue;
            }
            else{
                int b=heights[i+1]-heights[i];
                jumps.push(b);
                if (jumps.size() > ladders) {
                    int largest_jump = jumps.top();
                    jumps.pop();
                    if (largest_jump <= bricks) {
                        bricks -= largest_jump;
                    } 
                    else {
                        break;
                    }
                }
            }
            
        }
        return i;
    }
};