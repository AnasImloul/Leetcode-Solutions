// Runtime: 68 ms (Top 62.80%) | Memory: 77 MB (Top 54.94%)
class Solution {
    public int longestSubsequence(int[] arr, int difference) {
        int max = 1;
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            // find the target element using the current element and the given difference
            int target = arr[i] - difference;
            // find if an AP for the target element exists in map and its length (else default to 1 - each element is an AP)
            int currAns = map.getOrDefault(target, 0) + 1;
            // add the current answer to the map
            // the amswer will override any previous answers with the same key (with an equal or greater answer)
            // for eg, in this case: .......X.....X
            // here X is the same number but the 2nd X will have an equal or larger AP sequence (logically)
            map.put(arr[i], currAns);
            // get max answer
            max = Math.max(max, currAns);
        }
        return max;
    }
}