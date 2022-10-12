class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int cnt=0;
        vector<int> indegree(numCourses,0);
        vector<int> adj[numCourses];
        int m=prerequisites.size();
        for(int i=0;i<m;i++)
         {  adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            cnt++;
            for(auto i:adj[temp]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        if(cnt==numCourses){
            return true;
        }
        return false;
    }
};