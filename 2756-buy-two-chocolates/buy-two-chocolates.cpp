class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
       int n=prices.size();
        int maxi=0, diff=0,c=0;
        sort(prices.begin(),prices.end());
    int i=0,j=1;
        if(prices[i]+prices[j]<=money){
            diff=money-(prices[i]+prices[j]);
            return diff;
        }
       return money;

    }
};