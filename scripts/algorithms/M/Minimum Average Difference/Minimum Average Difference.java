// Runtime: 27 ms (Top 34.34%) | Memory: 76.7 MB (Top 35.00%)
class Solution {
    public int minimumAverageDifference(int[] nums) {
        if(nums.length == 1){
            return 0;
        }
        int idx = -1;
        long min = Integer.MAX_VALUE;
        long suml = nums[0];
        long sumr = 0;
        for(int i = 1; i < nums.length; i++){
            sumr += nums[i];
        }
        int i = 1;
        int calc = 0;
        int left = 1;
        int right = nums.length - left;
        long[] arr = new long[nums.length];
        while(i < nums.length){
            long diff = Math.abs((suml/left) - (sumr/right));
            arr[calc] = diff;
            if(diff < min){
                min = diff;
                idx = calc;
            }
            suml += nums[i];
            sumr -= nums[i];
            left++;
            right--;
            calc++;
            i++;
        }
        arr[calc] = suml/nums.length;
        if(arr[calc] < min){
            min = arr[calc];
            idx = nums.length - 1;
        }
        // for(i = 0; i < nums.length; i++){
        // System.out.println(arr[i]);
        // }
        return (int)idx;
    }
}