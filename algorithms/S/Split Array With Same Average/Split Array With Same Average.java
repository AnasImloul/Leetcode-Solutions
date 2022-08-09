class Solution {
    public boolean splitArraySameAverage(int[] nums) {
        int n = nums.length, sum = Arrays.stream(nums).sum();
        Set<Integer>[] a = new HashSet[n/2+1];
        Set<Integer>[] b = new HashSet[n/2+2];
        Arrays.setAll(a, o -> new HashSet<>());
        Arrays.setAll(b, o -> new HashSet<>());
        gen(0, n/2, 0, 0, nums, a);
        gen(n/2, n, 0, 0, nums, b);
        for (int i = 0; i < a.length; i++){ // i = num of elements selected from A
            for (int j = 0; j < b.length; j++){ // j = num of elements selected from B
                if (i+j>0 && i+j < n && sum*(i+j)%n == 0){
                    for (int cur : a[i]){ // do Two Sum
                        if (b[j].contains(sum*(i+j)/n-cur)){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    
    private void gen(int cur, int n, int bits, int sum, int[] nums, Set<Integer>[] set){
        set[bits].add(sum);
        if (cur < n){
            gen(cur+1, n, bits+1, sum+nums[cur], nums, set);
            gen(cur+1, n, bits, sum, nums, set);
        }
    }
}
