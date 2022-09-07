// Runtime: 5 ms (Top 6.49%) | Memory: 42.9 MB (Top 12.04%)
class Solution {
    public boolean findRotation(int[][] mat, int[][] target) {
        if (mat == target) return true;
        int n = mat.length;
        int[] res[] = new int[n][n];
        for (int i = 0; i < n; i++) { //clockwise 90
            for (int j = 0; j < n; j++) {
                res[i][j] = mat[n - 1 - j][i];
            }
        }

        int[] res2[] = new int[n][n];
        for (int i = 0; i < n; i++) { //clockwise 180
            for (int j = 0; j < n; j++) {
                res2[i][j] = res[n - 1 - j][i];
            }
        }

        int[] res3[] = new int[n][n];
        for (int i = 0; i < n; i++) { //clockwise 270
            for (int j = 0; j < n; j++) {
                res3[i][j] = res2[n - 1 - j][i];
            }
        }

        //compare to 90,180,270 and itself
        if(Arrays.deepEquals(target, res) || Arrays.deepEquals(target, res2) || Arrays.deepEquals(target, res3) || Arrays.deepEquals(target, mat) ){
            return true;
        }
        return false;
    }
}

// Arrays.deepEquals() use for matrix