class Solution {
public:

//recursive approach
    // int countpaths(int i,int j,int m,int n){
    //     if(i==n-1 && j==m-1){
    //         return 1;
    //     }
    //     if(i>=n || j>=m) return 0;
    //     else return countpaths(i+1,j,m,n)+countpaths(i,j+1,m,n);
    // }

    int uniquePaths(int m, int n) {
        int ni=m+n-2;
        int r=m-1;
        double res=1;
        for(int i=1;i<=r;i++){
            res=res*(ni-r+i)/i;
        }
        return (int)res;
    }
};