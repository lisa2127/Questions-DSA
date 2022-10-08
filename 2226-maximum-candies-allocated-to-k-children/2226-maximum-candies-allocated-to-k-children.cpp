class Solution {
public:
    bool isPossible(vector<int> arr,long long k,int mid){
        for(auto i:arr){
            k-=i/mid;
        }
        return k<=0;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int s=1;
        int e=*max_element(candies.begin(),candies.end());
        int ans=0;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isPossible(candies,k,mid)){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
};