class Solution {
public:
    int gcd(int a,int b){
        if(a==0){
            return b;
        }
        if(b==0){
            return a;
        }
        if(a==b){
            return a;
        }
        if(a>b){
            return gcd(a-b,b);
        }
        return gcd(a,b-a);
    }
    int commonFactors(int a, int b) {
        int n=gcd(a,b);
        int ans=0;
        for(int i=1;i<=n;i++){
            if(a%i==0 && b%i==0){
                ans++;
            }
        }
        return ans;
    }
};