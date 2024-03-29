class Solution {
public:
    /*int solve(string &a,string &b,int i,int j,vector<vector<int>> &dp){
        if(a.length()==i){
            return 0;
        }
        if(b.length()==j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(a[i]==b[j]){
            ans=1+solve(a,b,i+1,j+1,dp);
        }
        else{
            ans=max(solve(a,b,i+1,j,dp),solve(a,b,i,j+1,dp));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }*/
    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>> dp(text1.length(),vector<int>(text2.length(),-1)); 
        // return solve(text1,text2,0,0,dp);
        int m=text1.length();
        int n=text2.length();
        int dp[m+1][n+1];
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
                if(i>0 && j>0){
                    if(text1[i-1]==text2[j-1]){
                        dp[i][j]=1+dp[i-1][j-1];
                    }
                    else{
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        }
        return dp[m][n];
    }
};