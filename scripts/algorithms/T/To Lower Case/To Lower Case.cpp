// Runtime: 3 ms (Top 44.79%) | Memory: 6.50 MB (Top 90.75%)

class Solution {
public:
    string toLowerCase(string s) {
        string res="";
        for(auto c:s) {
            if('A' <= c && c <= 'Z')
                res+=c - 'A' + 'a';
            else res+=c;
        }
        return res;
    }
};
