class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int r=n;
        int c=n;
        vector<vector<int>> ans(n,vector<int>(n));
        int top=0,bottom=r-1,left=0,right=n-1;
        int direction=1;
        int x=0;
        while(top<=bottom && left<=right){
            vector<int> temp;
            if(direction==1){
                for(int i=left;i<=right;i++){
                    ans[top][i]=++x;
                }
                direction=2;
                top++;
            }
            else if(direction==2){
                for(int i=top;i<=bottom;i++){
                    ans[i][right]=++x;
                }
                direction=3;
                right--;
            }
            else if(direction==3){
                for(int i=right;i>=left;i--){
                    ans[bottom][i]=++x;
                }
                direction=4;
                bottom--;
            }
            else if(direction==4){
                for(int i=bottom;i>=top;i--){
                    ans[i][left]=++x;
                }
                direction=1;
                left++;
            }
        }
        return ans;
    }
};