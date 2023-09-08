// Runtime: 1 ms (Top 99.9%) | Memory: 44.19 MB (Top 7.0%)

class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        // Sort the input array to handle duplicates properly
        Arrays.sort(nums);
        // Start the recursion with an empty prefix list
        return subset(new ArrayList<Integer>(), nums);
    }
    
    // Recursive function to generate subsets
    public List<List<Integer>> subset(ArrayList<Integer> prefix, int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        
        // Base case: If there are no elements in nums, add the current prefix to result
        if (nums.length == 0) {
            result.add(new ArrayList<>(prefix));
            return result;
        }
        
        // Include the first element of nums in the prefix
        ArrayList<Integer> withCurrent = new ArrayList<>(prefix);
        withCurrent.add(nums[0]);
        
        // Recursive call with the first element included
        List<List<Integer>> left = subset(withCurrent, Arrays.copyOfRange(nums, 1, nums.length));
        
        List<List<Integer>> right = new ArrayList<>();
        
        // Check for duplicates in the prefix and decide whether to include the first element again
        if (prefix.size() > 0 && prefix.get(prefix.size() - 1) == nums[0]) {
            // If the current element is a duplicate, don't include it in the prefix
            // This avoids generating duplicate subsets
        } else {
            // If the current element is not a duplicate, include it in the prefix
            right = subset(prefix, Arrays.copyOfRange(nums, 1, nums.length));
        }
        
        // Combine the subsets with and without the current element
        left.addAll(right);
        return left;
    }
}