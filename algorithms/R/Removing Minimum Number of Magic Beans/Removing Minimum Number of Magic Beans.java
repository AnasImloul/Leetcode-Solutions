class Solution {
    public long minimumRemoval(int[] beans) {
        long total = 0;
        for (int num: beans) {
            total += num;
        }
        
        
        long sumSoFar = 0, output = Long.MAX_VALUE;
        Arrays.sort(beans);
        for (int i = 0; i < beans.length; ++ i) {
            long current = sumSoFar;
            while (i + 1 < beans.length && beans[i] == beans[i + 1]) {
                sumSoFar += beans[i];
                ++ i;
            }
            sumSoFar += beans[i];
            current += total - sumSoFar - (long)(beans.length - i - 1) * beans[i];
            
            output = Math.min(current, output);
        }
        
        return output;
    }
}
