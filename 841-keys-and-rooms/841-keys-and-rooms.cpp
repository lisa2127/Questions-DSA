class Solution {
public:
    void dfs(int src,unordered_map<int,bool> &visited,vector<vector<int>>& rooms){
        visited[src]=true;
        for(int i=0;i<rooms[src].size();i++){
            if(!visited[rooms[src][i]]){
                dfs(rooms[src][i],visited,rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int,bool> visited;
        dfs(0,visited,rooms);
        for(int i=0;i<rooms.size();i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};