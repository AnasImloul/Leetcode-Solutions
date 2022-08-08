class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        
        int i, j, k, ans = 0, res, n = s.length();
        
        string temp;
        unordered_map<char, int> st;
        unordered_map<string, int> mp;
        
        i = 0, j = 0;
        while(i <= n - minSize && j < n)
        {
            temp += s[j];
            st[s[j]] += 1;;
            if(temp.length() == minSize)
            {
                if(st.size() <= maxLetters)
                    mp[temp] += 1;
                i += 1;
                st[temp[0]] -= 1;
                if(st[temp[0]] == 0)
                    st.erase(temp[0]);
                temp.erase(temp.begin());
            }
            j += 1;
        }
        for(auto el : mp)
            ans = max(ans, el.second);
        return ans;
    }
};
