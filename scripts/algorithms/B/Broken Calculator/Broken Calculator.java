// Runtime: 0 ms (Top 100.00%) | Memory: 40.5 MB (Top 78.77%)
class Solution {
    public int brokenCalc(int startValue, int target) {
        if(startValue >= target) return startValue - target;
        if(target % 2 == 0){
            return 1 + brokenCalc(startValue, target / 2);
        }
        return 1 + brokenCalc(startValue, target + 1);
    }
}