// Runtime: 8 ms (Top 48.49%) | Memory: 14.60 MB (Top 7.99%)

class Solution {
public:
    int finalValueAfterOperations(vector<string>& o,int c=0) {
           for(auto &i:o) if(i=="++X" or i=="X++") c++; else c--;
           return c;
    }
};
