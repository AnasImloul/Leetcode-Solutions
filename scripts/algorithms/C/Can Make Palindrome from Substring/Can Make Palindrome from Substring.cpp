// Runtime: 966 ms (Top 29.96%) | Memory: 142.8 MB (Top 55.90%)
class Solution {
public:
  vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
    vector<vector<int>>table(s.size(), vector<int>(26,0));
    vector<bool>ans;

    table[0][s[0]-'a']++;
    for(int i = 1; i != s.size(); i++){
      for(int j = 0; j != 26; j++) table[i][j] = table[i-1][j];
      table[i][s[i]-'a']++;
    }

    for(auto &q: queries){
      int odd = 2 + (q[2]<<1);
      for(int i = 0; i != 26; i++){
        int val = table[q[1]][i] - (q[0] ? table[q[0]-1][i] : 0);
        if( (val & 1) && --odd == 0){ans.push_back(false); goto mark;}
      }

      ans.push_back(true);
      mark:;
    }

    return ans;
  }
};