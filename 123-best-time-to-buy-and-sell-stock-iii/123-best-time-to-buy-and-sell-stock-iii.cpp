class Solution {
public:
   int solve(vector<int>&prices, int day, int transactionsLeft, vector<vector<int>> &Memo){
        
        if(day == prices.size()){
            return 0;
        }
        
        if(transactionsLeft == 0){
            return 0;
        }
        
        int &ans = Memo[day][transactionsLeft]; 
        
        if(ans != -1){ 
            return ans;
        }
        
    
        int ans1 = solve(prices, day + 1, transactionsLeft, Memo);
        
        
         
        int ans2 = 0;
        bool buy = (transactionsLeft % 2 == 0);
        
        if(buy == true){ 
            ans2 = -prices[day] + solve(prices, day + 1, transactionsLeft - 1, Memo);
        }else{ // sell
            ans2 = prices[day] + solve(prices, day + 1, transactionsLeft - 1, Memo);
        }
        
        return ans = max(ans1, ans2); 
        
        
    }
    
    
    int maxProfit(vector<int>& prices) {
        
        vector<vector<int>> Memo(prices.size(), vector<int>(5, -1));
        int ans = solve(prices, 0, 4, Memo);
        return ans;
        
    }
};
