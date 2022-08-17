class Solution {
    /*
        1. let's assume we have an array with 2 * n size
            from [2,3,1,4,0] to [2,3,1,4,0,2,3,1,4,0]
        2. loop through every element from left to right
            index 0 1 2 3 4 5 6 7 8 9
                 [2,3,1,4,0,2,3,1,4,0]
        3. we can find the different value between index and element, we only keep value >= 0
            index 0 1 2 3 4 5 6 7 8 9
                 [2,3,1,4,0,2,3,1,4,0]
            value     1   4 3 3 6 4 9
        4. we perform sliding window(size n) on this pattern
            l = left pointer of window, r = current right pointer
            index 0 1 2 3 4 5 6 7 8 9
                 [2,3,1,4,0,2,3,1,4,0]
            value     1   4 3 3 6 4 9 : if left pointer pass this value, this value cannot be counted in result
                  l       r
            value : if left pointer smaller than or equal to 1, we can keep it in window
                    (largest left pointer index to keep this element in our window)
        5. we use variable "sum" to keep tracking current count of valid elements
            but we need to remove invalid value from "sum"
        6. in order to remove invalid left pointer / value, we need count[] array to mark element count at that index
            before moving left pointer point to next index, we need to use sum - count[left]
   example   
            index 0 1 2 3 4 5 6 7 8 9
                 [2,3,1,4,0,2,3,1,4,0]
            value     1   4 3 3 6 4 9
    left = 0, right = 2, sum = 1, count = {{1:1}}
    left = 0, right = 4, sum = 2, count = {{1:1}, {4:1}}
    left = 1, right = 5, sum = 3, count = {{1:1}, {4:1}, {3:1}}
        after calculate max / possible result, we need to remove count[left] from sum
    left = 1, right = 5, sum = (3 - count[left]) = 2, count = {{1:1}, {4:1}, {3:1}}
    left = 2, right = 6, sum = 3, count = {{1:1}, {4:1}, {3:2}}
    left = 3, right = 7, sum = 4, count = {{1:1}, {4:1}, {3:2}, {6:1}}
        after calculate max / possible result, we need to remove count[left] from sum
    left = 3, right = 7, sum = (4 - count[left]) = 2, count = {{1:1}, {4:1}, {3:2}, {6:1}}
    left = 4, right = 8, sum = 3, count = {{1:1}, {4:2}, {3:2}, {6:1}}
        after calculate max / possible result, we need to remove count[left] from sum
    left = 4, right = 8, sum = (3 - count[left]) = 1, count = {{1:1}, {4:2}, {3:2}, {6:1}}    
    ....
    
    
    */
    public int bestRotation(int[] nums) {
        int n = nums.length;
        int[] cnt = new int[2 * n];
        int max = 0;
        int res = 0;
        for(int r = 0, l = 0, sum = 0; r < 2 * n; r++) {
            int v = r - nums[r % n];
            if(v >= 0) {
                cnt[Math.min(2 * n - 1, v)]++;
                if(v >= l) {
                    sum++;
                }
            }
            if(r - l == n - 1) {
                if(sum > max) {
                    max = sum;
                    res = l;
                }
                sum -= cnt[l];
                l++;
            }
        }
        return res;
    }
}
