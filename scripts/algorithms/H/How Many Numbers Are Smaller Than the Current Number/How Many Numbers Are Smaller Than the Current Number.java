// Runtime: 8 ms (Top 76.25%) | Memory: 44.5 MB (Top 55.91%)
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] sorted = nums.clone();
        int[] res = new int[nums.length];//result array
        Arrays.sort(sorted);
        for (int i = 0; i < nums.length; ++i) {
            //binary search it, if there is no duplicates the idx will be how many smaller are there
            int idx = binarySearch(sorted, nums[i]);
            //if there are duplicates, then we need to find the first one presented in the array
            if (idx-1>=0 && sorted[idx-1] == nums[i]) {
                while (idx >= 0 && sorted[idx] == nums[i]) {
                    --idx;
                }
                ++idx;
            }
            //As I said before, array of indices(indexes) will be the answer
            res[i] = idx;
        }
        return res;
    }
    //Just simple iterative binary search
     public static int binarySearch(int[] arr, int target) {
        int s = 0;
        int e = arr.length-1;
        int m = (s+e)/2;

        while (s<=e) {
            if (arr[m] == target) {
                return m;
            } else if (arr[m] > target) {
                e = m-1;
            } else {
                s = m+1;
            }
            m = (s+e)/2;
        }
        return -1;
    }
}