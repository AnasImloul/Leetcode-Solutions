class Solution {
public:
    
    int stoi1(string &s, int i, int j)
    {
        int num = 0;
        for (int k = i; k <= j; k++)
        {
            num = num * 10 + (s[k] - '0');
        }
        return num;
    }

    vector<int> rec(string &s, int i, int j, vector<vector<vector<int>>> &dp)
    {
        if(dp[i][j].size() > 0){
            return dp[i][j];
        }
        vector<int> ans;
        for (int k = i; k <= j; k++)
        {
            if(s[k] == '+' || s[k] == '*' || s[k] == '-'){
                vector<int> v1 = rec(s, i, k - 1, dp);
                vector<int> v2 = rec(s, k + 1, j, dp);
                for (int m = 0; m < v1.size(); m++)
                {
                    for (int n = 0; n < v2.size(); n++)
                    {
                        if (s[k] == '-')
                        {
                            ans.push_back(v1[m] - v2[n]);
                        }
                        else if (s[k] == '*')
                        {
                            ans.push_back(v1[m] * v2[n]);
                        }
                        else
                        {
                            ans.push_back(v1[m] + v2[n]);
                        }
                    }
                }
            }
        }
        if(ans.empty()){
            ans.push_back(stoi1(s,i,j));
        }
        return dp[i][j] = ans;
    }
    
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.length() + 1;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>()));
        return rec(expression, 0, expression.length()-1, dp);
    }
};
