// Runtime: 0 ms (Top 100.00%) | Memory: 6 MB (Top 96.62%)
class Solution {
    int MOD=1e9+7;
public:
    int knightDialer(int n) {
        if(n==1) return 10;
        int a=2, b=2, c=3, d=2; //a{2,8} b{1,3,7,9} c{4,6} d{0}
        for(int i=3; i<=n; i++){
            int w, x, y, z;
            w = 2ll*b%MOD;
            x = (1ll*a + 1ll*c)%MOD;
            y = (2ll*b + 1ll*d)%MOD;
            z = 2ll*c%MOD;
            a = w; b = x; c = y; d = z;
        }
        int ans = (2ll*a + 4ll*b + 2ll*c + d)%MOD;
        return ans;
    }
};