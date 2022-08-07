class Solution {
public:
    int findNumbers(vector<int>& nums) {
        //Approach-1
        /*int cnt=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int n=nums[i];
            while(n>0){
                cnt++;
                n=n/10;
            }
            if(cnt%2==0){
                ans++;
            }
             cnt=0;
        }   
        return ans;*/
        //Approach-2
       /*int ans=0;
        for(int i=0;i<nums.size();i++){
            string s=to_string(nums[i]);
            if(s.length()%2==0){
                ans++;
            }
        }
        return ans;*/
        
        //Approach-3
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int l=log10(nums[i]);
            if((l+1)%2==0){
                ans++;
            }
        }
        return ans;
    }
};