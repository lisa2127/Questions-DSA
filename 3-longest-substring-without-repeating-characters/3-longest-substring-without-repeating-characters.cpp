class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.length()==0 || s.length()==1){
            return s.length();
        }
        int ans=0;
        for(int i=0;i<s.length();i++){
            vector<bool> visited(256);
            for(int j=i;j<s.length();j++){
                if(visited[s[j]]==true){
                    break;
                }
                else{
                    ans=max(ans,j-i+1);
                    visited[s[j]]=true;
                }
            }
            visited[s[i]]=false;
        }
        return ans;
    }
};