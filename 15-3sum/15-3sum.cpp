class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sol;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i==0 || i>0 && nums[i]!=nums[i-1]){
                
            int first=nums[i];
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
            if(nums[j]+nums[k]+first==0){
                sol.push_back({nums[i],nums[j],nums[k]});
                
                while(j<k && nums[j]==nums[j+1]){
                    j++;
                }
                while(j<k && nums[k]==nums[k-1]){
                    k--;
                }
                k--;
                j++;
                
            }
            else if(first+nums[j]+nums[k]>0){
                k--;
            }
            else{
                j++;
            } 
           
        }
      }
    }
        return sol;
    }
};