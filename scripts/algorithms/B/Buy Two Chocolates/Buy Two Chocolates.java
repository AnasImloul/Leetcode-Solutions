// Runtime: 1 ms (Top 100.0%) | Memory: 44.40 MB (Top 36.98%)

class Solution {
    public int buyChoco(int[] prices, int money) {
        int firstMinCost = Integer.MAX_VALUE;
        int secondMinCost = Integer.MAX_VALUE;

        for (int p : prices) {
            if (p < firstMinCost) {
                secondMinCost = firstMinCost;
                firstMinCost = p;
            } else {
                secondMinCost = Math.min(secondMinCost, p);
            }
        }

        int leftover = money - (firstMinCost + secondMinCost);

        return leftover >= 0 ? leftover : money;        
    }
}
