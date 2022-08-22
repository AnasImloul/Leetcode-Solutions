// Runtime: 22 ms (Top 70.57%) | Memory: 10.5 MB (Top 99.25%)
class Solution
{
    string LCS(string str1, string str2, int m, int n)
    {
        int t[m+1][n+1];
        string ans = "";
        for(int i = 0;i < m+1; ++i)
        {
            for(int j = 0; j< n+1; ++j)
            {
                if(i == 0 || j == 0)
                    t[i][j] = 0;
            }
        }

        for(int i = 1; i < m+1; ++i)
        {
            for(int j = 1; j < n+1; ++j)
            {
                if(str1[i-1] == str2[j-1])
                    t[i][j] = 1 + t[i-1][j-1];
                else
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
        int i = m, j = n;
        while(i > 0 && j > 0)
        {
            if(str1[i-1] == str2[j-1])
            {
                ans.push_back(str1[i-1]);
                --i;
                --j;
            }

            else if(t[i][j-1] > t[i-1][j])
            {
                ans.push_back(str2[j-1]);
                --j;
            }

            else
            {
                ans.push_back(str1[i-1]);
                --i;
            }
        }
        while( i > 0)
        {
            ans.push_back(str1[i-1]);
            --i;
        }
        while( j > 0)
        {
            ans.push_back(str2[j-1]);
            --j;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

public:
    string shortestCommonSupersequence(string str1, string str2) {

        int m = str1.length();
        int n = str2.length();

        return LCS(str1, str2, m ,n);
    }
};