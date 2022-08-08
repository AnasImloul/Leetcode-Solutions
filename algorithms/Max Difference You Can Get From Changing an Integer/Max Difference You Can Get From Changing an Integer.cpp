class Solution {
public:
    int power10(int n)
    {
        int total=1;
        for(int i=0;i<n;i++)
        {
            total*=10;
        }
        return total;
    }
 
    int maxDiff(int num) {
    vector<int> v;
    vector<int> w;
    int n = num;
    while (n > 0)
    {
        v.push_back(n % 10);
        w.push_back(n % 10);
        n /= 10;
    }
        
    //Finding maximum number
    int d = v.size();
    int j = d - 1;
    for (int i = d - 1; i >= 0; i--)
    {
        if (v[i] != 9)
        {
            j = i;
            break;
        }
    }
    

    for (int i = 0; i <= j; i++)
    {
        if (v[i] == v[j])
        {
            v[i] = 9;
        }
    }
    long long int res = 0;
    for (int i = d - 1; i >= 0; i--)
    {
        res += (v[i] * power10(i));
    }

    //Finding minimum number   
    int t = w.size();
    if (w[t - 1] == 1)
    {
        int l = -1;
        for (int i = t - 2; i >= 0; i--)
        {
            if (w[i] != 0 && w[i]!=1)
            {
                l = i;
                break;
            }
        }
        for (int i = 0; i <= l; i++)
        {
            if (w[i] == w[l])
            {
                w[i] = 0;
            }
        }
    }
    else
    {
        for (int i = 0; i < t; i++)
        {
            if (w[i] == w[t - 1])
            {
                w[i] = 1;
            }
        }
    }
    long long int res2 = 0;
    for (int i = t - 1; i >= 0; i--)
    {
        res2 += (power10(i) * w[i]);
    }
    return res-res2;
    }
};
