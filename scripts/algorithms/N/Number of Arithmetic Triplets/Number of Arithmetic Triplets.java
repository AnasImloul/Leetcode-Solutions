// Runtime: 1 ms (Top 98.25%) | Memory: 42.8 MB (Top 15.70%)

class Solution {
    public int arithmeticTriplets(int[] nums, int diff) {
        int result = 0;
        int[] map = new int[201];

        for(int num: nums) {
            map[num] = 1;

            if(num - diff >= 0) {
                map[num] += map[num - diff];
            }

            if(map[num] >= 3) result += 1;
        }

        return result;
    }
}