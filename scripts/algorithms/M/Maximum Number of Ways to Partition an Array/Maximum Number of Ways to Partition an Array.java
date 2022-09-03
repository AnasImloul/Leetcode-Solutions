// Runtime: 532 ms (Top 32.98%) | Memory: 178.2 MB (Top 67.02%)
class Solution {
    //time - O(n), space - O(n)
    public int waysToPartition(int[] nums, int k) {
        int n = nums.length;

        int[] pref = new int[n];
        pref[0] = nums[0];
        Map<Integer, Integer> count = new HashMap<>(); //contribution of prefixes without changing
        count.put(pref[0], 1);

        for (int i = 1; i < n - 1; i++){
            pref[i] += pref[i - 1] + nums[i];
            count.put(pref[i], count.getOrDefault(pref[i], 0) + 1);
        }
        pref[n - 1] += pref[n - 2] + nums[n - 1]; //last step doesn't add into 'count' map, because we're trying to find at least two parts.

        int sum = pref[n - 1];
        int max = 0;
        if (sum % 2 == 0)
            max = count.getOrDefault(sum / 2, 0); //max without changing

        Map<Integer, Integer> countPrev = new HashMap<>(); //contribution of prefixes before current step
        for (int i = 0; i < n; i++){
            int diff = k - nums[i];
            int changedSum = sum + diff;
            if (changedSum % 2 == 0)
                max = Math.max(max, count.getOrDefault(changedSum / 2 - diff, 0) + countPrev.getOrDefault(changedSum / 2, 0));
            count.put(pref[i], count.getOrDefault(pref[i], 0) - 1);
            countPrev.put(pref[i], countPrev.getOrDefault(pref[i], 0) + 1);
        }
        return max;
    }
}