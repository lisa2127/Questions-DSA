/*class Solution {
public:
    bool check(char s,unordered_map<char,int> &mp,char p){
        if(s=='=' || mp.find(p)==mp.end()){
            return true;
        }
        return false;
    }
    bool equationsPossible(vector<string>& equations) {
        int cnt=0;
        unordered_map<char,int> mp;
        for(int i=0;i<equations.size();i++){
            string temp=equations[i];
            mp[temp[0]]++;
            if(check(temp[1],mp,temp[0])){
                cnt++;
            }
        }
        if(cnt==equations.size()){
            return true;
        }
        return false;
        
    }
};*/

class Solution {
    int uf[26];
    int find(int x) {
        return uf[x] == x ? x : (uf[x] = find(uf[x]));
    }
public:
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; ++i) uf[i] = i;
        for (auto e : equations) {
            if (e[1] == '=') uf[find(e[0] - 'a')] = find(e[3] - 'a'); 
        }
        for (auto e : equations) {
            if (e[1] == '!' && find(e[0] - 'a') == find(e[3] - 'a')) return false;
        }
        return true;
    }
};