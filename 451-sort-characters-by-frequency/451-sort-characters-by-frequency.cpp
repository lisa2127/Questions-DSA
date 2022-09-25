class Solution {
public:
    static bool cmp(pair<char,int> &a,pair<char,int> &b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
       unordered_map<char,int> mp;
       for(int i=0;i<s.length();i++){
           mp[s[i]]++;
       }
        vector<pair<char,int>> freq;
        for(auto i:mp){
            freq.push_back(i);
        }
        string ans="";
        sort(freq.begin(),freq.end(),cmp);
        for(auto i:freq){
            for(int j=0;j<i.second;j++){
                ans+=i.first;
            }
        }
        return ans;
    }
};