class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> s;
        vector<int> ans(nums2.size(),-1);
        for(int i=nums2.size()-1;i>=0;i--){
            while(!s.empty()){
                if(s.top()<=nums2[i]){
                    s.pop();
                }
                else{
                    ans[i]=s.top();
                    break;
                }
            }
            s.push(nums2[i]);
        }
        unordered_map<int,int> mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]=ans[i];
        }
        vector<int> sol;
        for(int i=0;i<nums1.size();i++){
            sol.push_back(mp[nums1[i]]);
        }
        return sol;
    }
};