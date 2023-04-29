class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int center = -1;
        for ( int i=0; i<n; ++i )
            if ( nums[i] == k ) center = i;
        // k not found in nums
        if ( center == -1 ) return 0;

        // init with 1 because nums[center] is an answer
        int ans = 1;
        // store the number of scores at the left, used for scenario 3
        unordered_map<int,int> cnt_l;
        for ( int i=center-1, sum=0; i>=0; --i ) {
            // sum is the accumulate score from center-1 to the left
            sum += (nums[i] < k) ? -1 : 1;
            // scenario 1: end with center
            if ( sum == 0 || sum == 1 ) ans++;
            // update the counter of this score
            cnt_l[sum]++;
        }
        for ( int i=center+1, sum=0; i<n; ++i ) {
            // sum is the accumulate score from center+1 to the right
            sum += (nums[i] < k) ? -1 : 1;
            // scenario 2: start with center
            if ( sum == 0 || sum == 1 ) ans++;
            // scenario 3: across center
            ans += cnt_l[-sum] + cnt_l[1-sum];
        }
        return ans;
    }
};