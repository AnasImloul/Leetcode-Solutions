// |-------|
//   |--|

// |-------|
//.   |-------|

// |-------|
//.           |-------|

class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a,b) -> a[0] - b[0]);
        
        int start = intervals[0][0];
        int end = intervals[0][1];
        int res = 0;
        
        for (int i = 1; i < intervals.length; i++){
            int[] interval = intervals[i];
            
            if(interval[0] >= start && interval[0] < end){
                res++;
                if (interval[1] >= end)
                    continue;
            }
            start = interval[0];
            end = interval[1];
    }
        
        return res;
    }
}
