class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> mp;
        for(int i=0;i<list1.size();i++){
            mp[list1[i]]=i;
        }
        vector<string> sol;
        map<int,vector<string>> temp;
        for(int i=0;i<list2.size();i++){
            if(mp.find(list2[i])!=mp.end()){
                int ind=mp[list2[i]]+i;
                temp[ind].push_back(list2[i]);
            }
        }
        int mini=INT_MAX;
        for(auto i: temp){
            if(i.first<=mini){
                mini=i.first;
                for(auto j:i.second){
                    sol.push_back(j);
                }
            }
        }
        return sol;
    }
};