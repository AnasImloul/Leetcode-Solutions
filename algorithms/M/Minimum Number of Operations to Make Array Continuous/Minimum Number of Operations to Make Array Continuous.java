class Solution {
    public int minOperations(int[] nums) {
        TreeSet<Integer> set = new TreeSet<>();
        int threshold = nums.length-1;
        int max = 0;
        Arrays.sort(nums);
        for(int num:nums) {
            while(!set.isEmpty() && num-set.first()>threshold) {
                set.remove(set.first());
            } 
            set.add(num);
            max = Math.max(max, set.size());   
        }
        return nums.length-max;
    }
}
