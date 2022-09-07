// Runtime: 70 ms (Top 5.03%) | Memory: 29.5 MB (Top 5.12%)
class Solution {
public:
    bool checkValidString(string s) {
        unordered_map<int, unordered_map<int, bool>> m;
        return dfs(s, 0, 0, m);
    }

    // b: balanced number
    bool dfs (string s, int index, int b, unordered_map<int, unordered_map<int, bool>>& m) {
        if (index == s.length()) {
            if (b == 0 ) return true;
            else return false;
        }

        if (m.count(index) && m[index].count(b)) return m[index][b];

        if (s[index] == '(') {
            m[index][b] = dfs(s, index+1, b+1, m);
        } else if (s[index] == ')') {
            m[index][b] = (b!= 0 && dfs(s, index+1, b-1, m));
        }else {
            m[index][b] = dfs(s,index+1, b, m) || dfs(s, index+1, b+1, m) ||
                    (b != 0 && dfs(s, index+1, b-1, m));
        }

        return m[index][b];
    }
};