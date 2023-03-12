class Solution{
typedef long long ll;
#define vi(x) vector<x>
public:
    unordered_map<string, ll>dp;
    string s;
    ll func(ll rem){
        if(dp.find(s)==dp.end()){
            dp[s]=-1;
        }
        ll&ans=dp[s];
        if(ans==-1){
            ans=0;
            ll bs=s.size();
            for(ll i=1;i<bs;++i){
                if(s[i]>'0'){
                    --s[i];
                    ans=max(ans, func((bs+rem-i)%bs)+!rem);
                    ++s[i];
                }
            }
        }
        return ans;
    }
    int maxHappyGroups(int bs, vector<int>&v) {
        s.assign(bs, '0');
        ll ans=0;
        for(ll it:v){
            if(it%bs==0){
                ++ans;
            }
            else if(s[bs-it%bs]>'0'){
                ++ans;
                --s[bs-it%bs];
            }
            else{
                ++s[it%bs];
            }
        }
        return ans+func(0);
    }
};