// Runtime: 3 ms (Top 98.54%) | Memory: 42 MB (Top 43.12%)
/*
    Time complexity: O(2 ^ n)
    Space complexity: O(n)

    Inutition:
    ---------
    Same as "Partition to K Equal Sum Subsets"
*/

class Solution {
    public boolean backtrack(int[] nums, int idx, int k, int subsetSum, int target, boolean[] vis) {
        // base case
        if (k == 0)
            return true;
        if (target == subsetSum) {
            // if one of the side is found then keep finding the other k - 1 sides starting again from the beginning
            return backtrack(nums, 0, k - 1, 0, target, vis);
        }

        // hypothesis
        for(int i = idx; i < nums.length; i++) {
            // if number is already visited or sum if out of range then skip
            if (vis[i] || subsetSum + nums[i] > target)
                continue;

            // Pruning
            // if the last position (i - 1) is not visited, that means the current combination didn't work,
            // and since this position (i) has the same value, it won't work for it as well. Thus, skip it.
            if (i - 1 >= 0 && nums[i] == nums[i - 1] && !vis[i - 1])
                continue;

            vis[i] = true;
            if (backtrack(nums, i + 1, k, subsetSum + nums[i], target, vis))
                return true;

            // backtrack
            vis[i] = false;
        }

        return false;
    }

    private void reverse(int[] arr) {
        for (int i = 0, j = arr.length - 1; i < j; i++, j--) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

    public boolean makesquare(int[] matchsticks) {
        int sum = 0;
        int k = 4;
        int n = matchsticks.length;
        // sort the array in descending order to make the recursion hit the base case quicker
        Arrays.sort(matchsticks);
        reverse(matchsticks);

        for(int match: matchsticks)
            sum += match;

        if (sum % k != 0)
            return false;

        int target = sum / k;
        boolean[] vis = new boolean[n];

        return backtrack(matchsticks, 0, k, 0, target, vis);
    }
}