class Solution {
public:
    int find(int a,vector<int> &parent){
        if(parent[a]==a){
            return a;
        }
        return parent[a]=find(parent[a],parent);
    }
    void Union(int x,int y,vector<int> &parent,vector<int> &rank){
        int u=find(x,parent);
        int v=find(y,parent);
        if(u==v){
            return;
        }
        if(rank[u]<rank[v]){
            parent[u]=v;
        }
        else if(rank[v]<rank[u]){
            parent[v]=u;
        }
        else{
            parent[u]=v;
            rank[v]++;
        }
        
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        if(n-1>m){
            return -1;
        }
        vector<int> parent(n);
        vector<int> rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int extra=0;
        for(int i=0;i<m;i++){
            Union(connections[i][0],connections[i][1],parent,rank);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                ans++;
            }
        }
        return ans-1;
    }
};