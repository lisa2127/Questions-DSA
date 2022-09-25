class Solution {
public:
    static bool cmp(pair<int,int> &a,pair<int,int> &b){
        return a.second==b.second ? a.first>b.first : a.second<b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>> freq;
        for(auto i: mp){
            freq.push_back(i);
        }
        sort(freq.begin(),freq.end(),cmp);
        vector<int> result;
        for(auto i: freq){
            for(int j=0;j<i.second;j++){
                result.push_back(i.first);
            }
        }
        return result;
    }
};