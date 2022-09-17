class Solution {
public:
    bool areAlmostEqual(string s, string goal) {
        if(s==goal){
            return true;
        }
        // if(s==goal){
        //     return (set<char>(s.begin(),s.end()).size() < s.size());
        // }
        vector<int> diff;
        for(int i=0;i<s.size();i++){
            if(s[i]!=goal[i]){
                diff.push_back(i);
            }
        }
        return (diff.size()==2 && s[diff[0]]==goal[diff[1]] && s[diff[1]]==goal[diff[0]]);
        
    }
};