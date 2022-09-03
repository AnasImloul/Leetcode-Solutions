// Runtime: 38 ms (Top 56.71%) | Memory: 11.1 MB (Top 20.60%)
class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u';
    }

    long long countVowels(string word) {
        long long count = 0;
        int len = word.size();

        for(int pos = 0; pos < len; pos++) {
            if(isVowel(word[pos])) {
                count += (long)(len - pos) * (long)(pos + 1);
            }
        }

        return count;
    }
};