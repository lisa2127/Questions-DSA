class Solution {
public:
    bool canChange(string start, string target) {
        
        vector<pair<char,int>> v;
        for(int i=0;i<start.size();i++){
            if(start[i]== 'L' || start[i]=='R'){
                v.push_back({start[i],i});
            }
        }
        int i=0;
        for(int j=0;j<target.size();j++){
            if(target[j]== 'L' || target[j]=='R'){
                if(i>=v.size() || target[j]!=v[i].first){
                    return false;
                }
                else{
                    if(v[i].first=='L' && v[i].second<j){
                        return false;
                    }
                    if(v[i].first=='R' && v[i].second>j){
                        return false;
                    }
                    else{
                        i++;
                    }
                }
            }
        }
        return i==v.size();
    }
};