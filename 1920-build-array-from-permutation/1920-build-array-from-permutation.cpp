class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        //Approach-1
        /*vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int element=nums[nums[i]];
            ans.push_back(element);
        }
        return ans;*/
        //Approach-2
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]+(nums[nums[i]]%nums.size())*nums.size();
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]/nums.size();
        }
        return nums;
    }
};