class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        queue<int> q;
        for(int i=1;i<10;i++){
            q.push(i);
        }
        for(int i=1;i<n;i++){
            int size=q.size();
            for(int i=0;i<size;i++){
                int temp=q.front();
                q.pop();
                int unit=temp%10;
                if(unit+k<10){
                    q.push((temp*10)+unit+k);
                }
                if(unit-k>=0 && k!=0){
                    q.push((temp*10)+unit-k);
                }
            
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};