class Solution {
public:
    bool isPossible(vector<int> arr,int ops,int mid){
        int requiredOps=0;
        for(int i=0;i<arr.size();i++){
            int x=arr[i]/mid;
            if(arr[i]%mid==0){
                x--;
            }
            requiredOps+=x;
        }
        return requiredOps<=ops;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int s=1;
        int ans=-1;
        int e= *max_element(nums.begin(),nums.end());
        int penalty=e;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isPossible(nums,maxOperations,mid)){
                penalty=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return penalty;
    }
};