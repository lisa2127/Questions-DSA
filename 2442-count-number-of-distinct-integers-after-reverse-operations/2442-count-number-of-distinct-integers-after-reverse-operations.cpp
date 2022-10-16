class Solution {
public:
    int reverse(int n){
        int ans=0;
        while(n>0){
            int r=n%10;
            ans=ans*10+r;
            n=n/10;
        }
        return ans;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
            int temp=reverse(nums[i]);
            if(s.find(temp)==s.end()){
                s.insert(temp);
            }
        }
        return s.size();
    }
};