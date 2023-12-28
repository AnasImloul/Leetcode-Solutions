// Runtime: 15 ms (Top 15.67%) | Memory: 45.10 MB (Top 6.59%)

class Solution {
    public int findMaxK(int[] nums) {
        Arrays.sort(nums);
        HashSet<Integer> set = new HashSet<>();
        for(int i = 0 ; i < nums.length ; i++){
            set.add(nums[i]);
        }
        for(int i = nums.length-1; i>=0 ; i--){//Checking the largest numbers from the last index as the array is sorted
            if(set.contains(-nums[i])){
                return nums[i];
            }
        }
        return -1;
    }
}
