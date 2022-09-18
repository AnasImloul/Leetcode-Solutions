// Runtime: 25 ms (Top 22.29%) | Memory: 144.4 MB (Top 28.51%)
 class Solution {
     public char[][] rotateTheBox(char[][] box) {
         int row = box.length, col = box[0].length;
         char[][] res = new char[col][row];
         // rotate first, then drop
         for (int i = 0; i < row; i++) {
             for (int j = 0; j < col; j++) {
                 res[j][i] = box[row-1-i][j];
             }
         }

        for (int i = col - 1; i >= 0; i--) {
             for (int j = 0; j < row; j++) {
                 if (res[i][j] == '#') {
                     int curRow = i;
                     while (curRow+1 < col && res[curRow+1][j] == '.') {
                         curRow++;
                     }
                     if (curRow != i) {
                         res[curRow][j] = '#';
                         res[i][j] = '.';
                     }
                 }
             }
         }
         return res;
     }
 }