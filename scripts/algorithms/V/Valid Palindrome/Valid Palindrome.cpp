// Runtime: 8 ms (Top 58.78%) | Memory: 7.4 MB (Top 54.16%)
class Solution {
public:
    bool isPalindrome(string s) {
        auto it = remove_if(s.begin(), s.end(), [](char const &c) {
            return !isalnum(c);
        });

        s.erase(it, s.end());
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        int i = 0;
        int j = s.size()-1;

        while(i <= j) {
            if(s[i] != s[j]) return false;
            i++; j--;
        }

        return true;
    }
};