class Solution {
public:
    int find(int a,vector<int> &parent){
        if(parent[a]==a){
            return a;
        }
        return parent[a]=find(parent[a],parent);
    }
    void unionBoth(int x,int y,vector<int> &parent,vector<int> &rank){
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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int> parent(n);
        vector<int> rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
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
        return n-cnt;
    }
};