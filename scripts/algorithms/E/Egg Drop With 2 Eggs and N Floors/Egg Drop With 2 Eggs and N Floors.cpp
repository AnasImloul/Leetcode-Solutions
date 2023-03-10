int dp[1001][1001];
class Solution {
public:
    int solve(int e, int f){
        if(f == 0 || f == 1){
            return f;
        }
        if(e == 1){
            return f;
        }
        if(dp[e][f] != -1) return dp[e][f];
        int mn = INT_MAX;
        int left = 1, right = f;
        while(left <= right){
            int mid = left + (right-left)/2;
            int left_result = solve(e-1,mid-1);
            int right_result = solve(e,f-mid);
            mn = min(mn,1+max(left_result, right_result));
            if(left_result<right_result)
                left = mid+1;
            else
                right = mid-1;
        }
        return dp[e][f] = mn;
    }
    int twoEggDrop(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(2,n);
    }
};