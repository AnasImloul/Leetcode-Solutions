// Runtime: 3 ms (Top 81.75%) | Memory: 52.8 MB (Top 24.19%)
class Solution {
    public int longestMountain(int[] arr) {
        if (arr.length < 3)
            return 0;
        int max = 0;
        for (int i = 0; i < arr.length; i++) {
            if (isPeak(arr, i)) {
                int leftLength = left(arr, i);
                int rightLength = right(arr, i);
                max = Math.max(max, leftLength + rightLength + 1);
            }
        }
        return max;
    }

    public int left(int[] arr, int i) {
        int j = i - 1;
        while (j >= 0 && arr[j] < arr[j + 1])
            j--;
        return i - (j + 1);
    }

    public int right(int[] arr, int i) {
        int j = i + 1;
        while (j < arr.length && arr[j - 1] > arr[j])
            j++;
        return j - (i + 1);
    }

    public boolean isPeak(int[] arr, int i) {
        return i - 1 >= 0 && i + 1 < arr.length && arr[i - 1] < arr[i] && arr[i + 1] < arr[i];
    }
}