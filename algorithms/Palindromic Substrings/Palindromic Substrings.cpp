class Solution {
public:
    int countSubstrings(string s) {
        int count = s.size();
        for(int i = 0; i < s.size(); i++) {
            int len1 = expand(s, i, i+1);
            int len2 = expand(s, i, i);
            
			// every palindrome found has len/2 total number of palindromes
            count += len1/2;
            count += len2/2;
        }
        return count;
    }
    
    int expand(string s, int i, int j) {
        while(i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;j++;
        }
        return j-i-1;
    }
};
