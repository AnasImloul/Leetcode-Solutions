class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int ans = 1;
        for(auto ch : s) {
            if(mp.find(ch) != mp.end()) {
                while(mp.find(ch) != mp.end()) mp.erase(mp.begin());
            }
            mp.insert({ch, 1});
            if(mp.size() > ans) ans = mp.size();
        }
        return ans;
    }
};
