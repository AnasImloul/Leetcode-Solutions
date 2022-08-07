class Solution {
public:

    int findSubstringInWraproundString(string p) {
        unordered_map<char, int> mp;

        // if the characters are not contiguous and also check whether after 'z' I am getting 'a'. If so, reset the streak to 1
        // else streak++

        int streak = 0;

        for (int i = 0; i < p.size(); i++) {

            // contiguous
            if (i and (p[i] - p[i - 1] == 1)) streak++;

            // z...a case
            else if (i and (p[i] == 'a' and p[i - 1] == 'z')) streak++;

            else streak = 1;

            mp[p[i]] = max(mp[p[i]], streak);
        }

        // why sum? cuz there might be multiple substrings when the streak's broken for one

        int ans = 0;
        for (auto x : mp) {
            ans += x.second;
        }

        return ans;
    }
};

