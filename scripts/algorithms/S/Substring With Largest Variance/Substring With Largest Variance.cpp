// Runtime: 277 ms (Top 33.70%) | Memory: 6.9 MB (Top 80.29%)
/*
    Time: O(26*26*n)
    Space: O(1)
    Tag: Kadane's Algorithm
    Difficulty: H (Logic) | E(Implementation)
*/

class Solution {
public:
    int largestVariance(string s) {
        int res = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (i == j) continue;
                int highFreq = 0;
                int lowFreq = 0;
                bool prevHadLowFreqChar = false;
                for (char ch : s) {
                    if (ch - 'a' == i)
                        highFreq++;
                    else if (ch - 'a' == j)
                        lowFreq++;
                    if (lowFreq > 0)
                        res = max(res, highFreq - lowFreq);
                    else if (prevHadLowFreqChar)
                        res = max(res, highFreq - 1);
                    if (highFreq - lowFreq < 0) {
                        highFreq = 0;
                        lowFreq = 0;
                        prevHadLowFreqChar = true;
                    }
                }
            }
        }
        return res;
    }
};