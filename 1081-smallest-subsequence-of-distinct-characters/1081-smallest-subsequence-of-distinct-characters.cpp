class Solution {
public:
    string smallestSubsequence(string s) {
        string ans="";
        unordered_map<char,int> mp;
        unordered_map<char,bool>vis;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }

        for(int i=0;i<s.length();i++){
            mp[s[i]]--;
            if(vis[s[i]]){
                continue;
            }
            while(!ans.empty() && ans.back()> s[i] && mp[ans.back()]>0){
                vis[ans.back()]=false;
                ans.pop_back();
                
            }
            vis[s[i]]=true;
            ans+=s[i];
        }
        return ans;
    }
};