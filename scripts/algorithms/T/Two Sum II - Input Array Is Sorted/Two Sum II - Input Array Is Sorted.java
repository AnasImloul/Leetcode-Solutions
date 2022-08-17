class Solution {
    public int[] twoSum(int[] numbers, int target) {
        for (int i = 0; i < numbers.length-1; ++i) {
            int res = binarySearch(numbers, numbers[i], target, i+1);
            if (res != -1) return new int[]{i+1,res+1};
        }
        return new int[]{1,2};
    }
    public static int binarySearch(int[] arr, int curr, int target, int s) {
        int e = arr.length-1;
        int m = (s+e)/2;
        
        while (s<=e) {
            if (arr[m]+curr == target) {
                return m;
            } else if (arr[m]+curr > target) {
                e = m-1;
            } else {
                s = m+1;
            }
            m = (s+e)/2;
        }
        return -1;
    }
}
