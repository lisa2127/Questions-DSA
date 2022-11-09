class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
       /* int j=0,i=0;
        long long ans=0,sum=0;
        set<int> s;
        while(j<nums.size()){
            sum+=nums[j];
            s.insert(nums[j]);
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                if(s.size()==k){
                    ans=max(ans,sum);
                    cout<< ans<<" ";
                    sum-=nums[i];
                    s.erase(nums[i]);
                    i++;
                    j++;
                }
                else{
                    sum-=nums[i];
                    s.erase(nums[i]);
                    i++;
                    j++;
                }
            }
        }
        return ans;*/
        unordered_map<int,int> mp;
        long long int sum=0,ans=0;
        int i=0;
        for(int j=0;j<nums.size();j++){
            mp[nums[j]]++;
            sum+=nums[j];
            if(j-i+1==k){
                if(mp.size()==k){
                    ans=max(ans,sum);
                }
                sum-=nums[i];
                mp[nums[i]]--;
                if(!mp[nums[i]]){
                    mp.erase(nums[i]);
                }
                i++;
            }
        }
        return ans;
    }
};