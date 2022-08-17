// If absolute of n is less than min, update the closest_num 
// If absolute of n is same of as min, update the bigger closest_num

class Solution {
    public int findClosestNumber(int[] nums) {
        int min = Integer.MAX_VALUE, closest_num = 0;
        for(int n : nums) {
            if(min > Math.abs(n)) {
                min = Math.abs(n);
                closest_num = n;
            } else if(min == Math.abs(n) && closest_num < n) {
                closest_num = n;
            }
        }
        return closest_num;
    }
}
