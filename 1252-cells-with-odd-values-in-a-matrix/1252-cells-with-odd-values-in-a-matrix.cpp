class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        
        vector<vector<int>> mat(m,vector<int>(n,0));
        int cnt=0;
        for(int i=0;i<indices.size();i++){
            int row=indices[i][0];
            int col=indices[i][1];
            for(int j=0;j<n;j++){
                mat[row][j]++;
                if(mat[row][j]%2!=0){
                    cnt++;
                }
                else{
                    cnt--;
                }
            }
            for(int k=0;k<m;k++){
                mat[k][col]++;
                if(mat[k][col]%2!=0){
                    cnt++;
                }
                else{
                    cnt--;
                }
            }
        
        }
        return cnt;
        
    }
};