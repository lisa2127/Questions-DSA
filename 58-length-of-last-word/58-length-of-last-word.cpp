class Solution {
public:
    int lengthOfLastWord(string s) {
       int cnt=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                cnt++;
            }
            else{
                if(cnt>0){
                    ans=cnt;
                }
                cnt=0;
            }
        }
        if(cnt>0){
            return cnt;
        }
        else{
            return ans;
        }
        
    }
};