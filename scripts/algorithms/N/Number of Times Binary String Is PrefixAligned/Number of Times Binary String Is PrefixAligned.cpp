// Runtime: 81 ms (Top 15.36%) | Memory: 38.80 MB (Top 66.29%)

class Solution {
public:
    int numTimesAllBlue(vector<int> &light) {
        int rIdx = 0, cnt = 0, openCnt = 0;
        for (int i = 0; i < light.size(); i++) {
            openCnt++;
            rIdx = max(rIdx, light[i]);
            if (openCnt == rIdx) {
                cnt++;
            }
        }
        return cnt;
    }
};
