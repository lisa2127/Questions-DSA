class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int cnt=0;
        unordered_map<char,int> mp;
        for(int i=0;i<stones.size();i++){
            mp[stones[i]]++;
        }
        for(int i=0;i<jewels.size();i++){
            if(mp[jewels[i]]>0){
                cnt+=mp[jewels[i]];
            }
        }
        return cnt;
    }
};