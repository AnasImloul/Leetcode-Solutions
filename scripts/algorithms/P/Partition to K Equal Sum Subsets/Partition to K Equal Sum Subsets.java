// Runtime: 277 ms (Top 51.4%) | Memory: 43.53 MB (Top 23.8%)

class Solution {
    private final List<Set<Integer>> allSubsets = new ArrayList<>();
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum = Arrays.stream(nums).sum();
        if(sum % k != 0) return false;
        getAllSubsets(nums.length, sum / k, new HashSet<>(), nums, false);
        return allSubsets.size() >= k && canPartition(allSubsets.size(), k, nums.length, new HashSet<>());
    }

    private boolean canPartition(int n, int k, int size, Set<Integer> current) {
        if(k == 0 && current.size() == size) return true;
        if(n == 0 || k < 0) return false;
        boolean addSet = false;
        if(allUnique(current, allSubsets.get(n-1))) {
            current.addAll(allSubsets.get(n - 1));
            addSet = canPartition(n - 1, k - 1, size, current);
            current.removeAll(allSubsets.get(n - 1));
        }
        return addSet || canPartition(n - 1, k, size, current);
    }

    private void getAllSubsets(int n, int targetSum, Set<Integer> subsets, int[] nums, boolean lol) {
        if(targetSum == 0) {
            allSubsets.add(new HashSet<>(subsets));
            return;
        }
        if (n == 0 || targetSum < 0) return;
        subsets.add(n-1);
        getAllSubsets(n-1, targetSum - nums[n-1], subsets, nums, true);
        subsets.remove(n-1);
        getAllSubsets(n-1, targetSum, subsets, nums, false);
    }
    
    private boolean allUnique(Set<Integer> set1, Set<Integer> set2) {
        for (Integer num: set1) if(set2.contains(num)) return false;
        return true;
    }
}