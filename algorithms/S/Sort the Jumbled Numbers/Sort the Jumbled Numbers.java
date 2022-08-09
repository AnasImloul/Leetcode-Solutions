class Solution {
    public int[] sortJumbled(int[] mapping, int[] nums) {
        int []mapped = new int[nums.length];
        HashMap<Integer, ArrayList<Integer>> map = new HashMap<>();
        for(int i = 0; i < nums.length; i++){
            int number = nums[i];
            int idx = 1;
            int mapped_number = 0;
            while (number > 0) {
            int remainder = number % 10;
            mapped_number = mapped_number + (mapping[remainder] * idx );
            number = number / 10;
            idx *= 10;
        }
            if(nums[i] == 0){
                mapped_number = mapping[0];
            }
            mapped[i] = mapped_number;
            if (!map.containsKey(ans[i])) {
            map.put(mapped[i], new ArrayList<Integer>());
            }
            map.get(mapped[i]).add(nums[i]);
                
        }
        Arrays.sort(mapped);
        int idx = 0;
        for(int i = 0; i < mapped.length; i++){
            if(map.containsKey(mapped[i])){
            for(int val: map.get(mapped[i])){
                nums[idx] = val;
                idx++;
            }
            }
            map.remove(mapped[i]);
        }
        return nums;
    }
}
