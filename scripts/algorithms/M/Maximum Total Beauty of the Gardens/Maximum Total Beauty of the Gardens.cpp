// Runtime: 1491 ms (Top 12.85%) | Memory: 85.2 MB (Top 46.18%)

class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        long long ans = 0;
        int n = flowers.size();
        if(n == 0) return 0;
        sort(flowers.begin(), flowers.end());
        vector<long long> pref(n, 0); // Prefix sums array
        pref[0] = flowers[0];
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + flowers[i];
        }
        for(int i = n; i >= 0; i--) {
            // When i is n, none of the elements are incremented till target.
            if(i < n) { // The ith element(0-indexed) is incremented till target. This is handling the case of "full". We are doing this from the end because it will cost the least number of new Flowers.
                long long toAdd = max(0, target - flowers[i]);
                if(newFlowers < toAdd) {
                    break; // We are breaking because we would've already found the best answer in the previous iterations
                }
                newFlowers -= toAdd;
                flowers.pop_back();
            }
            long long beautyForFullCase = (long long)(n - i) * full; // All the elements from i to n -1 are incremented till target, so they have a beauty of (n - 1) * full

            // Here, we do binary search on x, which is the the maximum number we can increment all the numbers from 0 to i - 1 to. The maximum we can increment to is target-1 because after that, "partial" will not be applicable. Binary search is done to find out the maximum possible answer for the partial case.
            int l = 0, r = target - 1;
            long long beautyForPartialCase = 0;
            while(l <= r) {
                long long mid = l + (r - l) / 2; // mid is the maximum number we can increment to
                auto it = upper_bound(flowers.begin(), flowers.end(), mid); // will point to an element that is atleast 1 more than the incomplete garden with most number of flowers
                if(it == flowers.begin()) { // there are no incomplete gardens
                    l = mid + 1;
                } else {
                    long long len = distance(flowers.begin(), it); // number of incomplete gardens
                    long long sum = pref[len - 1];
                    long long needed = ((long long)mid * len) - sum; // number of flowers needed to make "mid" as the minimum element
                    if(needed <= newFlowers) { // if it is possible to plant flowers such that the minimum number of flowers for any garden is "mid", then we go to check for higher values through Binary search
                        l = mid + 1;
                        beautyForPartialCase = (long long)mid * partial; // (minimum number of flowers in any incomplete garden) * (partial) = total beauty of incomplete gardens
                    } else {
                        r = mid - 1;
                    }
                }
            }
            ans = max(ans, beautyForFullCase + beautyForPartialCase); // checking if this answer is better than the previous answers computed.
        }
        return ans;
    }
};