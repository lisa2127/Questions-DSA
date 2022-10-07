class Solution {
public:
    bool found(vector<int> arr,int target){
        int s=0,e=arr.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]==target){
                return true;
            }
            else if(arr[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return false;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        set<int> s;
        /*set<int> s,p;
        for(int i=0;i<nums1.size();i++){
            s.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            if(s.find(nums2[i])!=s.end()){
                p.insert(nums2[i]);
            }
        }
        for(auto i:p){
            ans.push_back(i);
        }*/
        sort(nums1.begin(),nums1.end());
        for(int i=0;i<nums2.size();i++){
            if(found(nums1,nums2[i])){
                s.insert(nums2[i]);
            }
        }
        for(auto i: s){
            ans.push_back(i);
        }
        return ans;
    }
};