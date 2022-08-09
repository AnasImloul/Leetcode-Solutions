class Solution {
public:
    #define MOD 1000000007
    #define ll long long
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        
        int n = packages.size();
        int m = boxes.size();
        sort(packages.begin(), packages.end());
        vector<ll> pack(n + 1);
        pack[0] = 0;
        for(int i = 0;i<n; i++){
            pack[i + 1] = packages[i];
            pack[i + 1] += pack[i];
        }
        ll ans = 1e18;
        bool mf = false;
        for(int i = 0; i<m; i++){
            vector<int> opt = boxes[i];
            sort(opt.begin(), opt.end());
            int back = 0;
            ll temp = 0;
            bool flag = false;
            ll bag ;
            for(int j = 0; j<(int)opt.size(); j++){
                
                bag = opt[j];
                auto it = upper_bound(packages.begin(), packages.end(), bag);
                auto it1 = it;
                int idx ;
                if(it != packages.begin()){
                    it--;
                    idx = it - packages.begin();
                    ll num_packs = idx + 1 - back;
                    
                    ll pack_sum = pack[idx + 1] - pack[back];
                    back = idx + 1;
                    temp += (num_packs*bag - pack_sum);
                }
                if(it1 == packages.end()){
                    flag = true;
                    break;
                }  
            }
            if(flag){
                ans = min(ans, temp);
                mf = true;
            }
                 
        }
        if(!mf) return -1;
        
        if(ans == 1e18) return -1;
        ans = ans % MOD;
        return ans;
    }
};
