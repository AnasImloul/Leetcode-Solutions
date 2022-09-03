// Runtime: 1 ms (Top 81.71%) | Memory: 41.5 MB (Top 17.69%)
class Solution {
    public int minBitFlips(int start, int goal) {
        int xor =start ^ goal;
        int count=0;
        while(xor>0){
            count++;
            xor=xor & (xor-1);
        }
        return count;

    }
}