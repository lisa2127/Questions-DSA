class Solution {
public:
    bool solve(vector<int> row, int x){
        int s=0,e=row.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(row[mid]==x){
                return true;
            }
            else if(row[mid]>x){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            if(solve(matrix[i],target)){
                return true;
            }
        }
        return false;
    }
};