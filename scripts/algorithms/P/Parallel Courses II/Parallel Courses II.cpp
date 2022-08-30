// Runtime: 699 ms (Top 31.21%) | Memory: 9.5 MB (Top 92.20%)
class Solution {
    int dp[1<<16];
    int dfs(unordered_map<int, int>& c, int mask, int& k, int &n) {
        if(dp[mask] != -1) return dp[mask];
        int canJoin = 0, canNotJoin = 0;
        vector<int> canJoinVec;
        for(auto [key, value]: c) {
            if(((value & mask) == value) and !(mask & (1<<key))) {
                //get course we can listen
                canJoin |= 1<<key;
                canJoinVec.push_back(key);
            } else if(!(mask & (1<<key))) {
                   //get courses we can not listen yet
                canNotJoin |= 1<<key;
            }
        }
        //if there is no course we can not listen calculate immediatly
        if(!canNotJoin) {
            int left = n - bitset<16>(mask).count();
            return dp[mask] = left / k + (left % k ? 1 : 0);
        }
        //if there is some courses we can listen now (less then k) and can not listen
        //select the courses we can listen now first
        if(bitset<16>(canJoin).count() <= k) {
            int nMask = mask | canJoin;
            int left = k - bitset<16>(canJoin).count();
            //if there is some extra slots we can listen in this semester
            //pick any thing
            for(int i = 0; i < n and left; i++) {
                if(!(canNotJoin & (1<<i)) and !(nMask & (1<<i))) {
                    nMask |= 1<<i; left--;
                }
            }
            return dp[mask] = 1 + dfs(c, nMask, k, n);
        }
        //if we can listen more then k courses now, pick K courses from list (check every combinations)
        //any idea for pick m element from n array?
        sort(canJoinVec.begin(), canJoinVec.end());
        int mi = INT_MAX;
        do {
            int nMask = mask;
            for(int i = 0; i < k; i++) nMask |= 1<<canJoinVec[i];
            mi = min(mi, dfs(c, nMask, k, n));
        }while(next_permutation(canJoinVec.begin(), canJoinVec.end()));
        return dp[mask] = 1 + mi;
    }
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        unordered_map<int, int> course;
        memset(dp, -1, sizeof(dp));
        //initialize courses relational graph
        for(auto& r : relations) course[r[1]-1] |= 1<<(r[0]-1), course[r[0]-1] += 0;
        dp[(1<<n) - 1] = 0;

        return dfs(course, 0, k, n);
    }
};