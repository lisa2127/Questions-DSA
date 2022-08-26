class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        
        //gave TLE
        /*int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int cnt=0;
            for(int j=0;j<numsDivide.size();j++){
                if(numsDivide[j]%nums[i]!=0){
                    ans++;
                    break;
                }
                else{
                    cnt++;
                }
            }
            if(cnt==numsDivide.size()){
                cout<<cnt;
                break;
            }
        }
        if(ans==nums.size()){
            return -1;
        }
        return ans;*/
        int gcd=numsDivide[0];
        for(int i=1;i<numsDivide.size();i++){
             gcd = std::__gcd(gcd, numsDivide[i]);
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(gcd % nums[i]==0){
                return i;
            }
        }
        return -1;
    }
};