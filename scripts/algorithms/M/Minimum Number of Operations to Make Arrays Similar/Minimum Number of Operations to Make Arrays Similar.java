// Runtime: 42 ms (Top 84.38%) | Memory: 62.00 MB (Top 6.25%)

class Solution {
    public long makeSimilar(int[] nums, int[] target) {
        Arrays.sort(nums);
        Arrays.sort(target);
        int len = nums.length, i, p = 0, j = 0, k = 0;
        long sum1 = 0, sum2 = 0;
        List<Integer> odd1 = new ArrayList<>();
        List<Integer> even1 = new ArrayList<>();
        for(i = 0; i < len; i++){
            if(nums[i] % 2 == 0)
                even1.add(nums[i]);
            else
                odd1.add(nums[i]);
        }
        for(i = 0; i < len; i++){
            if(target[i] % 2 == 0){
                sum1 += (long)Math.abs(even1.get(j) - target[i]);
                j++;
            }
            else{
                sum2 += (long)Math.abs(odd1.get(k) - target[i]);
                k++;
            }
        }
        sum1 /= 2;
        sum2 /= 2;
        return (sum1 + sum2) / 2;
    }
}
