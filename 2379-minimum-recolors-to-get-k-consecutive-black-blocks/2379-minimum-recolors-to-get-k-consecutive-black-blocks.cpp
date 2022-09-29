class Solution {
public:
    int solve(string blocks,int index,int k){
       int ans=0,colour=0,count=0;
        for(int i=index;i<index+k;i++){
            if(blocks[i]=='W'){
                colour++;
            }
            if(blocks[i]=='B'){
                count++;
            }
            if(count+colour==k){
                ans=colour;
                break;
            }
        } 
        return ans;
    }
    int minimumRecolors(string blocks, int k) {
        int ans=INT_MAX;
        for(int i=0;i<=blocks.size()-k;i++){
            int temp=solve(blocks,i,k);
            ans=min(ans,temp);
        }
        return ans;
    }
};