class Solution {
public:
    long long dis(int x1, int y1, int x2, int y2)
{
    return pow(x2-x1,2) + pow(y2-y1,2);
}
void dfs(int node, vector<vector<int>> &adj, vector<bool>& visited , int &count)
{
    if(visited[node]) return;
    
    visited[node]=true;
    count++;
    
    for(auto i: adj[node])
        if(!visited[i])
            dfs(i,adj,visited,count);
}
    int maximumDetonation(vector<vector<int>>& bombs) {
        //preparing adjacency list
        int n=bombs.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long int r=dis(bombs[i][0],bombs[i][1],bombs[j][0],bombs[j][1]);
                if(r<=pow(bombs[i][2],2)){
                    adj[i].push_back(j);
                }
                if(r<=pow(bombs[j][2],2)){
                    adj[j].push_back(i);
                }
            }
        }
        int ans=INT_MIN;
        vector<bool> vis;
        
        for(int i=0;i<n;i++){
            vis=vector(n,false);
                int cnt=0;
                dfs(i,adj,vis,cnt);
                ans=max(ans,cnt);
            
        }
        return ans;
    }
};