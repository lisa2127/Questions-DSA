class Solution {
public:

    bool solve(vector<int> &nums,int n,int pos,int sum){
     
        bool dp[n+1][sum+1];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0 || j==0){
                    dp[i][j]=false;
                }
                else if(nums[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }
                else if(nums[i-1]==j){
                    dp[i][j]=true;
                }
                else{
                    dp[i][j]= (dp[i-1][j]|| dp[i-1][j-nums[i-1]]);
                }
            }
        }
        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
         int n=nums.size();
         int sum=0;
           
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2==1){
            return false;
        }
        
        return solve(nums,n,0,sum/2);
    }
};