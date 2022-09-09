// Runtime: 344 ms (Top 99.56%) | Memory: 108.2 MB (Top 83.84%)
class Solution {
public:

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int r = isWater.size();
        int c = isWater[0].size();
        queue <pair<int,int>> curr;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                //set the land cell to -1 (not visited)
                if (isWater[i][j] == 0) {
                    isWater[i][j] = -1;
                }
                //set the water cell to zero and to queue
                else {
                    isWater[i][j] = 0;
                    curr.push({i, j});
                }
            }
        }

        int hill = 0;
        while (!curr.empty()) {
            int len = curr.size();

            for (int k = 0; k < len; k++) {

                //for each cell check its 4 boundary cells
                //if it is not visited, increase its hill by 1
                pair <int, int> fnt = curr.front(); curr.pop();
                int i = fnt.first, j = fnt.second;

                //top cell
                if (i > 0 && isWater[i - 1][j] == -1) {
                    isWater[i - 1][j] = hill + 1;
                    curr.push({i-1, j});
                }
                //bottom cell
                if ((i < r - 1) && (isWater[i + 1][j] == -1)) {
                    isWater[i + 1][j] = hill + 1;
                    curr.push({i+1, j});
                }
                //left cell
                if (j > 0 && (isWater[i][j - 1] == -1)) {
                    isWater[i][j - 1] = hill + 1;
                    curr.push({i, j-1});
                }
                //right cell
                if ((j < c - 1) && (isWater[i][j + 1] == -1)) {
                    isWater[i][j + 1] = hill + 1;
                    curr.push({i, j+1});
                }
            }

            //after 1 complete round increase the height of the hill
            hill += 1;
        }

        return isWater;
    }
};