// Runtime: 4 ms (Top 100.0%) | Memory: 44.20 MB (Top 14.75%)

class Solution {
    public int distanceTraveled(int mainTank, int additionalTank) {
        int i = 1;
        int feul = mainTank;
        while(feul - 4 * i > 0 && additionalTank-- > 0) i++;
        i--;
        return (i * 5 + feul - i * 4) * 10;
    }
}
