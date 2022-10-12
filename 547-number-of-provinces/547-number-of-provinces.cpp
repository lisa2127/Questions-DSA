class Solution {
public:
    int find(int x,vector<int> &parent){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x],parent);
    }
    void unionBoth(int a,int b,vector<int> &parent,vector<int> &rank){
        int u=find(a,parent);
        int v=find(b,parent);
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> parent(n);
        vector<int> rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isConnected[i][j]){
                    unionBoth(i,j,parent,rank);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                cnt++;
            }
        }
        return cnt;
    }
};