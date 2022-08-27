// Runtime: 7 ms (Top 59.27%) | Memory: 8.3 MB (Top 95.54%)
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        sort(answers.begin(),answers.end());
        int ans = 0;
        for(int i=0;i<answers.size();i++){
            ans += answers[i]+1;
            int num = answers[i];
            while(answers[i]==answers[i+1] && num>0 && i+1<answers.size()){
                num--;
                i++;
            }

        }
        return ans;
    }
};