class Solution {
public:
    bool possible(vector<vector<int>>& grid, int i, int j, int n, vector<vector<bool>>& visited){
        
        return (i>=0 and i<n and j>=0 and j<n and grid[i][j]==0 and !visited[i][j]);
        
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int cnt=0;
        int n=grid.size();
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        queue<pair<int,int>> q;
        if(grid[0][0]==0){
            q.push(make_pair(0,0));
            vis[0][0]=true;
        }
        while(!q.empty()){
            int size=q.size();
            cnt++;
            for(int index=0;index<size;index++){
                pair<int,int> temp=q.front();
                q.pop();
                int i=temp.first;
                int j=temp.second;
                if(i==n-1 && j==n-1){
                    return cnt;
                }
                for(int k=i-1;k<=i+1;k++){
                    for(int l=j-1;l<=j+1;l++){
                        if(possible(grid,k,l,n,vis)){
                            q.push({k,l});
                            vis[k][l]=true;
                        }
                    }
                }
            }
        }
        return -1;
        
    }
};
