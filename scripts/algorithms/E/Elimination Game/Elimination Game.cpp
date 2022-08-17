class Solution {
public:
    int lastRemaining(int n) {
        int beg = 1, d = 1, len = n;
        bool fromleft = true;

        while(len != 1 ) {
            if(fromleft || (len&1))
                beg += d;
            len >>= 1;
            d <<= 1;
            fromleft = !fromleft;
        }

        return beg;
    }
};
