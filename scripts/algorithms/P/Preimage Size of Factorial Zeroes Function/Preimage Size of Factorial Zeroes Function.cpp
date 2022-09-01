// Runtime: 5 ms (Top 11.74%) | Memory: 5.9 MB (Top 34.16%)
#define ll long long
class Solution {
public:
    bool check(ll num, int k){
        ll start = 5;
        ll ans = 0;
        while(start <= num){
            ans += (num/start);
            start *= 5;
        }
        return ans <= k;
    }
    ll get(int k){
        ll lo = 1;ll hi = 1e18;
        ll mid, res(1e18);
        while(lo <= hi){
            mid = (lo+hi)/2;
            if(check(mid, k)){
                lo = mid+1;
                res = mid;
            }
            else
                hi = mid-1;
        }
        return res;
    }
    int preimageSizeFZF(int k) {
        if(k == 0)
            return 5;
        return (get(k) - get(k-1));
    }
};