class Solution {
public:
    int solve(vector<int> arr,int x){
        int cnt=0;
        int s=0,e=arr.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]<x){
                cnt+=mid-s+1;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return cnt;
    }
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> copy,ans;
        copy=nums;
        sort(copy.begin(),copy.end());
        for(int i=0;i<nums.size();i++){
            int temp=solve(copy,nums[i]);
            ans.push_back(temp);
        }
        return ans;
    }
};