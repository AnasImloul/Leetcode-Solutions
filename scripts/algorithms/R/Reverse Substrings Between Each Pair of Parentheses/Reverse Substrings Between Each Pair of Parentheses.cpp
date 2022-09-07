// Runtime: 0 ms (Top 100.00%) | Memory: 6.2 MB (Top 81.63%)
class Solution {
private:
    void revString(string& s, int start, int end) {
        while(start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
public:
    string reverseParentheses(string s) {
        stack<int> startIdx;
        string ans = "";
        int n = s.length();

        for (int i = 0; i < n; i++) {

            if (s[i] == '(') {
                startIdx.push(i);
            }

            if (s[i] == ')') {
                revString(s, startIdx.top(), i);
                startIdx.pop();
            }
        }

        for (auto ch : s) {
            if (ch != '(' && ch != ')') {
                ans += ch;
            }
        }

        return ans;
    }
};