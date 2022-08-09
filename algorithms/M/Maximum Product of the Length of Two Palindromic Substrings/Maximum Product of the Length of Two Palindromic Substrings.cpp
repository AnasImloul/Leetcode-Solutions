class Solution
{
public:
    long long maxProduct(string s)
    {

        int n = s.size();
        vector<int> d1 = vector<int>(s.size(), 0);
        for (int i = 0, l = 0, r = -1; i < n; i++)
        {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
            {
                k++;
            }
            d1[i] = k--;
            if (i + k > r)
            {
                l = i - k;
                r = i + k;
            }
        }

        vector<int> maxL = vector<int>(s.size(), 1);
        auto lQueue = set<pair<int, int>>();
        for (int i = 0; i < s.size(); i++)
        {
            if (i > 0)
                maxL[i] = max(maxL[i], maxL[i - 1]);

            lQueue.insert({i, d1[i]});

            while (lQueue.begin()->first + lQueue.begin()->second - 1 < i)
            {
                lQueue.erase(lQueue.begin());
            }

            maxL[i] = max(maxL[i], ((i - lQueue.begin()->first) * 2) + 1);
        }

        vector<int> maxR = vector<int>(s.size(), 1);
        auto rQueue = priority_queue<pair<int, int>>();

        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (i < s.size() - 1)
                maxR[i] = max(maxR[i], maxR[i + 1]);

            rQueue.push({i, d1[i]});

            while (rQueue.top().first - (rQueue.top().second - 1) > i)
            {
                rQueue.pop();
            }

            maxR[i] = max(maxR[i], ((rQueue.top().first - i) * 2) + 1);
        }

        long long res = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            res = max(res, (long long) maxL[i] * (long long)maxR[i + 1]);
        }
        return res;
    }
};
