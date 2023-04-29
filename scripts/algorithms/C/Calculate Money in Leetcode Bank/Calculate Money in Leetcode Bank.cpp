class Solution {
public:
    int totalMoney(int n) {
        int res = 0;
        for (int i = 1, c = 1; i <= n; i++, c++) {
            res += c;
            c = i % 7 ? c : (i / 7);
        }
        return res;
    }
};