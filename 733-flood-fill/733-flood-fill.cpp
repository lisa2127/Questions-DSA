class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int row,int col,int color,int source){
        if(sc<0 || sr<0 || sr>=row || sc>=col){
            return;
        }
        else if(image[sr][sc]!=source){
            return;
        }
        image[sr][sc]=color;
        dfs(image,sr-1,sc,row,col,color,source);
        dfs(image,sr+1,sc,row,col,color,source);
        dfs(image,sr,sc-1,row,col,color,source);
        dfs(image,sr,sc+1,row,col,color,source);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color==image[sr][sc]){
            return image;
        }
        int m=image.size();
        int n=image[0].size();
        int start=image[sr][sc];
        dfs(image,sr,sc,m,n,color,start);
        return image;
    }
};