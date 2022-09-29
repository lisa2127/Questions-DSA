class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(abs(nums[i])<abs(pq.top())){
                pq.pop();
                pq.push(nums[i]);
            }
            else if(abs(nums[i])==abs(pq.top())){
                if(pq.top()<nums[i]){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
        return pq.top();
    }
};