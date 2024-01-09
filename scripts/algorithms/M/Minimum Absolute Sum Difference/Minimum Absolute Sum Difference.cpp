// Runtime: 149 ms (Top 82.87%) | Memory: 65.50 MB (Top 60.22%)

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int M = 1e9 + 7;
        int sum = 0;
        vector<int> diff(n);
        for(int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            //Avoid Integer Overflow Condition
            sum = (sum + diff[i]) % M;
        }
        sort(nums1.begin(), nums1.end());
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            int j = lower_bound(nums1.begin(), nums1.end(), nums2[i]) - nums1.begin();
            if(j != 0 && j != n) 
                arr[i] = min(abs(nums2[i] - nums1[j]), abs(nums2[i] - nums1[j - 1]));
            else if(j == 0) 
                arr[i] = abs(nums2[i] - nums1[j]);
            else if(j == n)
                arr[i] = abs(nums2[i] - nums1[j - 1]);
        }
        int bestSave = 0;
        for(int i = 0; i < n; i++) {
            bestSave = max(bestSave, diff[i] - arr[i]);
        }
        return (M + sum - bestSave) % M;
    }
};
