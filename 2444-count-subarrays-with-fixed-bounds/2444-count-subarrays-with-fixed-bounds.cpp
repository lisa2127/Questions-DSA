class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long int count=0;
        int high=-1,low=-1;
        int l=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=minK && nums[i]<=maxK){
                if(nums[i]==minK){
                    low=i;
                }
                if(nums[i]==maxK){
                    high=i;
                }
                if(high!=-1 && low !=-1){
                    count+=min(low,high)-l+1;
                }
            }
            else{
                l=i+1;
                low=-1;
                high=-1;
            }
        }
        return count;
    }
};