class Solution{
    public:
    int sumSubarrayMins(vector<int>& arr){
        int n=arr.size();
        int MOD=1e9+7;
        vector<int> left(n),right(n);

        //left
        stack<int> st;
        st.push(0);
        left[0]=1;// distance = 1, left not found, this is distance multiplied with num, so it can't be zero
        for(int i=1;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                st.pop();
            }
            if(st.empty()){
                left[i]=i+1;
            }
            else{
                left[i]=i-st.top();
            }
            st.push(i);
        }
        //now empty the stack for the right side
        while(st.size()){
            st.pop();
        } 
        //right
        st.push(n-1);
        right[n-1]=1;
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(st.empty()){
                right[i]=n-i;
            }
            else{
                right[i]=st.top()-i;
            }
            st.push(i);
        }
        // total number of subarrays : (Left[i] * Right[i])
        // total contribution in A[i] element in final answer : (Left * Right) * A[i]
        int sum=0;
        for(int i=0;i<n;i++){
           long long  prod=(left[i]*right[i])%MOD;
           prod=(prod*arr[i])%MOD;
           sum=(sum+prod)%MOD;
        }
        return sum%MOD;
    }
};




//only 78 testcases passed out of 87 in o(n^2)complexity
// class Solution {
//       static constexpr int MOD = 1e9 + 7;
// public:

//     int sumSubarrayMins(vector<int>& arr) {
//         int min=0;
//         long sum=0;
//         for(int i=0;i<arr.size();i++){
//             min=arr[i];
//             for(int j=i;j<arr.size();j++){
//                 if(arr[j]<min){
//                     min=arr[j];
//                 }
//                 sum=(sum+min)%MOD;
//             }
//         }
//         return sum;
//     }
// };