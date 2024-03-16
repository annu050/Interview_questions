class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n=heights.size();
        int leftsm[n],rightsm[n];
        //finding left smaller
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty())leftsm[i]=0;
            else leftsm[i]=st.top()+1;
            st.push(i);
        }
        while(!st.empty())st.pop();

        //finding right smaller 
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty())rightsm[i]=n-1;
            else rightsm[i]=st.top()-1;
            st.push(i);
        }
        int maxa=0;
        for(int i=0;i<n;i++){
            maxa=max(maxa,heights[i]*(rightsm[i]-leftsm[i]+1));//r-l+1 gives us the width
        }
        return maxa;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m = matrix[0].size();
        
        vector<int> curr(m, 0);
        int maxArea = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '1') {
                    curr[j] += 1;
                } else {
                    curr[j] = 0;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(curr));
        }
        
        return maxArea;

    }
};