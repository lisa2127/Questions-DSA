class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        int i2=0;
        int i3=0;
        int i5=0;
        dp[0]=1;
        int multiple_2=2;
        int multiple_3=3;
        int multiple_5=5;
        int next=1;
        for(int i=1;i<n;i++){
            next=min(multiple_2,min(multiple_3,multiple_5));
            dp[i]=next;
            if(next==multiple_2){
                i2++;
                multiple_2=dp[i2]*2;
            }
            if(next==multiple_3){
                i3++;
                multiple_3=dp[i3]*3;
            }
            if(next==multiple_5){
                i5++;
                multiple_5=dp[i5]*5;
            }
            
        }
        return next;
    }
};