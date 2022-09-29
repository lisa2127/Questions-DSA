class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
       priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<arr.size();i++){
            if(pq.size()!=k){
                pq.push(arr[i]);
            }
            else{
                if(abs(arr[i]-x)<abs(pq.top()-x)){
                    pq.pop();
                    pq.push(arr[i]);
                }
            }
        }
        while(pq.size()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};