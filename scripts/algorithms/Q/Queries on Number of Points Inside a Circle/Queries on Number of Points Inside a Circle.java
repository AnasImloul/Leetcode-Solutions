// Runtime: 16 ms (Top 100.00%) | Memory: 42.8 MB (Top 96.08%)

class Solution {
    public int[] countPoints(int[][] points, int[][] queries) {
        int len = queries.length;
        int[] ans = new int[len];

        for(int i=0;i<len;i++){
            int count = 0;
            int radius2 = queries[i][2] * queries[i][2];
            for(int p=0; p<points.length;p++){
                int[] point = points[p];
                if(radius2(point,queries[i]) <= radius2){
                    count += 1;
                }
            }
            ans[i] = count;
        }

        return ans;
    }

    private int radius2(int[] point, int[] center){
        int x = point[0] - center[0];
        int y = point[1] - center[1];
        return x*x + y*y;
    }
}