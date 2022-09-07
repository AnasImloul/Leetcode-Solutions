// Runtime: 438 ms (Top 14.29%) | Memory: 113.8 MB (Top 74.48%)
/**
 * @brief
 * Given two array, return the minimum numbers we have to change the values to make two arrays sum equal
 *
 * [Observation]
 * Since the value is from 1 ~ 6
 *
 * Min sum of the array = len(arr)
 * Max sum of the array = 6 len(arr)
 *
 * When to arrays range cannot overlap -> no answer
 *
 * If there is a answer -> sum s, value will be between s1 and s2
 * So, let's say if s1 is smaller, we would like to increase s1's element and decrease s2's element
 * -> We only have to design for s1 is smaller than s2.
 *
 * [Key] Which element's should we increase and decrease?
 * To minimize the changing elements, we change the number who can mostly decrease the differences.
 * So, we compare the smallest element in num1 and largest in num2.
 * -> sorting
 *
 * @algo sorting + greedy
 * Time O(NlogN) for sorting
 * Space O(1)
 */
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size(); // l1 ~ 6l1
        int l2 = nums2.size(); // l2 ~ 6l2

        if(6*l1 < l2 || 6*l2 < l1) {
            return -1;
        }

        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        if(sum1 > sum2) return minOperations(nums2, nums1);

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end(), greater<int>());
        // let us design the way where sum1 <= sum2
        int ans = 0, ptr1 = 0, ptr2 = 0;
        int diff = sum2 - sum1;

        while(diff > 0) {
            if(ptr2 == l2 || ptr1 < l1 && (6 - nums1[ptr1]) >= (nums2[ptr2] - 1)) {
                diff -= (6 - nums1[ptr1]);
                ans++;
                ptr1++;
            }
            else {
                diff -= (nums2[ptr2] - 1);
                ans++;
                ptr2++;
            }
        }
        return ans;
    }
};