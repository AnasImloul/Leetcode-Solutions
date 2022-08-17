class Solution {
public:
    
    #define lld long long int
    
    int mul(lld a, lld b){
        lld product = (a*b)%MOD;
        return product;
    }
    
    int add(lld a, lld b){
        lld addition = (a+b)%MOD;
        return addition;
    }
    
    const int MOD = 1e9+7;
    int binary_exponentiation(lld x, int p){
        long long res = 1;
        while(p){
            if(p&1) res = mul(res, x);
            x = mul(x, x);
            p/=2;
        }
        return res;
    }
    
    int goodSubsets(int pos, int mask, vector<int>& V, vector<vector<int>>& dp, vector<int>& cache){
        if(pos == V.size()) return (mask>0);
        
        if(dp[pos][mask] != -1) return dp[pos][mask]%MOD;
        
        if(V[pos]&mask) return dp[pos][mask] = goodSubsets(pos+1, mask, V, dp, cache) % MOD;
        return dp[pos][mask] = add(mul(cache[V[pos]],goodSubsets(pos+1, mask|V[pos], V, dp, cache)),goodSubsets(pos+1, mask, V, dp, cache));
    }
    
    int numberOfGoodSubsets(vector<int>& nums) {
        
        int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        
        vector<int> V;
        vector<int> cache(1025, 0);
        
        int ones = 0;
        
        for(auto x: nums){
            
            int num = 0, k=0;
            int flag = 1;
            
            for(auto j: primes){

                int cnt = 0;
                while(x%j == 0){
                    x/=j;
                    cnt++;
					if(cnt>1) break;
                }
                
                if(cnt > 1)
                { 
                    flag = 0;
                    break;
                }
                
                if(cnt == 1)
                    num = num | (1<<k);
                
                ++k;
            }
            
            if(flag == 0) continue;
            
            if(num == 0) { 
                ones++;
                continue;
            }
            
            cache[num]++;
            if(cache[num] > 1) continue;
            
            V.push_back(num);
        }
        
        vector<vector<int>> dp(V.size(), vector<int> (1024, -1));
        
        int ans = goodSubsets(0,0,V,dp,cache);
        ans = mul(binary_exponentiation(2, ones),ans);
        
        return ans;
    }
};
