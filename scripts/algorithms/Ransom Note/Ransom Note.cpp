class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[26] = {0};
        for(char x: magazine)
            cnt[x-'a']++;
        
        for(char x: ransomNote) {
            if(cnt[x-'a'] == 0)
                return false;
            cnt[x-'a']--;
        }
        
        return true;
    }
};
