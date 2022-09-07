// Runtime: 52 ms (Top 13.68%) | Memory: 77.1 MB (Top 37.46%)
class Solution {
    public int maxConsecutive(int bottom, int top, int[] special) {
        int max = Integer.MIN_VALUE;

        Arrays.sort(special);

        // from bottom to the first special floor
        max = Math.max(max, special[0] - bottom);

        // middle floors
        for(int i = 1; i < special.length; i++) {
            max = Math.max(max, special[i] - special[i - 1] - 1);
        }

        // from last special floor to the top
        max = Math.max(max, top - special[special.length - 1]);

        return max;
    }
}