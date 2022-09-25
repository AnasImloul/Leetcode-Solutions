// Runtime: 30 ms (Top 84.45%) | Memory: 11.9 MB (Top 20.06%)
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(helper(answerKey,k,'T'),helper(answerKey,k,'F'));
    }

    int helper(string answerKey, int k,char c){
        int start = 0;
        int end = 0;
        int count = 0;
        int ans = 0;
        while(end<answerKey.length()){
            if(answerKey[end]==c)count++;
            while(count>k){
                if(answerKey[start]==c)count--;
                start++;
            }
            ans = max(ans,end-start+1);
            end++;
        }
        return ans;
    }
};