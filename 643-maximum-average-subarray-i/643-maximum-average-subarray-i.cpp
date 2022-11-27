class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=INT_MIN;
        double curravg=0;
        double sum=0;
        int i=0;
        int j=0;
        while(j<nums.size()){
            sum+=nums[j];
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                curravg=sum/k;
                ans=max(ans,curravg);
                sum=sum-nums[i];
                i++;
                j++;
            }
        }
        return ans;
    }
};
