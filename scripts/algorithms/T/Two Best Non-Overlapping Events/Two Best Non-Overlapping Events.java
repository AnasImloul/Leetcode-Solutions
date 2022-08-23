// Runtime: 92 ms (Top 45.29%) | Memory: 159.8 MB (Top 35.88%)
class Solution {
    public int maxTwoEvents(int[][] events) {
        Arrays.sort(events, (a, b) -> a[0] - b[0]);
        int onRight = 0, maxOne = 0, n = events.length;
        int[] rightMax = new int[n+1];
        for (int i = n - 1; i >= 0; i--) {
            int start = events[i][0], end = events[i][1], val = events[i][2];
            maxOne = Math.max(val, maxOne);
            rightMax[i] = Math.max(rightMax[i+1], val);
        }
        int two = 0;
        for (int i = 0; i < n; i++) {
            int start = events[i][0], end = events[i][1], val = events[i][2];
            int idx = binarySearch(end, events);
            if (idx < n) {
                two = Math.max(rightMax[idx] + val, two);
            }
        }
        return Math.max(two, maxOne);
    }

    public int binarySearch(int end, int[][] arr) {
        int left = 0, right = arr.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid][0] > end) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}