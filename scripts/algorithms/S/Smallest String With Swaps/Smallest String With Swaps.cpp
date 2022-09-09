// Runtime: 370 ms (Top 35.98%) | Memory: 87.5 MB (Top 5.47%)
class Solution {
public:

    vector<int> parent;

    int findParent(int n)
    {
        if(parent[n] == n) return n;
        return parent[n] = findParent(parent[n]);
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs)
    {
        map<int, set<int>> mp;
        parent.resize(s.size());
        string ans = s;

        for(int i=0; i<s.length(); i++) parent[i] = i;

        for(auto pair: pairs)
        {
            int p1 = findParent(pair[0]), p2 = findParent(pair[1]);
            if(p1 != p2) parent[p2] = p1;
        }

        for(auto pair: pairs)
        {
            int p = findParent(pair[0]);
            mp[p].insert(pair[0]);
            mp[p].insert(pair[1]);
        }

        for(auto it: mp)
        {
            vector<char> part;
            set<int> idx = it.second;

            for(auto index: idx) part.push_back(s[index]);

            sort(part.begin(), part.end());

            auto index = idx.begin();
            for(auto x: part) ans[*index] = x, ++index;
        }

        return ans;
    }
};