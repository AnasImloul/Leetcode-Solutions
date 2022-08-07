class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        if(n == k) return n;
        if(n == 1) return 1;

        int res = 0;
        int maxCnt = 0;
        
        unordered_map<char,int> mp;
        
        for(int l = 0, r = 0; r < n; r++)
        {
            mp[s[r]]++;
            maxCnt = max(maxCnt,mp[s[r]]);
            while(r - l + 1 - maxCnt > k){
                mp[s[l]]--;
                l++;
            }
            res = max(r - l + 1, res);
        }
        return res;
    }
};
