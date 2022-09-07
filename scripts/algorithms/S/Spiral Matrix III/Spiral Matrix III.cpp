// Runtime: 35 ms (Top 23.18%) | Memory: 12.2 MB (Top 76.14%)
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {

        vector<vector<int>> ans;
        ans.push_back({rStart, cStart}); //Pushing the starting point in answer
        int topRow = rStart-1; //Row above starting point
        int bottomRow = rStart+1; //Row below starting point
        int leftCol = cStart-1; //Col left to starting point
        int rightCol = cStart+1; //Col right to starting point

        while(topRow != -1 || bottomRow != rows || leftCol != -1 || rightCol != cols){ //Untill all rows and columns are exhausted

            if(rightCol != cols){ //Checking if this col is exhausted
                for(int i = topRow+1; i < bottomRow;i++) ans.push_back({i, rightCol}); //Running loop from one bottom of top row till bottom row in right col
                rightCol++; //Incrementing the col forward
            }
            //Similar things are done below with different cols and rows
            if(bottomRow != rows){
                for(int j = rightCol-1; j > leftCol; j--) ans.push_back({bottomRow, j});
                bottomRow++;
            }

            if(leftCol != -1){
                for(int i = bottomRow-1; i > topRow; i--) ans.push_back({i, leftCol});
                leftCol--;
            }

            if(topRow != -1){
                for(int j = leftCol+1; j < rightCol; j++) ans.push_back({topRow, j});
                topRow--;
            }
        }
        return ans;
    }
};