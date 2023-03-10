//easy to understand
class Solution {
public:
    bool allZeros(vector<int> &count) {
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) 
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        string s1 = p, s2 = s;
        int n = s1.length(); 
        int m = s2.length();
        if (n > m) 
            return {};

        vector<int> ans;
        vector<int> count(26, 0);

        for (int i = 0; i < n; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        //it will check for s1 = abcd, s2 = cdab
        if (allZeros(count)) {
            ans.push_back(0);
        }

        for (int i = n; i < m; i++) {
            count[s2[i] - 'a']--;
            count[s2[i - n] - 'a']++;
            if (allZeros(count)) 
                ans.push_back(i-n+1);
        }

        return ans;
    }
};