class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n=points.size();
        int left=0;
        int right=1;
        int count=0;
        while(right<n){
            if(points[left][1]<points[right][0]){
                left=right;
                right+=1;
            }
            else if(points[left][1]<=points[right][1]){
                count++;
                right+=1;
            }
            else if(points[left][1]>points[right][1]){
                count++;
                left=right;
                right+=1;
            }
        }
        return n-count;
    }
};