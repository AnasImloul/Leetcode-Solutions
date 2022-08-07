    int characterReplacement(string s, int k) {
        int n = s.length();
        if(n == k) return n;
        if(n == 1) return 1;

        int res = 0;

        unordered_map<char, int> mp;
        using pair_type = decltype(mp)::value_type;
        auto it =[] (const pair_type& p1, const pair_type& p2) {return p1.second < p2.second;};
        
        for(int l = 0, r = 0; r < n; r++)
        {
            mp[s[r]]++;
            while(r - l + 1 - (max_element(mp.begin(), mp.end(), it)->second) > k){
                mp[s[l]]--;
                l++;
            }
            res = max(r - l + 1, res);
        }
        return res;
    }
};
