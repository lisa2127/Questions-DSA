class Solution {
public:
    bool isSubstring(string s1,string s2){
        if(s1.find(s2)!=string::npos){
            return true;
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        int ans=1;
        string s=a;
        while(s.size()<b.size()){
            s+=a;
            ans++;
        }
        if(isSubstring(s,b)){
            return ans;
        }
        if(isSubstring(s+a,b)){
            return ans+1;
        }
        return -1;
    }
};