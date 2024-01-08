// Runtime: 26 ms (Top 90.8%) | Memory: 26.10 MB (Top 93.66%)

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.size() == 0)
            return 0;
        int res = 0;
        for(int i=0; i<timeSeries.size()-1; i++) {
            if (timeSeries[i+1] - timeSeries[i] < duration)
                res += timeSeries[i+1] - timeSeries[i];
            else
                res += duration;
        }
        return res+duration;
    }
};
