// Runtime: 26 ms (Top 14.75%) | Memory: 49.6 MB (Top 26.03%)
class Solution {
    public int minTaps(int n, int[] ranges) {
        Integer[] idx = IntStream.range(0, ranges.length).boxed().toArray(Integer[]::new);
        Arrays.sort(idx, Comparator.comparingInt(o -> o-ranges[o]));
        int ans = 1, cur = 0, end = 0;
        for (int i = 0;i<ranges.length&&end<n;i++){
            int j = idx[i];
            if (j-ranges[j]>cur){
                cur=end;
                ans++;
            }
            if (j-ranges[j]<=cur){
                end=Math.max(end, j+ranges[j]);
            }
        }
        return end<n?-1:ans;
    }
}