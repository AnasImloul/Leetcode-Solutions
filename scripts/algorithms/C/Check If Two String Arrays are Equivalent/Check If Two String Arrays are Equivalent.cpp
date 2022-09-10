// Runtime: 18 ms (Top 5.29%) | Memory: 11.7 MB (Top 29.17%)
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a,b;
        for(auto x:word1)
            a += x;
        for(auto x:word2)
            b += x;

        if(a.compare(b)==0)
            return 1;

        return 0;
    }
};