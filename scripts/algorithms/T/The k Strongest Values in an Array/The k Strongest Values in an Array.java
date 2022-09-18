// Runtime: 55 ms (Top 48.30%) | Memory: 81.3 MB (Top 78.98%)
class Solution {
    public int[] getStrongest(int[] arr, int k) {
        int[] result = new int[k];
        int n = arr.length, left = 0, right = n - 1, idx = 0;
        Arrays.sort(arr);
        int median = arr[(n - 1) / 2];
        while (left <= right) {
            int diff_l = Math.abs(arr[left] - median);
            int diff_r = Math.abs(arr[right] - median);

            if (diff_r > diff_l)
                result[idx++] = arr[right--];
            else if (diff_l > diff_r)
                result[idx++] = arr[left++];
            else if (arr[right] > arr[left])
                result[idx++] = arr[right--];
            else
                result[idx++] = arr[left++];
            if (idx == k)
                break;
        }
        return result;
    }
}