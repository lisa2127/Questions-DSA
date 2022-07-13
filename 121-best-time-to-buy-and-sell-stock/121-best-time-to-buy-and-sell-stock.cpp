class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int max_profit=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>mini){
                max_profit=max(max_profit,prices[i]-mini);
            }
        else{
            mini=min(prices[i],mini);
        }
    }
         return max_profit;
    }
};