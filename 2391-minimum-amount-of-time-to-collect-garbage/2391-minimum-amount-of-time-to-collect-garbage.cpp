class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans=0;
        int n=garbage.size();
        int m=travel.size();
        vector<int> prefix(m+1,0);
        for(int i=0;i<m;i++){
            prefix[i+1]=prefix[i]+travel[i];
        }
        
        vector<unordered_map<int,char>> present(n,unordered_map<int,char>());
        for(int i=0;i<n;i++){
            for(auto j:garbage[i]){
                present[i][j]++;
            }
        }
        
        for(auto type:{'G','P','M'}){
            int prevsum=0;
            for(int currsum=0;currsum<n;currsum++){
                if(present[currsum][type]>0){
                    ans+=present[currsum][type];
                    
                    if(currsum!=0){
                        ans+=prefix[currsum]-prefix[prevsum];
                        prevsum=currsum;
                    }
                }
            }
        }
        return ans;
        
    }
};