// Runtime: 326 ms (Top 27.47%) | Memory: 102.4 MB (Top 18.31%)
class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size(), x = 0;
        // XOR of the permutation
        for(int i = 1; i<=n+1; i++) x ^= i;

        // Xoring X with all the odd positioned elements to find first number
        for(int i = 1; i<n; i+=2) x ^= encoded[i];

        vector <int> res;
        res.push_back(x);
        for(int i = 0; i<n; i++){
            x ^= encoded[i];
            res.push_back(x);
        }
        return res;
    }
};