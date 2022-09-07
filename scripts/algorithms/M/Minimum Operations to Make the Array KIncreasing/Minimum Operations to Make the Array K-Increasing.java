// Runtime: 30 ms (Top 97.26%) | Memory: 101.5 MB (Top 84.93%)
class Solution {
    public int kIncreasing(int[] arr, int k) {
        int ans = arr.length;
        int[] tails = new int[arr.length];
        for (int i = 0; i < k; i ++) {
            int size = 0;
            for (int j = i; j < arr.length; j += k) {
                if (size == 0 || arr[j] >= tails[size - 1]) {
                    tails[size ++] = arr[j];
                } else {
                    int low = 0, high = size - 1;
                    while (low <= high) {
                        int mid = (low + high) / 2;
                        if (tails[mid] <= arr[j] && tails[mid + 1] > arr[j]) {
                            tails[mid + 1] = arr[j];
                            break;
                        } else if (tails[mid + 1] <= arr[j]) {
                            low = mid + 1;
                        } else {
                            high = mid - 1;
                        }
                    }
                    if (low > high) {
                        tails[0] = arr[j];
                    }
                }
            }
            ans -= size;
        }
        return ans;
    }
}