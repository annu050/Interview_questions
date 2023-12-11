class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int c=1,temp=arr[0];
        int res=0,ans=0;
        
        for(int i=1;i<arr.size();i++){
            if(temp==arr[i]){
                c++;
            }
            else{
                c=1;
            }
            if(c> arr.size()/4){
                return arr[i];
            }
           temp=arr[i];
        }
        return temp;
    }
};