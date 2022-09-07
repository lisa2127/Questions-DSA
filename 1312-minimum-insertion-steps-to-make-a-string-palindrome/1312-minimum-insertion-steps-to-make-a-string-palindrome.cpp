class Solution {
public:
    int lps(string a,string b){
        int m=a.length();
        int n=b.length();
        int dp[m+1][n+1];
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                }
                if(i>0 && j>0){
                    if(a[i-1]==b[j-1]){
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
    int minInsertions(string s) {
        string revs=s;
        reverse(revs.begin(),revs.end());
        int ans=lps(s,revs);
        int sol=s.length()-ans;
        return sol;
    }
};