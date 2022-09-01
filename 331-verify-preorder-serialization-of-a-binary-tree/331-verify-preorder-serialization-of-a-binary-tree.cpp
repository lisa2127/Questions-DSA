class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string temp;
        int cnt=1;
        while(getline(ss,temp,',')){
            cnt--;
            if(cnt<0){
                return false;
            }
            if(temp!="#"){
                cnt=cnt+2;
            }
        }
        return cnt==0;
    }
};