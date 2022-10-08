class Solution {
public:
     bool isPossible(vector<int> arr,int k,int mid){
        int count=1;
        int arrSum=0;
        for(int i=0;i<arr.size();i++){
            if(arrSum+arr[i]<=mid){
                arrSum+=arr[i];
            }
            else{
                count++;
                if(count> k || arr[i]>mid){
                    return false;
                }
                arrSum=arr[i];
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int s=0;
        int ans=-1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int e=sum;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isPossible(nums,k,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};