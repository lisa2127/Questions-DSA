class Solution {
public:
    int solve(vector<int> nums,int x){
        for(int i=0;i<nums.size();i++){
            if(nums[i]>x){
                return nums[i];
            }
        }
        return -1;
    }
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size());
        stack<int> s;
        s.push(INT_MAX);
        for(int i=nums.size()-1;i>=0;i--){
            while(s.top()!=INT_MAX && nums[i]>=s.top()){
                s.pop();
            }
            ans[i]=s.top();
            s.push(nums[i]);
        }
        for(int i=ans.size()-1;i>=0;i--){
            if(ans[i]==INT_MAX){
                ans[i]=solve(nums,nums[i]);
            }
        }
        return ans;
    }
};