class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        //TLE
        /*long long ans=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(i<j && j-i !=nums[j]-nums[i]){
                    ans++;
                }
            }
        }
        return ans;*/
        unordered_map<int,long long> mp;
        long long equal=0;
        long long n=nums.size();
        for(int i=0;i<nums.size();i++){
            mp[i-nums[i]]++;
        }
        for(auto &i:mp){
            equal+=((i.second*(i.second-1))/2);
        }
        long long total=(n*(n-1))/2;
        
        return total-equal;
    }
};