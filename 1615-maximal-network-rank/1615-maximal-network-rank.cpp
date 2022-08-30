class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        //creating adjacency list
        unordered_map<int,set<int>> adj;
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            adj[u].insert(v);
            adj[v].insert(u);
        }
        int maxi=INT_MIN;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                count=adj[i].size()+adj[j].size();
                if(adj[i].count(j)){
                    count--;
                }
                maxi=max(maxi,count);
            }
        }
        return maxi;
    }
};