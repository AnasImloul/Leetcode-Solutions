class Solution {
public:
    void dfs(string &s, string &small, int a, int b, unordered_map<string, string> &memo) {
        if (memo.count(s)) return;
        string res = s, str = res;
        memo[s] = res;
        rotate(str.begin(), str.begin() + b, str.end()); // rotate current string
        dfs(str, small, a, b, memo);
        if (memo[str] < res) res = memo[str];
        
        for (int i = 0; i < 9; i++) { // or add it
            for (int j = 1; j < s.length(); j+=2)
                s[j] = '0' + ((s[j] - '0') + a) % 10;
            if (s < res) res = s;
            dfs(s, small, a, b, memo);
        }
        if (small > res) small = res;
        memo[s] = res;
    }
    string findLexSmallestString(string s, int a, int b) {
        unordered_map<string, string> memo;
        string res = s;
        dfs(s, res, a, b, memo);
        return  res;
    }
};
