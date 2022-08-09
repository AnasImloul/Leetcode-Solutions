class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n, 'a');
        k -= n;
        
        int i = res.size() - 1;
        while (k > 0) {
            int tmp = min(k, 25);
            res[i] += tmp;
            k -= tmp;
            --i;
        }
        
        return res;
    }
};