class Solution {
public:
    long long appealSum(string s) {
        int n=s.length();
        long long int ans=0;
        vector<int> dp(n+1,0);
        vector<int> index(26,-1);
        for(long long int i=0;i<s.size();i++){
            char ch=s[i]-'a';
            dp[i+1]=dp[i]+i-index[ch];
            ans+=dp[i+1];
            index[ch]=i;
        }
        return ans;
    }
};