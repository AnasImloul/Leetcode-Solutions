// Runtime: 0 ms (Top 100.0%) | Memory: 6.40 MB (Top 36.84%)

class Solution {
public:
    pair<int, int> divmod(int dividend, int divisor) {
        int quotient = dividend / divisor;
        int remainder = dividend % divisor;
        return make_pair(quotient, remainder);
    }
    int numWaterBottles(int numBottles, int numExchange) {
        int result = numBottles;
        pair<int, int> div = divmod(numBottles, numExchange);
        int drunk = div.first;
        int empty = div.second;
        while(drunk) {
            result += drunk;
            div = divmod(drunk + empty, numExchange);
            drunk = div.first;
            empty = div.second;
        }
        return result;
    }
};
