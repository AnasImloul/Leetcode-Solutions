class Solution {
    int[] id;
    int[] tmp;
    int[] idTmp;
    int[] counts;
    public List<Integer> countSmaller(int[] nums) {
        int n = nums.length;
        id = new int[n];
        tmp = new int[n];
        idTmp = new int[n];
        counts = new int[n];
        for(int i = 0; i < n; i++) {
            id[i] = i;
        }
        mergesort(nums, 0, n);
        return IntStream.of(counts).boxed().collect(Collectors.toList());
    }
    
    void mergesort(int[] nums, int lo, int hi) {
        if(lo + 1 >= hi) {
            return;
        }
        int mid = lo + (hi - lo) / 2;
        mergesort(nums, lo, mid);
        mergesort(nums, mid, hi);
        merge(nums, lo, mid, hi);
    }
    
    void merge(int[] nums, int lo, int mid, int hi) {
        int j = lo, k = mid;
        for(int i = lo; i < hi; i++) {
            if(k == hi || (j < mid && nums[j] > nums[k])) {
                counts[id[j]] += (hi - k);
                idTmp[i] = id[j];
                tmp[i] = nums[j++];
            } else {
                idTmp[i] = id[k];
                tmp[i] = nums[k++];
            }
        }
        System.arraycopy(tmp, lo, nums, lo, hi - lo);
        System.arraycopy(idTmp, lo, id, lo, hi - lo);
    }
}
