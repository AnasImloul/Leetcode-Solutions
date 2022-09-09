// Runtime: 554 ms (Top 45.63%) | Memory: 94.8 MB (Top 47.30%)
class DetectSquares {
public:
    vector<unordered_map<int, int>> x_axis;

    DetectSquares() {
        x_axis = vector<unordered_map<int, int>>(1005);
    }

    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        x_axis[x][y]++;
    }

    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int res = 0;
        for (auto& it : x_axis[x]) { // For all points lying on x_axis with value x_coordinate = x
            int y_coord = it.first;
            int countOcc = it.second;

            if (y == y_coord) continue;
            int sideLength = abs(y_coord - y);

             // counting for p3' and p4'
            if (x + sideLength <= 1000) // x_coordinate should be within range [0, 1000]
            {
                int newX = x + sideLength;
                res += x_axis[x][y_coord] * x_axis[newX][y_coord] * x_axis[newX][y];
            }

            // counting for p3'' and p4''
            if (x - sideLength >= 0) // x_coordinate should be within range [0, 1000]
            {
                int newX = x - sideLength;
                res += x_axis[x][y_coord] * x_axis[newX][y_coord] * x_axis[newX][y];
            }
        }
        return res;
    }
};