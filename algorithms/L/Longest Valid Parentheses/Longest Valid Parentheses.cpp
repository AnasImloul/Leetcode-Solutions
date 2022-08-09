class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), i = 0, ans = 0, k = 0;
        for(int j = 0; j < n; j++) {
            if(s[j] == '(')  k++;
            else if(s[j] == ')') {
                k--;
                if(k == 0)
                    ans = max(ans, j - i + 1);
            }
            if(k < 0) {
                k = 0;
                i = j + 1;
            }
        }
        k = 0, i = n - 1;
        for(int j = n - 1; j >= 0; j--) {
            if(s[j] == ')') {
                k++;
            }
            else if(s[j] == '(') {
                k--;
                if(k == 0)
                    ans = max(ans, i - j + 1);
            }
            if(k < 0) {
                k = 0;
                i = j - 1;
            }
        }
        return ans;
    }
};
