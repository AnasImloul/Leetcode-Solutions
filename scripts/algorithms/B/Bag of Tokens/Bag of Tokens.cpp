// Runtime: 15 ms (Top 23.40%) | Memory: 10.6 MB (Top 67.12%)
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int start=0,end=tokens.size()-1,score=0,ans=0;
        while(start<=end){
            if(power>=tokens[start]){
                ans=max(ans,++score);
                power-=tokens[start++];
            } else if(score>0){
                score--;
                power+=tokens[end--];
            } else {
                return 0;
            }
        }
        return ans;
    }
};