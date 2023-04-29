class Solution {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int dp[2][81][8][8][8][8];
    inline bool canGo(vector<string>& grid, int i , int j) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size()
        && grid[i][j] != '#';
    }

public:
    int solve(vector<string>& grid, int catJump, int mouseJump, int turn,
     int mouseSteps, int mousePosX, int mousePosY, int catPosX, int catPosY) {
        if (mouseSteps > 80) {
            return 0;
        }
        if (grid[mousePosX][mousePosY] == 'F') {
            return 1;
        }
        if (mousePosX == catPosX && mousePosY == catPosY) {
            return 0;
        }
        if (grid[catPosX][catPosY] == 'F') {
            return 0;
        }

        int &ans = dp[turn][mouseSteps][mousePosX][mousePosY][catPosX][catPosY];
        if (ans != -1) {
            return ans;
        }

        bool mouseCanWin = 0;
        if (turn) {
            mouseCanWin = 1;
            for (int k = 0; k < 4; k++) {
                for (int jump = 0; jump <= catJump; jump++) {
                    int newCatPosX = catPosX + dx[k] * jump;
                    int newCatPosY = catPosY + dy[k] * jump;
                    if (canGo(grid, newCatPosX, newCatPosY)) {
                        mouseCanWin &= solve(grid, catJump, mouseJump, 0, mouseSteps, mousePosX, mousePosY, newCatPosX, newCatPosY);
                    if (!mouseCanWin) break;
                    } else break; // cannot jump over the wall
                }
            }
        } else {
            mouseCanWin = 0;
            for (int k = 0; k < 4; k++) {
                for (int jump = 0; jump <= mouseJump; jump++) {
                    int newMousePosX = mousePosX + dx[k] * jump;
                    int newMousePosY = mousePosY + dy[k] * jump;
                    if (canGo(grid, newMousePosX, newMousePosY)) {
                        mouseCanWin |= solve(grid, catJump, mouseJump, 1, mouseSteps + 1, newMousePosX, newMousePosY, catPosX, catPosY);
                        if (mouseCanWin) break;
                    } else break; // cannot jump over the wall               
                }
            }
        }
        return ans = mouseCanWin;
    }

    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        memset(dp, -1, sizeof(dp));
        int mousePosX = 0;
        int mousePosY = 0;
        int catPosX = 0;
        int catPosY = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 'C') {
                    catPosX = i;
                    catPosY = j;
                }
                if (grid[i][j] == 'M') {
                    mousePosX = i;
                    mousePosY = j;
                }
            }
        }
        return solve(grid, catJump, mouseJump, 0, 0, mousePosX, mousePosY, catPosX, catPosY);
    }
};