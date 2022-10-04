class Solution {
public:
    int kadaneForNonCircular(vector<int>& nums){
        int max_so_far=INT_MIN;
        int max_ending_here=0;
        for(int i=0;i<nums.size();i++){
            max_ending_here+=nums[i];
            if(max_ending_here>max_so_far){
                max_so_far=max_ending_here;
            }
            if(max_ending_here<0){
                max_ending_here=0;
            }
        }
        return max_so_far;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int nonCircularSum=kadaneForNonCircular(nums);
        int totalSum=0;
        for(int i=0;i<nums.size();i++){
            totalSum+=nums[i];
            nums[i]=-nums[i];
        }
        int circularSum=totalSum+kadaneForNonCircular(nums);
        if(circularSum==0){
            return nonCircularSum;
        }
        return max(circularSum,nonCircularSum);
    }
};