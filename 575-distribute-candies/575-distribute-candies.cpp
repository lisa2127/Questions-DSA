class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        
        unordered_map<int,int> mp;
        for(int i=0;i<candyType.size();i++){
            mp[candyType[i]]++;
        }
        int candy=candyType.size()/2;
        if(mp.size()>=candy){
            return candy;
        }
        else{
            return mp.size();
        }
    }
};