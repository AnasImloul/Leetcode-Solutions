class Solution {
public:
    bool isPalindrome(int x) {
        string rev= to_string(x);
        reverse(rev.begin(), rev.end());
        return to_string(x)== rev;
    }
};
