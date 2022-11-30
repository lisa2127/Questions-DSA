class Solution {
public:
    bool isPossible(vector<int> piles,int limit,int h){
        int count=0;
        for(auto p:piles){
            count+=p/limit;
            if(p%limit){
                count++;
            }
        }
        return count>h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        if(piles.size()==h){
            return r;
        }
        while(l<r){
            int mid=l+(r-l)/2;
            if(isPossible(piles,mid,h)){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return l;   
    }
};