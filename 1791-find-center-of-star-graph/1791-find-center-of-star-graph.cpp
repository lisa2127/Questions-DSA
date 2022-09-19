class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        unordered_map<int,list<int>> adj;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int m=adj.size();
        vector<int> degree(m+1,0);
        for(int i=1;i<=m;i++){
            for(auto j:adj[i]){
                degree[j]++;
            }
        }
        for(int i=0;i<degree.size();i++){
            if(degree[i]==m-1){
                return i;
            }
        }
        return -1;
    }
};