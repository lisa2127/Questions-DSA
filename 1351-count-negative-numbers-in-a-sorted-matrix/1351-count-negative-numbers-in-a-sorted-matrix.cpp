class Solution {
public:
    int solve(vector<int> arr){
        int res=0;
        int s=0,e=arr.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]>=0){
                s=mid+1;
            }
            else if(arr[mid]<0){
                res+=e-mid+1;
                e=mid-1;
            }
        }
        return res;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        /*for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]<0){
                    count++;
                }
            }
        }*/
        for(int i=m-1;i>=0;i--){
            int neg=solve(grid[i]);
            if(neg==0){
                 break;
            }
             count+=neg;
        }
        return count;
    }
};