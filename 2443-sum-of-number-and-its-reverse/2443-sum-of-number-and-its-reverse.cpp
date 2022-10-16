class Solution {
public:
    int reverse(int n){
        int ans=0;
        while(n>0){
            ans=ans*10+n%10;
            n=n/10;
        }
        return ans;
    }
    bool sumOfNumberAndReverse(int num) {
       for(int i=0;i<=num;i++){
           int temp=reverse(i);
           if(i+temp==num){
               return true;
           }
       } 
        return false;
    }
};