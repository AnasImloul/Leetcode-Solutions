class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int mp[26] = {0};
        for(auto &word: words){
            for(auto &c: word){
                mp[c - 'a']++;
            }
        }
        
        for(int i = 0;i<26;i++){
            if(mp[i] % words.size() != 0) return false;
        }
        return true;      
    }
};