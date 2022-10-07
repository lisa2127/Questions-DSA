class Solution {
public:
    int solve(vector<int> nums,int x){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=x){
                cnt++;
            }
        }
        return cnt;
    }
    int specialArray(vector<int>& nums) {
        int s=0,e=nums.size();
        while(s<=e){
            int mid=s+(e-s)/2;
            int check=solve(nums,mid);
            if(check==mid){
               return mid;
            }
            else if(check>mid){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return -1;
    }
};