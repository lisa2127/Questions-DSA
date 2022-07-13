class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0){
            return 0;
        }
        int left=0;
        int right=height.size()-1;
        int leftmax=height[left];
        int rightmax=height[right];
        int ans=0;
        while(left<right){
            if(leftmax<rightmax){
                left++;
                leftmax=max(leftmax,height[left]);
                ans+=leftmax-height[left];
            }
            else{
                right--;
                rightmax=max(rightmax,height[right]);
                ans+=rightmax-height[right];
            }
        }
        return ans;
    }
};