class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        //Approach-1
        /*vector<int> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[i]*nums[i]);
        }
        sort(ans.begin(),ans.end());
        return ans;*/
        //Approach-2
        vector<int> ans(nums.size(),0);
        int i=0;
        int k=nums.size()-1;
        int j=nums.size()-1;
        while(i<=j && k>=0){
            if(nums[i]*nums[i] > nums[j]*nums[j]){
                ans[k]=nums[i]*nums[i];
                k--;
                i++;
            }
            else{
                ans[k]=nums[j]*nums[j];
                j--;
                k--;
            }
        }
        return ans;
    }
};