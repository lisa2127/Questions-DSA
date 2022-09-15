class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(mp[arr[i]] && mp[arr[i]*2]){
                mp[arr[i]]--;
                mp[arr[i]*2]--;
            }
        }
        for(auto [a,b]:mp){
            if(b){
                return false;
            }
        }
        return true;
    }
};