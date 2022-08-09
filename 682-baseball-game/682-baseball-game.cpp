class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        for(int i=0;i<ops.size();i++){
            if(ops[i]=="+"){
                int val=s.top();
                s.pop();
                int sum=s.top()+val;
                s.push(val);
                s.push(sum);
            }
            else if(ops[i]=="C"){
                s.pop();
            }
            else if(ops[i]=="D"){
                int val =s.top();
                s.push(2*val);
            }
            else{
                
                s.push(stoi(ops[i]));
            }
        }
        int ans=0;
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
};