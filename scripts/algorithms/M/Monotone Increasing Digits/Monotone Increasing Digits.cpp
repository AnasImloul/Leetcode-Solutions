// Runtime: 0 ms (Top 100.00%) | Memory: 5.9 MB (Top 82.10%)
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
            if(n < 10) return n;

            string s = to_string(n);

            for(int i = s.size() - 2; i >= 0; i--) {
                   if(s[i] > s[i+1]) {
                       s[i]--;
                       for(int j = i + 1; j < s.size(); j++) s[j] = '9';
                   }
            }
        int ans = stoi(s);
        return ans;
    }
};