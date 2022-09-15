class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans;
        if(changed.size()%2){
            return ans;
        }
        unordered_map<int,int> mp;
        for(int i=0;i<changed.size();i++){
            mp[changed[i]]++;
        }
        sort(changed.begin(),changed.end());
        for(int i=0;i<changed.size();i++){
            if(mp[changed[i]]){
                mp[changed[i]]--;
                ans.push_back(changed[i]);
                if(mp[changed[i]*2]){
                    mp[changed[i]*2]--;
                }
                else{
                    return vector<int>();
                }
            }
        }
        return ans;
    }
};