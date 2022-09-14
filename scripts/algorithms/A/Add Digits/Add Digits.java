// Runtime: 2 ms (Top 73.88%) | Memory: 41.9 MB (Top 17.90%)
class Solution {
    public int addDigits(int num) {
        if(num == 0) return 0;
        else if(num % 9 == 0) return 9;
        else return num % 9;
    }
}