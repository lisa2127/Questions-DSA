class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> copy=matrix;
        int n=matrix.size();
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                matrix[j][n-i-1]=copy[i][j];
            }
        }
    }
};