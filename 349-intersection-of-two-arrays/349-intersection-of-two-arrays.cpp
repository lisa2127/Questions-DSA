class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        
        set<int> s,p;
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
        }
        return ans;
    }
};