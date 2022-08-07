class Solution {
public:
    int n,m;
    vector<int> pos[26];
    int findRotateSteps(string ring, string key) {
        n = ring.size(), m = key.size();
        for(int i = 0; i < n; i++)
            pos[ring[i] - 'a'].push_back(i);
        vector<vector<int>> memo(n, vector<int>(m, INT_MAX));
        return helper(0, 0, memo, ring, key);
    }
    int helper(int i, int j, vector<vector<int>>& memo, string &ring, string &key){
        if(j == m) return 0;
        if(memo[i][j] != INT_MAX) return memo[i][j];
        int best = INT_MAX;
        for(int &next: pos[key[j] - 'a']){
            int diff = abs(i - next);
            best = min(best, min(diff, n - diff) + helper(next, j + 1, memo, ring, key));
        }
        return memo[i][j] = best + 1;
    }
};
