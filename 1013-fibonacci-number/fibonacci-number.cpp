//by recursion
// class Solution {
// public:
//     int fib(int n) {
//         if(n<=1){
//             return n;
//         }
//         return fib(n-1)+fib(n-2);
//     }
// };


//by memoizatiom top down
// class Solution {
// public:
//     int ans(vector<int>&look,int n) {
//        if(look[n]==-1){
//            if(n<=1){
//                look[n]=n;
//            }
//            else{
//                look[n]=fib(n-1)+fib(n-2);
//            }
//        }
//        return look[n];
//     }
//     int fib(int n){
//         vector<int> look(n+1,-1);
//         return ans(look,n);
//     }
// };

//by tabulation bottom up
class Solution {
public:
    int fib(int n) {
        if(n==0){
            return 0;
        }
       int f[n+1];
       f[0]=0;
       f[1]=1;
       for(int i=2;i<=n;i++){
           f[i]=f[i-1]+f[i-2];
       }
       return f[n];
    }
};