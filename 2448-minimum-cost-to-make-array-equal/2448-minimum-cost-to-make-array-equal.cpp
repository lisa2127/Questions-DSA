class Solution {
public:
    long long solve(vector<int>& nums, vector<int>& cost,int mid){
         long long sum = 0;
            for(int i =0;i<nums.size();i++){
                long long k = abs(nums[i]-mid);
                sum+= k*cost[i];  
            }   return sum;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long s=0;
        long long e=1e6;
        while(s<=e){
            long long mid=s+(e-s)/2;
            long long sum1=solve(nums,cost,mid);
            if(s==e){
                return sum1;
            }
            long long sum2=solve(nums,cost,mid-1);
            long long sum3=solve(nums,cost,mid+1);
            if(sum2>=sum1 && sum1<=sum3){
                return sum1;
            }
            else if(sum2<sum1){
                e=mid;
                continue;
            }
            else if(sum3<sum1){
                s=mid;
                continue;
            }
        }
        return 0;
    }
};