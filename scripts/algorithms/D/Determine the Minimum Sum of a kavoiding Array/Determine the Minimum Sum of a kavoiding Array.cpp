// Runtime: 8 ms (Top 67.53%) | Memory: 6.30 MB (Top 91.56%)

class Solution {
public:
    int calculateSumInRange(int start, int count) {
        int sum = (count * (2 * start + (count - 1))) / 2;
        return sum;
    }
    
    int minimumSum(int quantity, int k) {
        int middle = k / 2;
        
        if (quantity <= middle) {
            return quantity * (quantity + 1) / 2;
        }
        
        int leftSum = middle * (middle + 1) / 2;
        
        int remainingNumbers = quantity - middle;
        
        return leftSum + calculateSumInRange(k, remainingNumbers);
    }
};
