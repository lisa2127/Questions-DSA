class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n=s.length();
        vector<char> ans(n);
        for(int i=0;i<s.length();i++){
           ans[indices[i]]=s[i]; 
        }
        string str(ans.begin(),ans.end());
        return str;
    }
};