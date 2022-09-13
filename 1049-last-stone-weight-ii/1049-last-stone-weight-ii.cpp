class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0;
        for(int i=0;i<stones.size();i++){
            sum+=stones[i];
        }
        int n=stones.size();
        bool dp[n+1][sum+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0){
                    dp[i][j]=0;
                }
                if(j==0){
                    dp[i][j]=1;
                }
                if(i>0 && j>0){
                    if(stones[i-1]<=j){
                        dp[i][j]=dp[i-1][j]||dp[i-1][j-stones[i-1]];
                    }
                    else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
        }
        for(int j=sum/2;j>=0;j--){
            if(dp[n][j]==true){
                return sum-2*j;
            }
        }
        return 0;
    }
};