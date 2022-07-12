class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0|| s.length()==1){
            return s.length();
        }
        unordered_map<char,int> mp;
        int ans=0;
        int i=0;
        for(int j=0;j<s.length();j++){
            if(mp.find(s[j])!=mp.end()){
                i=max(i,mp[s[j]]+1);
            }
            mp[s[j]]=j;
            ans=max(ans,j-i+1);
            
        }
        return ans;
        
    }
};