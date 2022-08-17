class Solution {
    public String[] findRelativeRanks(int[] score) {
        String[] res = new String[score.length];
        TreeMap<Integer, Integer> map = new TreeMap<>();
        for(int i = 0; i < score.length; i++)   map.put(score[i], i);
        int rank = score.length;
        for(Map.Entry<Integer, Integer> p: map.entrySet()){
            if(rank == 1)   res[p.getValue()] = "Gold Medal";
            else if(rank == 2)   res[p.getValue()] = "Silver Medal";
            else if(rank == 3)   res[p.getValue()] = "Bronze Medal";
            else    res[p.getValue()] = String.valueOf(rank);
            rank--;
        }
        return res;
    }
}
