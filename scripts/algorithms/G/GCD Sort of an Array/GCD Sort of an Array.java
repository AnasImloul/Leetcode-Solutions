// Runtime: 47 ms (Top 94.62%) | Memory: 71.9 MB (Top 80.64%)
class Solution {
    private static final int[] primes;
    // precompute prime numbers
    static {
        primes = new int[5133];
        final int max = 100000 / 2;
        boolean[] notprime = new boolean[max];
        for (int index = 0, i = 2; i < max; i++) {
            if (notprime[i]) continue;
            primes[index++] = i;
            for (int j = (max - 1) / i; j >= 2; j--) notprime[i * j] = true;
        }
    }

    public boolean gcdSort(int[] nums) {
        final var sorted = nums.clone();
        Arrays.sort(sorted);
        final int len = nums.length, max = sorted[len - 1];
        final int[] map = new int[max + 1]; // grouping tree child->parent
        for (int i = 0; i < len; i++) map[nums[i]] = nums[i];

        for (final var p : primes) {
            if (p > max / 2) break;
            int group = p;
            map[p] = p;
            for (int num = p + p; num <= max; num += p) {
                var existing = map[num];
                if (existing == 0) continue; // value doens't exist in array
                if (existing == num) map[num] = group; // 1st hit, set group, otherwise, group merging
                else if ((existing = root(map, existing)) < group) {
                    map[group] = existing;
                    group = existing;
                } else map[existing] = group;
            }
        }

        for (int i = 0; i < len; i++) if (root(map, nums[i]) != root(map, (sorted[i]))) return false;
        return true;
    }

    private static int root(int[] map, int num) {
        int group;
        while (num != (group = map[num])) num = group;
        return group;
    }
}