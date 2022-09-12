class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        sort(tokens.begin(),tokens.end());
        int score=0;
        int i=0;
        int j=n-1;
        while(i<j){
            if(tokens[i]<=power){
                score++;
                power-=tokens[i++];
            }
            else if(score>=1 && power+tokens[j]>=tokens[i]){
                score--;
                power+=tokens[j--];
            }
            else{
                break;
            }
        }
        while(i<j+1 && power>=tokens[i]){
            power-=tokens[i++];
            score++;
        }
        return score;
    }
};