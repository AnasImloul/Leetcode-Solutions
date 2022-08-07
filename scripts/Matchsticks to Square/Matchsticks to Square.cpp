class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int goal = 0, totalSum = 0;
        for (int i : matchsticks) {
            totalSum += i;
        }
        goal = totalSum / 4;
        sort(matchsticks.begin(), matchsticks.end(), [](auto left, auto right) {
            return left > right;
        });
        int b = 0;
        if (totalSum % 4) {
            return false;
        }
        return backtrack(0, b, 0, goal, 4, matchsticks);
    }
    
    bool backtrack(int start, int &b, int sum, int &goal, int groups, vector<int>& matchsticks) {
        if (sum == goal) {
            //set sum to 0, groups--
            return backtrack(0, b, 0, goal, groups-1, matchsticks);
        }
        if (groups == 1) {
            return true;
        }
        for (int i = start; i < matchsticks.size(); i++) {
            if ((i > 0) && (!(b & (1 << (i - 1)))) && (matchsticks[i] == matchsticks[i-1])) {
                continue;
            }
            //if element not used and element value doesnt go over group sum
            if (((b & (1 << i)) == 0) && (sum + matchsticks[i] <= goal)) {
                //set element to used, recursion
                b ^= (1 << i); 
                if (backtrack(i + 1, b, sum + matchsticks[i], goal, groups, matchsticks)) {
                    return true;
                }
                //if here, received a false, set element to unused again
                b ^= (1 << i);
            }
        }
        return false;
    }
};
