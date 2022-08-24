// Runtime: 4 ms (Top 98.71%) | Memory: 45.6 MB (Top 85.46%)
class Solution {
    public int removeCoveredIntervals(int[][] intervals)
    {
        int count=0;

        for(int i=0;i<intervals.length;i++)
        {
            for(int j=0;j<intervals.length;j++)
            {
                if(intervals[i][0]>=intervals[j][0] && intervals[i][1]<=intervals[j][1] && i!=j)
                {
                    count++;
                    break;
                }

            }
        }
        return intervals.length-count;
    }
}