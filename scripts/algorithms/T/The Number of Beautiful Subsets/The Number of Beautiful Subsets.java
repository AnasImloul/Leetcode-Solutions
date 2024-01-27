// Runtime: 7 ms (Top 91.11%) | Memory: 44.20 MB (Top 70.55%)

class Solution {
    int[][] s;

    private void mapToList(Map<Integer, Integer> fr) {
        s = new int[fr.size()][2];
        int i = 0;
        for (Map.Entry<Integer, Integer> x: fr.entrySet()) {
            s[i][0] = x.getKey();
            s[i][1] = x.getValue();
            i++;
        }
    }

    private int beautifulSubsets(int n, int k, int i) {
        if (i == n) {
            return 1;
        }
        int skip = beautifulSubsets(n, k, i + 1); // 1 * f(i + 1)
        int take = (1 << s[i][1]) - 1; // take s[i]
        if (i + 1 < n && s[i + 1][0] - s[i][0] == k) { // next number is s[i] + k
            take *= beautifulSubsets(n, k, i + 2);
        } else {
            take *= beautifulSubsets(n, k, i + 1);
        }
        return skip + take;
    }

    public int beautifulSubsets(int[] nums, int k) {
        int result = 1;
        Map<Integer, Map<Integer, Integer>> freq = new TreeMap<>();
        // {remainder : {num :    frequency}}
        // map is sorted based on num to get subset of form [x, x + k, x + 2k, ...]
        for (int x: nums) { // splitting subsets based on remainder and calculating frequency
            Map<Integer, Integer> fr = freq.getOrDefault(x % k, new TreeMap<>());
            fr.put(x, fr.getOrDefault(x, 0) + 1);
            freq.put(x % k, fr);
        }
        for (Map fr: freq.values()) { // loop for s1, s2, ...
            mapToList(fr);
            result *= beautifulSubsets(s.length, k, 0); // f(s1) * f(s2) ...
        }
        return result - 1; // -1 for empty subset
    }
}
