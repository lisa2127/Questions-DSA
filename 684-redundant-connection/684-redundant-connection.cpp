class Solution {
public:
    int find(int temp,vector<int> &parent){
        if(parent[temp]==temp){
            return temp;
        }
        return parent[temp]=find(parent[temp],parent);
    }
    bool unionBoth(int x,int y,vector<int> &parent,vector<int> &rank){
        int u=find(x,parent);
        int v=find(y,parent);
        if(u==v){
            return false;
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
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> ans;
        vector<int> parent(n);
        vector<int> rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto &e:edges){
            if(!unionBoth(e[0]-1,e[1]-1,parent,rank)){
                ans.push_back(e[0]);
                ans.push_back(e[1]);
            }
        }
        return ans;
    }
};