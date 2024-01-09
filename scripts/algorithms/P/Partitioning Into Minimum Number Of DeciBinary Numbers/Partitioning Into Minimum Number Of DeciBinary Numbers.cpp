// Runtime: 31 ms (Top 56.02%) | Memory: 13.80 MB (Top 66.76%)

class Solution {
public:
    int minPartitions(string n) {
        char best = '0';
        for (auto& c : n)
            if (c > best) best = c;
        return best - '0';
    }
};
