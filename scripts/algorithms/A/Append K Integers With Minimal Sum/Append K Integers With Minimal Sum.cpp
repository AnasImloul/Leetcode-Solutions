// Runtime: 116 ms (Top 82.06%) | Memory: 66.60 MB (Top 59.64%)

class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Sort array so that we can get smaller elements first
        sort(begin(nums), end(nums));
        
        long long sum = 0;
        
        // Previous element that we encountered
        int prev = 0, curr = 0;
        
        for(int i=0; i<n; i++) {
            
            curr = nums[i];
            
            // Get the difference b/w prev and current 
            // So that we can append elements that are in between them
            long long diff = (curr - prev - 1);
            
            // If prev and current are same then just skip
            if(diff <= 0) {
                prev = curr;
                continue;
            }
            
            // If there are more available elements b/w prev and current
            // Then we just take closest k element from prev.
            // And leave remaining as it is
            if(diff > k) {
                diff = k;
                curr = prev + k + 1;
            }
            
            // Get the sum of all elements b/w prev and current
            // Since it is AP series, we can use direct formula
            sum += (diff * 1LL * (curr + prev) / 2);
            
            // Update previous to current
            prev = curr;
            
            // Update count of how many more element we need to append 
            k -= diff;
            
            if(k == 0) break;
        }
        
        // Case : When we have reached the end of array 
        // And still we have some more element left to append
        if(k) {
            sum += (k * 1LL * (2 * prev + k + 1) / 2);
        }
        
        return sum;
    }
};
