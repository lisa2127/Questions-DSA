class Solution {
public:
    int mySqrt(int x) {
        long long int s=0;
        long long int e=x;
        long long int ans=-1;
        while(s<=e){
            long long int mid=s+(e-s)/2;
            if(mid*mid<=x){
                ans=mid;
                s=mid+1;
            }
            else if(mid*mid>x){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};