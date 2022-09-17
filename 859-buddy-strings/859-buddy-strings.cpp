class Solution {
public:
    bool buddyStrings(string s, string goal) {
        /*if(s.size()==1 || s.size()!=goal.size()){
            return false;
        }
        if(s==goal && s[0]!=s[1]){
            return false;
        }
        string temp=s;
        temp.erase(unique(temp.begin(),temp.end()),temp.end());
        string tempg=goal;
        tempg.erase(unique(tempg.begin(),tempg.end()),tempg.end());

        if(temp.size()==1 && tempg.size()==1){
            return true;
        }
        unordered_map<char,int> mp1,mp2;
        for(int i=0;i<s.size();i++){
            mp1[s[i]]=i;
            mp2[goal[i]]=i;
        }
        int cnt=0;
        for(auto i:mp1){
            int old=i.second;
            int curr=mp2[i.first];
            if(old!=curr){
                cnt++;
                if(cnt>2){
                    return false;
                }
            }
        }
        if(cnt==2){
            return true;
        }
        return false;*/
        if(s.size()!=goal.size()){
            return false;
        }
        if(s==goal){
            return (set<char>(s.begin(),s.end()).size() < s.size());
        }
        vector<int> diff;
        for(int i=0;i<s.size();i++){
            if(s[i]!=goal[i]){
                diff.push_back(i);
            }
        }
        return (diff.size()==2 && s[diff[0]]==goal[diff[1]] && s[diff[1]]==goal[diff[0]]);
        
    }
};