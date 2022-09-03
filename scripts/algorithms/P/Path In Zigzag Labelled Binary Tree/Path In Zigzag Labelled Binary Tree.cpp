// Runtime: 0 ms (Top 100.00%) | Memory: 6.2 MB (Top 69.70%)
class Solution
{
public:
    vector<int> pathInZigZagTree(int label)
    {
        vector<int> v;
        int n = 0, num = label;
        while (label)
        {
            n++;
            label = label >> 1;
        }

        int l, r, c, ans;
        for (int i = n; i >= 2; i--)
        {

            r = pow(2, i) - 1;
            l = pow(2, i - 1);
            c = r - num;
            ans = l + c;
            if ((n + i) % 2)
            {
                v.push_back(ans);
            }
            else
            {
                v.push_back(num);
            }
            num /= 2;
        }
        v.push_back(1);
        sort(v.begin(), v.end());
        return v;
    }
};