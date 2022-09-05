class Solution {
public:
     int M = 1e9+7;
    
    int f(int s, int e, int k, vector<vector<int>> &dp){
		// base condition
        if(k==0) {
            if(s==e) {
                return 1;
            }
            else return 0;
        }
        
        if(abs(e-s)>k) return 0;
        if(dp[s+1000][k] != -1) {
            return dp[s+1000][k]%M;
        }
        
        
        int left = f(s-1, e, k-1, dp)%M;
        int right = f(s+1, e, k-1, dp)%M;
        
        return dp[s+1000][k] = (left + right)%M;
    }
    
    int numberOfWays(int s, int e, int k) {
        vector<vector<int>> dp(3000, vector<int>(k+1, -1));
        return f(s, e, k, dp);
    }
};