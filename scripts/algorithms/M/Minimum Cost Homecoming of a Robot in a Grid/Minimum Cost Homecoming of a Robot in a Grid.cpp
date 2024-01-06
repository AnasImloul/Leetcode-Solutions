// Runtime: 127 ms (Top 95.56%) | Memory: 150.10 MB (Top 97.22%)

class Solution {
public:
    int minCost(vector<int>& start, vector<int>& end, vector<int>& costR, vector<int>& costC) {
        int ans = 0;
        int i = start[0], j = start[1];
        int x = end[0], y = end[1];
        int changeI = i < x ? 1 : -1;
        int changeJ = j < y ? 1 : -1;

        while(i != x) {
            i += changeI;
            ans += costR[i];
        }

        while(j != y) {
            j += changeJ;
            ans += costC[j];
        }

        return ans;


    }
};
