class Solution {
public:
    int solve(vector<int> &temp){
        if(temp.size()==1){
            return temp[0];
        }
        int prev1=temp[0];
        int prev2=0;
        for(int i=1;i<temp.size();i++){
            int include=prev2+temp[i];
            int exclude=prev1;
            int curr=max(include,exclude);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> first,last;
        for(int i=0;i<n;i++){
            if(i!=n-1){
                last.push_back(nums[i]);
            }
            if(i!=0){
                first.push_back(nums[i]);
            }
        }
        return max(solve(first),solve(last));
    }
};