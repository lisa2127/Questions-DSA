class Solution {
public:
    static int cmp(pair<int,int> a,pair<int,int> b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first<b.first;
    }
    int solve(vector<int> row){
        int res=0;
        int s=0,e=row.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(row[mid]==0){
                e=mid-1;
            }
            else if(row[mid]==1){
                res+=mid-s+1;
                s=mid+1;
            }
        }
        return res;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        vector<pair<int,int>> ans;
        for(int i=0;i<m;i++){
            int cnt=solve(mat[i]);
            ans.push_back({cnt,i});
        }
        vector<int> sol;
       
        sort(ans.begin(),ans.end(),cmp);      
        for(int i=0;i<k;i++){
            sol.push_back(ans[i].second);
            //cout<<ans[i]<<" ";
        }
        return sol;
    }
};