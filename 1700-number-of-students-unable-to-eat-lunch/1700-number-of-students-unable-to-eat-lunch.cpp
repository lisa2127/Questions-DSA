class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        queue<int> q;
        for(int i=0;i<students.size();i++){
            q.push(students[i]);
        }
        int rotations=0;
        int i=0;
        while(!q.empty() && rotations<q.size()){
            if(q.front()==sandwiches[i]){
                q.pop();
                i++;
                rotations=0;
            }
            else{
                int x=q.front();
                q.pop();
                q.push(x);
                rotations++;
            }
        }
        return q.size();
    }
};