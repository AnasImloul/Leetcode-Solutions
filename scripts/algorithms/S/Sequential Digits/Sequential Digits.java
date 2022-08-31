// Runtime: 0 ms (Top 100.00%) | Memory: 41.6 MB (Top 53.25%)
class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        int lowSize = String.valueOf(low).length(), highSize = String.valueOf(high).length();
        List<Integer> output = new ArrayList<>();

        for(int size=lowSize; size<=highSize; size++) {
            int seedNumber = getSeedNumber(size);
            int increment = getIncrement(size);
            int limit = (int)Math.pow(10,size);
            // System.out.println(seedNumber+":"+increment+":"+limit);
            while(true){
                if(seedNumber>=low && seedNumber<=high)
                    output.add(seedNumber);
                if(seedNumber%10==9 || seedNumber>high) break;
                seedNumber+=increment;
            }
        }
        return output;
    }

    private int getSeedNumber(int size) {
        int seed = 1;
        for(int i=2;i<=size;i++)
            seed=10*seed + i;
        return seed;
    }

    private int getIncrement(int size) {
        int increment = 1;
        for(int i=2;i<=size;i++)
            increment=10*increment + 1;
        return increment;
    }
}