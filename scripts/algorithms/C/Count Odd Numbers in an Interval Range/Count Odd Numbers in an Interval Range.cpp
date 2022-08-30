// Runtime: 4 ms (Top 47.19%) | Memory: 5.9 MB (Top 24.93%)
class Solution {
public:
    int countOdds(int low, int high) {
        if (low%2 == 0 && high%2 == 0 ){
            return (high - low)/2;
        }
        else{
            return (high - low)/2 + 1;
        }

    }
};