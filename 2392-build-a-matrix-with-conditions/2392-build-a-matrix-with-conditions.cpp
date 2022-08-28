class Solution {
public:
    
    vector<int> solve(int k,vector<vector<int>>& conditions){
        unordered_map<int,list<int>> adj;
        vector<int> indegree(k+1);
        for(int i=0;i<conditions.size();i++){
            int u=conditions[i][0];
            int v=conditions[i][1];
            
            adj[u].push_back(v);
        }
        for(int i=1;i<=k;i++){
            for(auto j:adj[i]){
                indegree[j]++;
            }
        }
        queue<int> q;
        for(int i=1;i<=k;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> order;
        int cnt=0;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            cnt++;
            order.push_back(temp);
            
            for(auto i:adj[temp]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        if(cnt==k){
            return order;
        }
        return {};
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<int> row=solve(k,rowConditions);
        vector<int> col=solve(k,colConditions);
        
        if(row.size()==0 || col.size()==0){
            return {};
        }
        
        vector<pair<int,int>> ind(k);
        for(int i=0;i<k;i++){
            ind[row[i]-1].first=i;
            ind[col[i]-1].second=i;
        }
        
        vector<vector<int>> ans(k,vector<int>(k,0));
        for(int i=0;i<k;i++){
            ans[ind[i].first][ind[i].second]=i+1;
        }
        
        return ans;
    }
};