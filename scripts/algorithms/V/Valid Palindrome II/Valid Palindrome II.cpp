class Solution {
  int first_diff(string s) {
    for (int i = 0; i < (s.size() + 1) / 2; ++i) {
      if (s[i] != s[s.size() - 1 - i]) {
        return i;
      }
    }
    return -1;
  }
public:
    bool validPalindrome(string s) {
      int diff = first_diff(s);
      if (diff == -1 || (s.size() % 2 == 0 && diff + 1 == s.size() / 2)) {
        // abca. If we have pattern like this than we can delete one of the symbols
        return true;
      }
      
      bool first_valid = true;
      for (int i = diff; i < (s.size() + 1) / 2; ++i) {
        if (s[i] != s[s.size() - 2 - i]) {
          first_valid = false;
          break;
        }
      }
      
      bool second_valid = true;
      for (int i = diff; i < (s.size() + 1) / 2; ++i) {
        if (s[i + 1] != s[s.size() - 1 - i]) {
          second_valid = false;
          break;
        }
      }
      return first_valid || second_valid;
    }
};
