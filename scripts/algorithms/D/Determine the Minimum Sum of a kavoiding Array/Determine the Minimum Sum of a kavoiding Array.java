// Runtime: 1 ms (Top 100.0%) | Memory: 41.70 MB (Top 66.25%)

class Solution {
    int calculateSumInRange(int a, int n) {
        int sum = (n * (2 * a + (n - 1))) / 2;
        return sum;
    }

    public int minimumSum(int quantity, int k) {
        int middle = k / 2;
        
        if (quantity <= middle) {
            return quantity * (quantity + 1) / 2;
        }
        
        int leftSum = middle * (middle + 1) / 2;
        
        int remainingNumbers = quantity - middle;
        
        return leftSum + calculateSumInRange(k, remainingNumbers);
    }
}
