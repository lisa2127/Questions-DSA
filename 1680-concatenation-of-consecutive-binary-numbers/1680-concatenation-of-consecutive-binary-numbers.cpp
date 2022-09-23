class Solution {
public:
    int countBits(int n) {
		  return log2(n) + 1;
    }
    /*
    n=1  1
    n=2  1 10    1*pow(2,2)+2  6
    n=3  110 11  6*pow(2,2)+3  27
    */
    int concatenatedBinary(int n) {
        long ans = 0, MOD = 1e9 + 7;
        
        for (int i = 1; i <= n; ++i) {
            int len = countBits(i);
            ans = ((ans << len) % MOD + i) % MOD;
        }
        return ans;
    }
};