class Solution {
public:
    int maxScore(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> dp( 1 << n ,  0); // dp contains score of masks - by default, scores are 0
        
        for(int i = 0 ; i < n ; i++) {//we have precomputed score for mask with only 2 set bits
            for(int j = 0 ; j < i ; j++){
                int mask = (1 << i) + (1 << j);
                dp[mask] = __gcd(nums[i] , nums[j]);// score after selecting only 2 nums is just their gcd
            }
        }
        
        dp[0] = 0; // score after selecting 0 nums is 0 by default
        
        for(int mask = 2 ; mask < (1 << n) ; mask ++ ){
    
            vector<int> nz;//here we would count and store non-zero bit positions of the mask in vector nz
            for(int i = 0 ; i < n ; i++)
                if(mask & (1 << i))
                    nz.push_back(i);
            
            if(nz.size() % 2) // if set bits is odd, we cannot compute as we need pairs for gcd
                continue;
            
            if(nz.size() == 2)//since we have precomputed dp for mask with only 2 set bits above
                continue;
            
            int op = nz.size() / 2; // we are performing opth operation now
            
            for(int i = 0 ; i < nz.size() ; i++) // nz[i]th bit not in submask
            {
                for(int j = 0 ; j < i ; j++){ // nz[j]th bit not in submask
                    
                    int pos1 = nz[i];
                    int pos2 = nz[j];
                    int submask = (mask ^ (1 << pos1)) ^ (1 << pos2);
                    
                    int g = dp[(1 << pos1) + (1 << pos2)] ;// to be added to get dp[mask] from dp[submask]
                    
                    dp[mask] = max(dp[mask] , op * g + dp[submask]);  
					//maximizing dp[mask] using the recursive equation explained above
                }
            }
                
        }
        
        return dp.back();
        
    }
};
