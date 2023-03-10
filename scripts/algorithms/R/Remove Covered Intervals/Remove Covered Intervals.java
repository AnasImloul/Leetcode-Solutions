class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        if(intervals == null || intervals.length == 0) return 0;
        Arrays.sort(intervals, (i1,i2) -> (i1[0]==i2[0]?i2[1]-i1[1]:i1[0]-i2[0]));
        int c = intervals[0][0], d = intervals[0][1];
        int ans = intervals.length;
        for(int i=1;i<intervals.length;i++){
            int a = intervals[i][0], b = intervals[i][1];
            if(c<=a && b<=d) ans--; 
            else {
                c = a;
                d = b;
            }
        }
        return ans;
    }
}