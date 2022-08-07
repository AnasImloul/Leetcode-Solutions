/*
- Time: O(N*log(N))
Loop through the array with n elements and run binary search with log(N) time for each of them.

- Space: O(N)
Used a hashmap map of size N to store the original indeces of intervals
 */
class Solution {
    public int[] findRightInterval(int[][] intervals) {
        int n = intervals.length;
        int[] res = new int[n];
        Map<int[], Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            map.put(intervals[i], i);
        }

        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        for (int i = 0; i < n; i++) {
            int[] interval = binarySearch(intervals, intervals[i][1], i);
            res[map.get(intervals[i])] = interval == null ? -1 : map.get(interval);
        }
        
        return res;
    }

    private int[] binarySearch(int[][] intervals, int target, int start) {
        int l = start, r = intervals.length - 1;
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (intervals[m][0] >= target) {
                // keep moving the right boundary to the left to get the first
                // element bigger than target
                r = m - 1;
            } else {
                // if the element we get is bigger than the target, we move the 
                // left boundary to look at right part of the array
                l = m + 1;
            }
        }
        return l == intervals.length ? null : intervals[l];
    }
}
