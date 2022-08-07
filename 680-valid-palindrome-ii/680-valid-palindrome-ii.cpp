class Solution {
public:
    bool ispali(string &s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int st=0;
        int e=s.length()-1;
        while(st<e){
            if(s[st]!=s[e]){
                return ispali(s,st+1,e)||ispali(s,st,e-1);
            }
            st++;e--;
        }
        return true;
    }
};