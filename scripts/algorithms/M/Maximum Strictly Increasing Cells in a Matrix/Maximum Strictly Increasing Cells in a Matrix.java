// Runtime: 180 ms (Top 90.3%) | Memory: 71.17 MB (Top 94.3%)

class Solution {
    public int maxIncreasingCells(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int[] rows = new int[m], cols = new int[n];
        int[] rowMaxVals = new int[m], colMaxVals = new int[n];
        
        int[] rowSubMaxVals = new int[m], colSubMaxVals = new int[n];
        for(int i=0;i<m;i++) {
            rows[i] = Integer.MIN_VALUE;
        }
        for(int i=0;i<n;i++) {
            cols[i] = Integer.MIN_VALUE;
        }
        PriorityQueue<int[]> queue = new PriorityQueue<>((int[] a, int[] b) -> {
            return a[0] - b[0];
        });
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                queue.add(new int[]{mat[i][j], i, j});
            }
        }
        int res = 0;
        while(!queue.isEmpty()) {
            int[] arr = queue.remove();
            int val = arr[0], row = arr[1], col = arr[2];
            int cur = 1;
            if(val == rows[row]) {
                cur = Math.max(rowSubMaxVals[row] + 1, cur);
            } else {
                cur = Math.max(rowMaxVals[row] + 1, cur);
            }
            if(val == cols[col]) {
                cur = Math.max(colSubMaxVals[col] + 1, cur);
            } else {
                cur = Math.max(colMaxVals[col] + 1, cur);
            }
            

            if(val > rows[row]) {
                rowSubMaxVals[row] = rowMaxVals[row];
                rows[row] = val;
            }
            if(val > cols[col]) {
                colSubMaxVals[col] = colMaxVals[col];
                cols[col] = val;
            }
            rowMaxVals[row] = Math.max(rowMaxVals[row], cur);
            colMaxVals[col] = Math.max(colMaxVals[col], cur);
            
            res = Math.max(res, cur);
        }
        
        return res;
    }
}