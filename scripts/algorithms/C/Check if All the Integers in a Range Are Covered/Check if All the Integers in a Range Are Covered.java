// Runtime: 1 ms (Top 85.31%) | Memory: 41.7 MB (Top 83.50%)
class Solution {
    public boolean isCovered(int[][] ranges, int left, int right) {
        boolean flag = false;
        for (int i=left; i<=right; i++) {
            for (int[] arr: ranges) {
                if (i >= arr[0] && i <= arr[1]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) return false;
            flag = false;
        }

        return true;
    }
}