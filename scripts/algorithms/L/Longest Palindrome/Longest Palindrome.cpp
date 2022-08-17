class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        int ans = 0;
        int odd = 0;
        for(auto i:mp){
            if(i.second % 2 == 1){
                odd = 1;
            }
            ans = ans + (i.second/2)*2;
        }
        return ans+odd;
    }
};
