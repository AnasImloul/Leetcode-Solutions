class Solution {
public:

    // Compute max score across all cases
    //  1. (arr_sum * k) [array sum is positive]
    //  2. (subarray_sum) [k == 1]
    //  3. if k > 1:
    //          if k == 2: lm + rm
    //          else: lm + (arr_sum * (k-2)) + rm

    // For case:3, instead of running over the entire modified array,
    //  we can just add (arr_sum * (k-2)) to the 's' instead.

    int kConcatenationMaxSum(vector<int>& arr, int k) {
        
        const int n = arr.size();
        int64_t s{}, min_s{}, max_score{INT_MIN};
        
        // This loop computes the answer for case:2
        for(int i=0; i<n; i++){
            s += arr[i];
            max_score = max(max_score, s - min_s);
            min_s = min(min_s, s);
        }
        
        if(k > 1){
            // Condition for case:3 part:2
            // At this point, 's' holds the sum of all numbers in 'arr'
            if(k > 2) s = max(s, s + s * (k - 2));
            // Base logic for case:3 part:1
            for(int i=0; i<n; i++){
                s += arr[i];
                max_score = max(max_score, s - min_s);
                min_s = min(min_s, s);
            }
        }

        // If all numbers are positive, case:1 is automatically computed with
        //  the method given above.
        //  Because (for an array with all positive elements):
        //      (max_score [after first loop]) == (arr_sum)
        //      s is updated to (s + s * (k - 2))
        //      Finally, s (and subsequently max_score) is also updated to (arr_sum * k)

        // Apply modulo on answer and convert to int
        int ans = static_cast<int>(max_score % (1000000000 + 7));
        // Subarray can have length == 0 (and sum == 0)
        if(ans < 0) return 0;
        else return ans;
    }
};
