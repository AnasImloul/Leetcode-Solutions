// Runtime: 8 ms (Top 77.31%) | Memory: 8.1 MB (Top 16.67%)
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> D, R;
        int len = senate.size();
        for (int i = 0; i < len; i++) {
            if (senate[i] == 'D') {
                D.push(i);
            }
            else {
                R.push(i);
            }
        }

        while (!D.empty() && !R.empty()) {
            int dIdx = D.front();
            D.pop();

            int rIdx = R.front();
            R.pop();

            if (dIdx < rIdx) {
                D.push(dIdx + len);
            }
            else {
                R.push(rIdx + len);
            }
        }

        return D.empty() ? "Radiant" : "Dire";
    }
};