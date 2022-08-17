class Solution {
   public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        const auto n = cars.size();
        vector<double> ret(n, -1);
        vector<int> stk;
        for (int i = n; i-- != 0;) {
            while (!stk.empty() && cars[stk.back()][1] >= cars[i][1]) {
                stk.pop_back();
            }
            for (int j = stk.size(); j-- != 0;) {
                const auto c = stk[j];
                const auto t =
                    1.0 * (cars[c][0] - cars[i][0]) / (cars[i][1] - cars[c][1]);
                if (t <= ret[c] || ret[c] == -1) {
                    ret[i] = t;
                    break;
                }
            }
            stk.push_back(i);
        }
        return ret;
    }
};
