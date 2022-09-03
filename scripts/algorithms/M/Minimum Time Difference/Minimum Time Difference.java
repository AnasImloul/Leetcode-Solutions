// Runtime: 9 ms (Top 62.54%) | Memory: 46.9 MB (Top 41.18%)
class Solution {
    public int findMinDifference(List<String> timePoints) {
        int N = timePoints.size();
        int[] minutes = new int[N];
        for(int i = 0; i < N; i++){
            int hr = Integer.parseInt(timePoints.get(i).substring(0, 2));
            int min = Integer.parseInt(timePoints.get(i).substring(3, 5));
            minutes[i] = hr * 60 + min;
        }
        Arrays.sort(minutes);
        int res = Integer.MAX_VALUE;
        for(int i = 0; i < N - 1; i++){
            res = Math.min(res, minutes[i + 1] - minutes[i]);
        }
        int b = minutes[0];
        int a = minutes[N - 1];
        return Math.min(res, (b - a + 1440) % 1440);
    }
}