// Runtime: 52 ms (Top 67.07%) | Memory: 22.8 MB (Top 17.97%)
class Solution {
public:
    string pushDominoes(string dominoes) {
        #define SET(ch, arr) \
                    if (dominoes[i] == ch) { count = 1; prev = ch; } \
                    else if (dominoes[i] != '.') prev = dominoes[i]; \
                    if (prev == ch && dominoes[i] == '.') arr[i] = count++;

        string res = "";
        char prev;
        int n = dominoes.size(), count = 1;

        vector<int> left(n, 0), right(n, 0);
        for (int i = 0; i < n; i++) {
            SET('R', right);
        }

        prev = '.';
        for (int i = n-1; i >= 0; i--) {
            SET('L', left);
        }

        for (int i = 0; i < n; i++) {
            if (!left[i] && !right[i]) res += dominoes[i];
            else if (!left[i]) res += 'R';
            else if (!right[i]) res += 'L';
            else if (left[i] == right[i]) res += '.';
            else if (left[i] < right[i]) res += 'L';
            else res += 'R';
        }

        return res;
    }
};