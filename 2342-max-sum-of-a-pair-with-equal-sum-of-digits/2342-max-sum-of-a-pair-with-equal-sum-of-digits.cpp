class Solution {
public:
    int solve(int n){
        int sum=0;
        while(n>0){
            int r=n%10;
            sum+=r;
            n=n/10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
       
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int temp=solve(nums[i]);
            ans.push_back(temp);
        }
        vector<pair<int,int>> p;
        for(int i=0;i<nums.size();i++){
            p.push_back(make_pair(ans[i],nums[i]));
        }
        int msum=-1;
        sort(p.begin(),p.end());
        for(int i=1;i<nums.size();i++){
            if(p[i].first==p[i-1].first){
                msum=max(msum,p[i].second+p[i-1].second);
            }
            
        }
        return msum;
    }
};