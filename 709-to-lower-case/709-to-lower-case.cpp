#include<algorithm>
class Solution {
public:
    string toLowerCase(string s) {
       string ans;
        for(int i=0;i<s.length();i++){
            char v=tolower(s[i]);
            ans=ans+v;
        }
        return ans;
    }
};