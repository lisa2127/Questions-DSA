class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char,char> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]=t[i];
        }
        
        vector<int> arr;
        for(auto i:mp){
            arr.push_back(i.second);
        }
        int n=arr.size();
        sort(arr.begin(),arr.end());
        arr.erase(unique(arr.begin(),arr.end()),arr.end());
        int m=arr.size();
        if(n!=m){
            return false;
        }
        for(int i=0;i<s.length();i++){
            s[i]=mp[s[i]];
        }
        if(s.compare(t)==0){
            return true;
        }
        else{
            return false;
        }
    }
};