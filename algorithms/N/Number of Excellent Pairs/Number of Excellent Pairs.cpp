class Solution {
public:
    typedef long long ll;
    int setbits(int n){
        int cnt = 0;
        while(n){
            cnt += (n%2);
            n /= 2;
        }
        return cnt;
    }
    
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(),nums.end());
        vector<int> v;
        for(auto& i: s){
            int x = setbits(i);
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        
        ll ans = 0;
        for(int i=0;i<v.size();i++){
            auto it = lower_bound(v.begin(),v.end(),k-v[i]);
            ans += (v.end()-it);
        }
        return ans;
        
    }
};
