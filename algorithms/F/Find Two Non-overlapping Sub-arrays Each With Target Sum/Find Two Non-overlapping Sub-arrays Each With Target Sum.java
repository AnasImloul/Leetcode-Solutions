class Solution {
    public int minSumOfLengths(int[] arr, int target) { //this fits the case when there's negative number, kind like 560
        if (arr == null || arr.length == 0) return 0;
        Map<Integer, Integer> map = new HashMap<>(); //sum - index
        map.put(0, -1);
        int sum = 0;
        for (int i = 0; i < arr.length; i++) { //record preSum and index
            sum += arr[i];
            map.put(sum, i);
        }
        sum = 0;
        int size = arr.length + 1, res = arr.length + 1;//note if we set size as MAX_VALUE the line 16 may overflow
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
            if (map.containsKey(sum - target)) size = Math.min(size, i - map.get(sum - target)); //find the subarray from the previous index to current one
            if (map.containsKey(sum + target)) res = Math.min(res, size + map.get(sum + target) - i); //from the current index to next one, this avoid overlap
        }
        return res == arr.length + 1 ? -1 : res;
    }
}
