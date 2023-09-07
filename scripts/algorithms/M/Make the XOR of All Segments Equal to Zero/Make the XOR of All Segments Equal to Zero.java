// Runtime: 31 ms (Top 100.0%) | Memory: 43.98 MB (Top 84.6%)

class Solution {
    public int minChanges(int[] nums, int k) {
        // solution (sequence) is uniquely defined by the first k elements, because a[i] == a[i+k] == a[i+2k] == ... for any offset i
        int v = 1 << 10;
        // best[pattern] is the highest number of relevant (ie. those with offsets between 0 and i) elements in nums
        // that can be left unchanged to achieve a[0] ^ a[1] ^ ... ^ a[i] == pattern
        int[] best = new int[v];
        // iterate over over each offset i of the solution
        for (int i = 0; i < k; i++) {
            // find frequencies of distinct element values present in the subsequence with offset i
            Map<Integer,Integer> n2c = new HashMap<Integer,Integer>();
            for (int p = i; p < nums.length; p += k) {
                n2c.put(nums[p],1+n2c.getOrDefault(nums[p],0));
            }
            // treat initial subsequence (i = 0) correctly
            if (i == 0) {
                for (int vv : n2c.keySet()) {
                    best[vv] = n2c.get(vv);
                }
                continue;
            }
            int[] next = new int[v];
            int max = 0;
            for (int j : best) max = Math.max(max, j);
            // elements previously unchanged (ie. from subsequences with offsets 0, 1, 2, .., i-1) can be carried to the current offset i
            // max of all best[] is used
            for (int j = 0; j < v; j++) next[j] = max;
            // for elements present in the subsequnce with offset i next[] can be improved accordingly
            for (int vv : n2c.keySet()) {
                int cnt = n2c.get(vv);
                for (int j = 0; j < v; j++) {
                    next[j ^ vv] = Math.max(next[j ^ vv], best[j] + cnt);
                }
            }
            best = next;
        }
        // solution is for pattern == 0, hence best[0]. Report minimum number of elements to change rather than maximum that can be left unchanged.
        return nums.length - best[0];
    }
}