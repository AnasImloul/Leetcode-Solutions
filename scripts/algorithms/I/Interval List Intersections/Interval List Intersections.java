// Runtime: 6 ms (Top 9.49%) | Memory: 45.30 MB (Top 8.74%)

class Solution {
    public int[][] intervalIntersection(int[][] A, int[][] B) {
        List<int[]> ans = new ArrayList<>();
        int i = 0, j = 0;
        while(i < A.length && j< B.length){
            int start = Math.max(A[i][0], B[j][0]);
            int end = Math.min(A[i][1], B[j][1]);
            if(start <= end) ans.add(new int[]{start, end});
            if(A[i][1]>B[j][1]) j++;
            else i++;
        }
        
        int[][] res = new int[ans.size()][2];
        i = 0;
        for(int[] pair: ans){
            res[i++] = pair;
        }
        
        return res;
    }
}
