class Solution {
    public int[][] reconstructQueue(int[][] people) {
        List<int[]> result = new ArrayList<>(); //return value
        
        Arrays.sort(people, (a, b) -> {
            int x = Integer.compare(b[0], a[0]);
            if(x == 0) return Integer.compare(a[1], b[1]); 
            else return x; });

        for(int[] p: people)
            result.add(p[1], p);
        
        return result.toArray(new int[people.length][2]);
    }
}
