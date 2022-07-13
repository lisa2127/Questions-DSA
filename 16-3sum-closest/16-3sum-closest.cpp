class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        int sumans=0;
        for(int i=0;i<nums.size()-2;i++){
            if(i==0 || i>0 && nums[i]!=nums[i-1]){
                int first=nums[i];
                int j=i+1;
                int k=nums.size()-1;
                while(j<k){
                int sum=first+nums[j]+nums[k];
                if(sum==target){
                    return sum;
                }
                else if(sum<target){
                    int element=abs(target-sum);
                    if(element<ans){
                        ans=element;
                        sumans=sum;
                    }
                    j++;
                }
                else{
                    int element=abs(target-sum);
                    if(element<ans){
                        ans=element;
                        sumans=sum;
                    }
                    k--;
                }
            }
        }
        }
        return sumans;
    }
};