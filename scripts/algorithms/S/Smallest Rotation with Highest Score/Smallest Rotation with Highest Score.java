// Runtime: 4 ms (Top 100.0%) | Memory: 61.60 MB (Top 46.55%)

class Solution {
    public int bestRotation(int[] nums) {
        final int size = nums.length;
        int[] rsc = new int[size];
        for(int i = 0; i < size - 1; i++) {
            int value = nums[i];
            int downPos = (i + 1 + size - value) % size;
            rsc[downPos]--;
        }
        int value = nums[size-1];
        if( value != 0 ) rsc[size - value]--;
        int bestk = 0;
        int bestscore = rsc[0];
        int score = rsc[0];
        for(int i = 1; i < nums.length; i++) {
            score += rsc[i] + 1;
            if( score > bestscore ) {
                bestk = i;
                bestscore = score;
            }
        }
        return bestk;
    }
}
