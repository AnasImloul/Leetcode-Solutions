class Solution {
    public int leastBricks(List<List<Integer>> wall) {
        HashMap<Long, Integer> map = new HashMap<Long, Integer>();
        int max = 0;
        for(List<Integer> row: wall){
            long sum = 0;
            for(int i = 0; i<row.size()-1; i++){
                sum+=row.get(i);
                map.put(sum, map.getOrDefault(sum, 0)+1);
                max = Math.max(max, map.get(sum));
            }
        }
        return wall.size()-max;
    }
}
