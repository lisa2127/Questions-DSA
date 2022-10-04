class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<int> rowm(m,1);
        vector<int> colm(n,1);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    rowm[i]=0;
                    colm[j]=0;
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(rowm[i]==0 || colm[j]==0)
                    matrix[i][j]=0;
            }
        }
    }
};