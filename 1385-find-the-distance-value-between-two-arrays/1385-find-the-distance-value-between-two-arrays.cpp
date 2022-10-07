class Solution {
public:
    bool solve(vector<int> arr,int x,int d){
        int s=0;
        int e=arr.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(abs(arr[mid]-x)<=d){
                return false;
            }
            else if(arr[mid]<x){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        } 
        return true;
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int ans=0;
        for(int i=0;i<arr1.size();i++){
            if(solve(arr2,arr1[i],d)){
                ans++;
            }
        }
        return ans;
    }
};