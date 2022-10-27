class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans=INT_MIN;
        for(auto s:sentences){
            int n=count(s.begin(),s.end(),' ');
            ans=max(ans,n+1);
        }
        return ans;
    }
};