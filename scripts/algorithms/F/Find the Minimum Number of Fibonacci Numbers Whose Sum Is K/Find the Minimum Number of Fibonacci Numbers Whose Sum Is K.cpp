// Runtime: 3 ms (Top 73.58%) | Memory: 6.4 MB (Top 65.21%)
class Solution
{
public:
    int findMinFibonacciNumbers(int k)
    {
        vector<int> fibb;
        int a = 1;
        int b = 1;
        fibb.push_back(a);
        fibb.push_back(b);
        int next = a + b;

        while (next <= k)
        {
            fibb.push_back(next);
            a = b;
            b = next;
            next = a + b;
        }

        int res = 0;
        int j = fibb.size() - 1;
        while (j >= 0 and k > 0)
        {
            if (fibb[j] <= k)
            {
                k -= fibb[j];
                res++;
            }
            j--;
        }

        return res;
    }
};