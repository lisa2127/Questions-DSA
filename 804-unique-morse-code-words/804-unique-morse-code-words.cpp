class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
       vector<string> morse= {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> s;
        for(auto word:words){
            string code=" ";
            for(auto ch:word){
                code+=morse[ch-'a'];
            }
            s.insert(code);
        }
        return s.size();
    }
};