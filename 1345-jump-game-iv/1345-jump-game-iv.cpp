class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
       
        int step=0;
        vector<bool> visited(n);
        visited[0]=true;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            for(int size=q.size();size>0;--size){
                int i=q.front();
                q.pop();
                if(i==n-1){
                    return step;
                }
                vector<int> &next=mp[arr[i]];
                next.push_back(i-1);
                next.push_back(i+1);
                for(auto j:next){
                    if(j>=0 && j<n && !visited[j]){
                        visited[j]=true;
                        q.push(j);
                    }
                }
                next.clear();
            }
            step++;
        }
        return 0;
    }
};
        