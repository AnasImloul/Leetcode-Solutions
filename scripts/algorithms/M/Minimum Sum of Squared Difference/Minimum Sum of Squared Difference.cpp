// Runtime: 133 ms (Top 92.5%) | Memory: 102.80 MB (Top 75.0%)

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);
        for(int i = 0; i<n; ++i) {
            diff[i] = abs(nums1[i] - nums2[i]);
        }
        int M = *max_element(diff.begin(), diff.end());
        vector<int> bucket(M+1);
        for(int i = 0 ; i<n; ++i) {
            bucket[diff[i]]++;
        }
        int k = k1 + k2;
        for(int i = M; i > 0; --i) {
            if(bucket[i] > 0) {
                int minus = min(bucket[i], k);
                bucket[i] -= minus;
                bucket[i-1] += minus;
                k -= minus;
            }
        }
        long long ans = 0;
        for(long long i = M; i > 0; --i) {
            ans += bucket[i]*i*i;
        }
        return ans;
    }
};
