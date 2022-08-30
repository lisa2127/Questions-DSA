class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //Approach -1
        /*unordered_map<int,set<int>> adj;
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
        return judge;*/
        //Approach-2
        if(n==1 && trust.empty()){
            return 1;
        }
        vector<int> ind(n+1,0);
        vector<int> outd(n+1,0);
        for(auto i:trust){
            ind[i[1]]++;
            outd[i[0]]++;
        }
        for(int i=0;i<=n;i++){
            if(outd[i]==0 && ind[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};