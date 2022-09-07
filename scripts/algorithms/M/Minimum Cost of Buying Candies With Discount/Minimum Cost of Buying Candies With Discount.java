// Runtime: 3 ms (Top 83.40%) | Memory: 42.5 MB (Top 73.57%)
class Solution {
    /** Algorithm
     * 1. Sort the cost array.
     * 2. In a loop, start from the back and buy items n, n-1 to get n-2 for free.
     * 3. Decrement the position by 3 and continue. stop when you reach 1.
     * 4. From 1, add the remaining 1 or 2 items.
     *
     */
    public int minimumCost(int[] cost) {
        int minCost = 0;
        int index = cost.length -1;
        Arrays.sort(cost);
        // add items in pairs of 2, the 3rd one getting it for free.
        while (index > 1) {
            minCost += cost[index] + cost[index -1];
            index -= 3;
        }
        // add the remaining 1, 2 items, if any.
        while(index >= 0) {
            minCost += cost[index--];
        }
        return minCost;
    }
}