// Runtime: 10 ms (Top 77.23%) | Memory: 8.1 MB (Top 73.16%)
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end(), greater <int> () );
        if (satisfaction[0] <= 0) return 0;
        int ans = 0;
        int total = 0;
        for (int i = 0; i < satisfaction.size(); i++) {
            if (total + ans + satisfaction[i] > total) {
                ans = ans + satisfaction[i];
                total = total + ans;
                continue;

            }
            return total;
        }
        return total;
    }
};