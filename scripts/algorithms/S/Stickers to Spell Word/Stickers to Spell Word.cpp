// Runtime: 1038 ms (Top 25.00%) | Memory: 269.4 MB (Top 16.92%)
class Solution {
public:
    int dp[50][1<<15] ;
    int solve(int ind, int mask, vector<string>& stickers, string& target)
    {
        if (mask == 0)
            return 0 ;
        if (ind == stickers.size())
            return 1e8 ;
        if (dp[ind][mask] != -1)
            return dp[ind][mask] ;
        vector<int> mp(26, 0);
        bool flag = false ;
        int ans = 1e8 ;
        for(int i = 0; i < stickers[ind].size(); i++)
            mp[stickers[ind][i]-'a'] ++ ;
        for(int i= 0; i < target.size(); i++)
        {
            if (mp[target[i]-'a'] > 0 && (mask & (1<<i)))
            {
                flag = true ;
                break ;
            }
        }
        if (flag) // Check if we can use any of the characters in sticker[ind]
        {
            int tempMask = mask ;
            for(int i = 0; i < target.size(); i++)
            {
                if (mp[target[i]-'a'] > 0 && (tempMask & (1<<i)))
                {
                    tempMask = tempMask ^ (1<<i) ;
                    mp[target[i]-'a'] -- ;
                }
            }
            ans = min(ans, 1+solve(ind, tempMask, stickers, target)) ; // Take those characters, and make call on same index
        }
        ans = min(ans, solve(ind+1, mask, stickers, target)) ; // Skip sticker[ind] and proceed
        return dp[ind][mask] = ans;
    }

    int minStickers(vector<string>& stickers, string target) {
        int n = target.size();
        memset(dp, -1, sizeof(dp)) ;
        int ans = solve(0, (1<<n)-1, stickers, target) ;
        if (ans == 1e8)
            return -1 ;
        return ans ;
    }
};