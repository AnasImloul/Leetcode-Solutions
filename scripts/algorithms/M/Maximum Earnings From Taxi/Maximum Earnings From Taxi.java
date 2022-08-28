// Runtime: 222 ms (Top 14.25%) | Memory: 127.5 MB (Top 23.46%)
class Solution {
    public long maxTaxiEarnings(int n, int[][] rides) {
        TreeMap<Integer,Long> maps = new TreeMap<Integer,Long>();
        Arrays.sort(rides,(a,b) -> a[1] - b[1]);
        maps.put(0,0L);
        for(int i = 0; i < rides.length; i++){
            Map.Entry<Integer,Long> e = maps.floorEntry(rides[i][0]);
            long p = 0L;
            if(maps.containsKey(rides[i][1]))
                 p = maps.get(rides[i][1]);
            long q = e.getValue() + (rides[i][1] - rides[i][0] + rides[i][2]);
            if(q > p && maps.lastEntry().getValue() < q){
                 maps.put(rides[i][1],q);
            }
            maps.put(0,0L);
        }
        return maps.lastEntry().getValue();
    }
}