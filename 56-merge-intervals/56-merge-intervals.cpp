class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        vector<int> v=intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=v[1]){
                v[1]=max(v[1],intervals[i][1]);
            }
            else{
                ans.push_back(v);
                v=intervals[i];
            }
        }
        ans.push_back(v);
        return ans;
    }
};