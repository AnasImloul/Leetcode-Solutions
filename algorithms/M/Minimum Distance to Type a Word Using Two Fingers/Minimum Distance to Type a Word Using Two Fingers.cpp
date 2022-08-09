class Solution {
public:
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_map<char, pair<int, int>> m;
    int distCalc(char a, char b) {
        pair<int, int> p_a = m[a];
        pair<int, int> p_b = m[b];
        
        int x_diff = abs(p_a.first - p_b.first);
        int y_diff = abs(p_a.second - p_b.second);
        
        return x_diff + y_diff;
    }
    int dp[301][27][27];
    int minDist(string word, int i, char finger1_char, char finger2_char) {
        if(i == word.size()) return 0;
       
        if(dp[i][finger1_char - 'A'][finger2_char - 'A'] != -1) return dp[i][finger1_char - 'A'][finger2_char - 'A'];
        
        //finger1
        int op1 =  (finger1_char == '[' ? 0 : distCalc(finger1_char, word[i])) + minDist(word, i + 1, word[i], finger2_char);
        
        //finger2
        int op2 =  (finger2_char == '[' ? 0 : distCalc(finger2_char, word[i])) + minDist(word, i + 1, finger1_char, word[i]);
        
        return dp[i][finger1_char - 'A'][finger2_char - 'A'] = min(op1, op2);
    }
    int minimumDistance(string word) {
        //each letter has choice to be clicked by finger 1 or 2
        
        int row = -1;
        for(int i = 0; i < alpha.length(); i++) {
            int col = i % 6;
            if(col == 0) row++;
            m[alpha[i]] = {row, col};
        }
         memset(dp, -1, sizeof(dp));
         return minDist(word, 0, '[', '[');
    }
};
