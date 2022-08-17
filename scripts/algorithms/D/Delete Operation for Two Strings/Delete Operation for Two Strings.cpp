class Solution {
public:
    int tabulation(string s1, string s2){
        vector<vector<int>> table(s1.length() + 1, vector<int>(s2.length() + 1));
        for(int i=1; i<s1.length()+1; i++){
            for(int j=1; j<s2.length()+1; j++){
                if(s1[i-1] == s2[j-1]){
                    table[i][j] = 1 + table[i-1][j-1];
                }
                else{
                    table[i][j] = max(table[i-1][j], table[i][j-1]);
                }
            }
        }
        return table[s1.length()][s2.length()];
    }
    
    int minDistance(string word1, string word2) {
        int lcs = tabulation(word1, word2);
        return (word1.length() - lcs) + (word2.length() - lcs);
    }
};
