class Solution {
public:
    string largestGoodInteger(string num) {
       char ans=0;
        for(int i=2;i<num.length();i++){
            if(num[i-1]==num[i-2] && num[i]==num[i-1]){
                ans=max(ans,num[i]);
            }
        }
        if(ans==0){
            return "";
        }
        return string(3,ans);
    }
};