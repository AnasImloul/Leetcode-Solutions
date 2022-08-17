import java.util.*;
class Solution {
    public int minimumEffort(int[][] tasks)
    {
        Arrays.sort(tasks, new Comparator<int[]>(){
            @Override
            public int compare(int[] a, int[] b)
            {
                return (b[1]-b[0])-(a[1]-a[0]);
            }
        });
        int sum=0, max=0;
        for(int i=0;i<tasks.length;i++)
        {
            max=Math.max(max, sum+tasks[i][1]);
            sum+=tasks[i][0];
        }
        
        return max;
        
    }
}```