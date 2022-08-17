class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        // support variables
        int len = text.size();
        long long res = 0, aCount = 0, bCount = 0;
        char a = pattern[0], b = pattern[1];
        // getting the frequencies
        for (char c: text)  {
            if (c == a) aCount++;
            else if (c == b) bCount++;
        }
        // edge case: a == b
        if (a == b) return aCount++ * aCount / 2;
        // adding our extra character to maximise the occurrences
        if (aCount < bCount) res += bCount;
        else bCount++;
        // computing the occurrences
        for (char c: text)  {
            // first case: spotting the first element of a sequence
            if (c == a) {
                res += bCount;
            }
            // second case: we found an ending sequence
            else if (c == b) bCount--;
            // all the rest: we do nothing
        }
        return res;
    }
};
