class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int i=0;
        int ans=0;
        int one=count(s.begin(),s.end(),'1');
        while(one){
            if(s[i]=='1'){
                one--;
                i++;
            }
            else{
                for(int j=i;j<s.size()-1;j++){
                    if(s[j]=='0'&& s[j+1]=='1'){
                        swap(s[j],s[j+1]);
                        j++;
                    }
                }
                ans++;
            }
        }
        return ans;
    }
};