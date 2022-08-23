// Runtime: 99 ms (Top 45.86%) | Memory: 22.5 MB (Top 13.53%)
class Solution {
public:
    const double MIN_STEP = 0.000001; // With 0.00001 not AC

    const int dx[4] = {0, 0, 1,-1};
    const int dy[4] = {1, -1, 0, 0};

    double totalDist(vector<vector<int>>& positions, double cx, double cy) {
        double dist = 0;
        for (auto p : positions) {
            dist += hypot(p[0] - cx, p[1] - cy);
        }
        return dist;
    }

    double getMinDistSum(vector<vector<int>>& positions) {
        int n = (int)positions.size();
        double cx = 0, cy = 0;
        for (auto p : positions) { cx += p[0], cy += p[1]; }
        cx /= n, cy /= n;

        pair<double, double> minDistCenter = {cx, cy};
        double minDist = totalDist(positions, cx, cy);
        //printf("cx = %.4lf, cy = %.4lf, minDist = %.4lf\n", minDistCenter.first, minDistCenter.second, minDist);

        double step = 50.0; // Because max value of x, y could be 100. So half of that
        while (step > MIN_STEP) {
            pair<double, double> tempCenter = minDistCenter;
            double tempDist = minDist;

            for (int k = 0; k < 4; k++) {
                double xx = minDistCenter.first + dx[k] * step;
                double yy = minDistCenter.second + dy[k] * step;
                double d = totalDist(positions, xx, yy);
                //printf("d = %.4lf\n", d);
                if (d < minDist) {
                    tempCenter = {xx, yy};
                    tempDist = d;
                }
            }
            if (minDistCenter == tempCenter) step /= 2;
            minDistCenter = tempCenter;
            minDist = tempDist;
        }
        //printf("minDist = %.4lf\n", minDist);
        return minDist;
    }
};