class Solution {
    
private:
    
    int MOD = 1e9 + 7;
    
public:
    
    int sumOfFlooredPairs(vector<int>& nums) {

        // first of all, we record the max value
        int max_n = INT_MIN;
        for(int n : nums) max_n = max(max_n, n);
        
        // then the occurences for each number in [0, max]
        vector<int> occs(max_n + 1, 0);
        for(int n : nums) occs[n]++;
        
        // prefix sum algorithm to accumulate the occurences
        vector<int> occs_acc(max_n + 1, 0);
        for(int i = 1; i < max_n + 1; ++i) {
            occs_acc[i] = occs[i] + occs_acc[i - 1]; 
        }
        
        // long long needed to prevent overflows
        long long ans = 0; 
        for(int i = 0; i < max_n + 1; ++i) {
            
            // just handle numbers that occur at least once
            if(occs[i] != 0) {
                                
                int k = 1;
                int k_next;
                
                // for each multiple of i
                do {
                    
                    k_next = k + 1;

                    // "right and left" multipliers in occs_acc 
                    int r = min(k_next * i - 1, max_n);
                    int l = k * i - 1;
                    
                    ans += ((long long) occs_acc[r] - (long long) occs_acc[l]) * (long long) occs[i] * k++;
                    
                    
                } while(k_next * i - 1 < max_n);
            }
        }
        
        return ans % MOD;
    }
};
