// Runtime: 6 ms (Top 83.33%) | Memory: 8.90 MB (Top 38.89%)

class Solution {
public:
    vector<int> movesToStamp(string S, string T) {
        if (S == T) return {0};
        int slen = S.size(), tlen = T.size() - slen + 1, i, j;
        vector<int> ans;
        bool tdiff = true, sdiff;
        while (tdiff)
            for (i = 0, tdiff = false; i < tlen; i++) {
                for (j = 0, sdiff = false; j < slen; j++)
                    if (T[i+j] == '*') continue;
                    else if (T[i+j] != S[j]) break;
                    else sdiff = true;
                if (j == slen && sdiff) {
                    for (j = i, tdiff = true; j < slen + i; j++)
                        T[j] = '*';
                    ans.push_back(i);
                }
            }
        for (i = 0; i < T.size(); i++) if (T[i] != '*') return {};
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
