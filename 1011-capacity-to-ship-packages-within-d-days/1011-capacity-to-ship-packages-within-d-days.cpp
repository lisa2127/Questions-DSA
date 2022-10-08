class Solution {
public:
    bool isPossible(vector<int> arr,int days,int mid){
        int dayCount=1;
        int capacity=0;
        for(int i=0;i<arr.size();i++){
            if(capacity+arr[i]<=mid){
                capacity+=arr[i];
            }
            else{
                dayCount++;
                if(dayCount> days || arr[i]>mid){
                    return false;
                }
                capacity=arr[i];
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s=0;
        int ans=-1;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
        }
        int e=sum;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isPossible(weights,days,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};