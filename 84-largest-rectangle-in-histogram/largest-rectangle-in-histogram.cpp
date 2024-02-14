class Solution {
public:
//find the right smaller and left smaller element for a single element
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n=heights.size();
        int leftsm[n],rightsm[n];
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
            maxa=max(maxa,heights[i]*(rightsm[i]-leftsm[i]+1));
        }
        return maxa;
    }
};