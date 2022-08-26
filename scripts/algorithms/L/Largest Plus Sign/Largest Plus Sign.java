// Runtime: 80 ms (Top 59.69%) | Memory: 74.3 MB (Top 37.60%)
class Solution {
    public int orderOfLargestPlusSign(int n, int[][] mines) {
        // Create the matrix
        int[][] arr = new int[n][n];
        for(int[] subArray : arr) {
            Arrays.fill(subArray, 1);
        }

        for(int i = 0; i < mines.length; i++) {
            arr[mines[i][0]][mines[i][1]] = 0;
        }

        // Prefix Count DP arrays
        int[][] dpTop = new int[arr.length][arr.length];
        int[][] dpLeft = new int[arr.length][arr.length];
        int[][] dpRight = new int[arr.length][arr.length];
        int[][] dpBottom = new int[arr.length][arr.length];

        // Prefix count of 1 cells on top and left directions
        for(int i = 0; i < arr.length; i++) {
            for(int j = 0; j < arr.length; j++) {
                if(i - 1 >= 0 && arr[i - 1][j] == 1) {
                    dpTop[i][j] = 1 + dpTop[i - 1][j];
                }

                if(j - 1 >= 0 && arr[i][j - 1] == 1) {
                    dpLeft[i][j] = 1 + dpLeft[i][j - 1];
                }
            }
        }

        // Prefix count of 1 cells on bottom and right directions
        for(int i = arr.length - 1; i >= 0; i--) {
            for(int j = arr.length - 1; j >= 0; j--) {
                if(i + 1 < arr.length && arr[i + 1][j] == 1) {
                    dpBottom[i][j] = 1 + dpBottom[i + 1][j];
                }

                if(j + 1 < arr.length && arr[i][j + 1] == 1) {
                    dpRight[i][j] = 1 + dpRight[i][j + 1];
                }
            }
        }

        int maxPlusSignLength = 0;
        for(int i = 0; i < arr.length; i++) {
            for(int j = 0; j < arr.length; j++) {
                if(arr[i][j] == 0) continue;

                // Minimum adjacent 1 cell count from all four directions to ensure symmetry
                int minAdjacentOnes = Math.min(Math.min(dpTop[i][j], dpBottom[i][j]), Math.min(dpLeft[i][j], dpRight[i][j]));
                maxPlusSignLength = Math.max(maxPlusSignLength, minAdjacentOnes + 1);
            }
        }

        return maxPlusSignLength;
    }
}