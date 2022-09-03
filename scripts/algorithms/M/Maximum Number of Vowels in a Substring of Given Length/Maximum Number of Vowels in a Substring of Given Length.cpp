// Runtime: 66 ms (Top 14.27%) | Memory: 9.8 MB (Top 99.25%)
class Solution {
public:
    bool checkVowel(char c){
        if(c == 'a' || c == 'e' || c =='i' || c == 'o' || c == 'u') return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int count = 0;
        int ans = 0;
        for(int i = 0; i < k; i++){
            if(checkVowel(s[i])) count++;
        }
        ans = count;
        int j = 0;
        for(int i = k; i<s.size(); i++){
            if(checkVowel(s[i])) count++;
            if(checkVowel(s[j])) count--;
            j++;
            ans = max(ans, count);
        }
        return ans;
    }
};