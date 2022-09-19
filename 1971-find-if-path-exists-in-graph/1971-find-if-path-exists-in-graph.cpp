class Solution {
public:
    void dfs(int node, unordered_map<int,list<int>> &adj,int destination,unordered_map<int,bool> &visited,int &cnt){
        visited[node]=true;
        if(node==destination){
            cnt++;
            return;
        }
        for(auto i:adj[node]){
            if(!visited[i]){
                dfs(i,adj,destination,visited,cnt);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,list<int>> adj;
        if(n==1){
            return true;
        }
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int cnt=0;
        unordered_map<int,bool> visited;
        dfs(source,adj,destination,visited,cnt);
        if(cnt==0){
            return false;
        }
        return true;
    }
};