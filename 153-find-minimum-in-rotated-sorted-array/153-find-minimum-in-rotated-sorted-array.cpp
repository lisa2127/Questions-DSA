class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        //checking if the array is rotated or not
        if(nums[e]>nums[0]){
            return nums[0];
        }
        while(s<e){
            int mid=s+(e-s)/2;
            if(nums[0]<=nums[mid]){
                s=mid+1;
            }
            else{
                e=mid;
            }
        }
        return nums[s];
    }
};