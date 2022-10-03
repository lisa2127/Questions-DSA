class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
       int ans=INT_MIN;
       for(int i=0;i<grid.size()-2;i++){                        //row-wise traverse
           for(int j=0;j<grid[0].size()-2;j++){                 //column wise traverse
               int sum=grid[i][j]+grid[i][j+1]+grid[i][j+2]+grid[i+1][j+1]+
                   grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];
               ans=max(ans,sum);
           }
       }
        return ans;
    }
};