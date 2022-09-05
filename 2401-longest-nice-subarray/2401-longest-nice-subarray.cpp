class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans=0;
        int start=0;
        int bitsUnion=0;
        for(int i=0;i<nums.size();i++){
            int ele=nums[i];
            while((bitsUnion & ele)!=0){
                int startelement=nums[start];
                bitsUnion ^=startelement;
                start++;
            }
            bitsUnion=bitsUnion | ele;
            ans=max(ans,i-start+1);
        }
        return ans;
    }
};