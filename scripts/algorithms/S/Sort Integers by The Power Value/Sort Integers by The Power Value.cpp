// Runtime: 93 ms (Top 57.79%) | Memory: 12.6 MB (Top 53.41%)
class Solution {
public:
    int getPower(int num) {
        if (num == 1)
            return 0;

        int res = 0;
        if (num %2 == 0)
            res += getPower(num/2);
        else
            res += getPower(3*num + 1);
        res++;
        return res;
    }

    int getKth(int lo, int hi, int k) {
        multimap<int,int> um;
        for (int i = lo; i <= hi; i++) {
            um.insert({getPower(i), i});
        }
        int cnt = 1;
        int res = 0;
        for (auto iter = um.begin(); iter != um.end(); iter++) {
            if (cnt == k) {
                res = iter->second;
            }
            cnt++;
        }
        return res;
    }
};