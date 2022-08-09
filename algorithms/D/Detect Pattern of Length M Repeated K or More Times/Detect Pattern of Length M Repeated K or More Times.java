// Time complexity: O(N)
// Space complexity: O(1)
class Solution {
    public boolean containsPattern(int[] arr, int m, int k) {
        int count = 0;
        for (int i = 0; i < arr.length - m; i++) {
            if (arr[i] == arr[i + m]) {
                count++;
            } else {
                count = 0;
            }
            if (count == m * (k-1)) {
                return true;
            }
        }
        return false;
    }
}
