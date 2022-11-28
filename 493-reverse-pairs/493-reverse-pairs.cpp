class Solution {
public:
    int count;
    void checkcount(vector<int> &nums,int start,int mid,int end){
        int l=start;
        int r=mid+1;
        while(l<=mid && r<=end){
            if((long)nums[l]>(long)2*nums[r]){
                count+=(mid-l+1);
                r++;
            }
            else{
                l++;
            }
        }
        sort(nums.begin()+start,nums.begin()+end+1);
        return;
    }
    void merge(vector<int> &nums,int start,int end){
        if(start==end){
            return;
        }
        int mid=(start+end)/2;
        merge(nums,start,mid);
        merge(nums,mid+1,end);
        checkcount(nums,start,mid,end);
        return;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        count=0;
        merge(nums,0,n-1);
        return count;
    }
};
