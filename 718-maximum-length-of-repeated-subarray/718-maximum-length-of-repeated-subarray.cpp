class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        //Longest common substring type
        int n=nums1.size();
        int m=nums2.size();
        int dp[n+1][m+1];
        int ans=0;
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                }
                if(i>0 && j>0){
                    if(nums1[i-1]==nums2[j-1]){
                        dp[i][j]=dp[i-1][j-1]+1;
                        ans=max(ans,dp[i][j]);
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
            }
        }
        return ans;
    }
};