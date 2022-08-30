class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,set<int>> adj;
        for(int i=0;i<trust.size();i++){
            int u=trust[i][0];
            int v=trust[i][1];
            adj[u].insert(v);
        }
        int judge=-1;
        for(int i=1;i<=n;i++){
            if(adj[i].size()==0){
                judge=i;
                break;
            }
        }
        if(judge==-1){
            return -1;
        }
        for(int i=1;i<=n;i++){
            if(i==judge){
                continue;
            }
            if(!adj[i].count(judge)){
                return -1;
            }
        }
        return judge;
    }
};