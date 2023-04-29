class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> v, powers, ans;
        for(int i=0; i<31; i++) v.push_back(pow(2, i));
        
        for(int i=v.size()-1; i>=0; i--) {
            if(v[i] <= n) powers.push_back(v[i]), n -= v[i];
        }
        reverse(powers.begin(), powers.end());

        int mod = 1e9 + 7;
        for(auto q : queries) {
            long long p = 1;
            for(int k=q[0]; k<=q[1]; k++) {
                p *= powers[k];
                p %= mod;
            }
            ans.push_back(p);
        }
        return ans;
    }
};
