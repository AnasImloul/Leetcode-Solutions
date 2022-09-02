// Runtime: 3 ms (Top 38.21%) | Memory: 6 MB (Top 42.79%)
class Solution {
public:
    int xorOperation(int n, int start) {

        int res = start;

        for(int i=1 ; i<n ; i++){
            res = res ^ (start + 2 * i);
        }

        return res;
    }
};