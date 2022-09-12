// Runtime: 58 ms (Top 33.33%) | Memory: 13.5 MB (Top 31.11%)
const vector<pair<int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

class Solution
{
protected:
    int n, m;

    int whichLayer(int x, int y) {
        if (x < 0 || y < 0 || x >= n || y >= m) return -1;
        int i = min(x, n - x - 1);
        int j = min(y, m - y - 1);
        return min(i, j);
    }

    void nextPos(int x, int y, int dir, int& nx, int& ny) {
        nx = x + directions[dir].first;
        ny = y + directions[dir].second;
    }

    // Go to next position in the current layer (in clockwise order)
    void advancePosition(int& x, int& y, int& d) {
        int nx, ny;
        nextPos(x, y, d, nx, ny);
        if (whichLayer(nx, ny) != whichLayer(x, y)) {
            // Change direction
            d = (d + 1) % 4;
            nextPos(x, y, d, nx, ny);
        }
        x = nx; y = ny;
    }

public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k)
    {
        // Check validity of the arguments
        if (grid.empty()) throw invalid_argument("empty grid");
        m = grid.size();
        n = grid[0].size();
        if (n == 0) throw invalid_argument("empty grid");
        if (k < 0) throw invalid_argument("negative k not accepted");

        // Trivial case
        if (k == 0) return grid;

        const int L = min(n, m) / 2;
        for (int l = 0; l < L; l++) {
            vector<int> v;

            // Flatten a layer from grid into a vector
            int j = l, i = l; // start position
            int d = 0; // direction
            do {
                v.push_back(grid[j][i]);
                advancePosition(i, j, d);
            } while (!(i == l && j == l)); // until the start position is reached

            // Unflatten rotated vector back into the grid
            j = l; i = l; // start position
            d = 0; // direction
            int off = k % v.size();
            do {
                grid[j][i] = v[off];
                off = (off + 1) % v.size();
                advancePosition(i, j, d);
            } while (!(i == l && j == l)); // until the start position is reached
        }

        return grid;
    }
};