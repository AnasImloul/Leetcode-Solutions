// Runtime: 5 ms (Top 87.96%) | Memory: 41.8 MB (Top 45.37%)
class Solution {
    public int[] memLeak(int memory1, int memory2) {
        int i = 1;
        while(Math.max(memory1, memory2) >= i){
            if(memory1 >= memory2)
                memory1 -= i;
            else
                memory2 -= i;
            i++;
        }
        return new int[]{i, memory1, memory2};
    }
}