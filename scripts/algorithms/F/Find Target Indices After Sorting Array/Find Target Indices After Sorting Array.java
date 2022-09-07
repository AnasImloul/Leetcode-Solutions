// Runtime: 2 ms (Top 82.14%) | Memory: 43.8 MB (Top 60.21%)
class Solution {
    /** Algorithm:
        - Parse the array once and count how many are lesser than target and how many are equal
        - DO NOT sort the array as we don't need it sorted.
          Just to know how many are lesser and how many are equal. O(N) better than O(NlogN - sorting)
        - The response list will have a size = with the number of equal elements (as their positions)
        - Loop from smaller to smaller+equal and add the values into the list. Return the list
    */
    public List<Integer> targetIndices(int[] nums, int target) {
        int smaller = 0;
        int equal = 0;
        for (int num : nums) {
            if (num < target) {
                smaller++;
            } else if (num == target) {
                equal++;
            }
        }
        List<Integer> indices = new ArrayList<>(equal);
        for (int i = smaller; i < smaller + equal; i++) {
            indices.add(i);
        }
        return indices;
    }
}