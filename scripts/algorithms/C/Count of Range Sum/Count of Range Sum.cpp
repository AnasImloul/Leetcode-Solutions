// Runtime: 1496 ms (Top 27.73%) | Memory: 68.2 MB (Top 89.04%)
class Solution {
public:
    using ll = long long;

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        // Build prefix sums
        vector<ll> prefixSums(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            prefixSums[i + 1] = prefixSums[i] + nums[i];
        }

        // Run merge sort and count range sum along the way
        tempNums.assign(prefixSums.size(), 0);
        splitAndMerge(prefixSums, 0, prefixSums.size(), lower, upper);

        return count;
    }

    void splitAndMerge(vector<ll> &nums, const int left, const int right, const int lower, const int upper) {
        if (right - left <= 1) return;
        const int mid = left + (right - left) / 2;
        splitAndMerge(nums, left, mid, lower, upper);
        splitAndMerge(nums, mid, right, lower, upper);

        countRangeSums(nums, left, mid, right, lower, upper);

        merge(nums, left, mid, right);
    }

    void countRangeSums(const vector<ll> &prefixSums, const int left, const int mid, const int right, const int lower, const int upper) {
        // S(i,j) == prefixSums[j+1] - prefixSums[i] (i <= j)
        // S(i,j) == prefixSums[k] - prefixSums[i] (let k=j+1, i < k)
        //
        // lower <= S(i,j) <= upper
        // => lower <= prefixSums[k] - prefixSums[i] <= upper
        // => lower + prefixSums[i] <= prefixSums[k] <= upper + prefixSums[i]
        for (int i = left; i < mid; i++) {
            const ll newLower = lower + prefixSums[i];
            const ll newUpper = upper + prefixSums[i];
            const auto findStart = prefixSums.begin() + mid;
            const auto findEnd = prefixSums.begin() + right;
            const auto itFoundLower = std::lower_bound(findStart, findEnd, newLower);
            const auto itFoundUpper = std::upper_bound(findStart, findEnd, newUpper);
            count += (itFoundUpper - itFoundLower);
        }
    }

    void merge(vector<ll> &nums, const int left, const int mid, const int right) {
        std::copy(nums.begin() + left, nums.begin() + right, tempNums.begin() + left);
        int i = left, j = mid;
        for (int k = left; k < right; k++) {
            if (i < mid && j < right) {
                if (tempNums[i] < tempNums[j]) {
                    nums[k] = tempNums[i++];
                } else {
                    nums[k] = tempNums[j++];
                }
            } else if (i >= mid) {
                nums[k] = tempNums[j++];
            } else { // j >= right
                nums[k] = tempNums[i++];
            }
        }
    }

    vector<ll> tempNums;
    int count = 0;
};