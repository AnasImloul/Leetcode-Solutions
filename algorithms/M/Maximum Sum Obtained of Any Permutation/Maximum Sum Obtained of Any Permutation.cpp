class Solution {
public:
    int MOD = 1e9 + 7 ;
    vector<int> createPermutation(vector<int>&nums , vector<vector<int>> &requests){
        sort(begin(nums),end(nums)) ;
        
        vector<int>sweep(nums.size() + 1) ;
        for(auto &x : requests) ++sweep[x[0]] , --sweep[x[1] + 1] ;
        for(int i = 1 ; i < sweep.size() ; ++i ) sweep[i] += sweep[i-1] ;
        
        vector<int> aux(nums.size()) ;
        set<pair<int,int>> st ;
        for(int i = 0 ; i < nums.size() ; ++i ) st.insert({sweep[i],i}) ;
        
        int i = 0 ;
        while(st.size()){
            auto[freq,idx] = *begin(st) ;
            st.erase(begin(st)) ;
            aux[idx] = nums[i++] ;
        }
        return aux ;
    }
    
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        vector<int> aux = createPermutation(nums,requests);
        vector<int>pref ;
        for(auto &x : aux) pref.push_back(pref.empty() ? x : x + pref.back()) ;
        int ans = 0 ;
        for(auto &x : requests) ans = (ans + (pref[x[1]] - (x[0]-1 >= 0 ? pref[x[0] - 1] : 0) + MOD) % MOD) % MOD;
        return ans ;
    }
};
