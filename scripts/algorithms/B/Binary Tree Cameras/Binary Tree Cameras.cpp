// Runtime: 33 ms (Top 14.78%) | Memory: 23.8 MB (Top 20.27%)
class Solution {
public:
    map<TreeNode*, int> mpr;
    int dp[1009][3];
    int minCameraCover(TreeNode* root)
    {
        int num = 0;
        adres(root, num);
        memset(dp, -1, sizeof(dp));

        int t1 = dp_fun(root, 0), t2 = dp_fun(root, 1), t3 = dp_fun(root, 2);

        return min({t1, t3});

    }

    int dp_fun(TreeNode* cur, int st)
    {
        int nd = mpr[cur];
        if(dp[nd][st] == -1)
        {
            if(cur == NULL)
            {
                if(st == 2)
                {
                    return 1e8;
                }
                else
                {
                    return 0;
                }
            }
            if(st == 2)
            {
                dp[nd][st] = 1 + min({dp_fun(cur->left, 1) + dp_fun(cur->right, 1), dp_fun(cur->left, 1) + dp_fun(cur->right, 2), dp_fun(cur->left, 2) + dp_fun(cur->right, 1), dp_fun(cur->left, 2) + dp_fun(cur->right, 2)});
            }
            else if(st == 1)
            {
                dp[nd][st] = min({dp_fun(cur->left, 0) + dp_fun(cur->right, 0), dp_fun(cur->left, 0) + dp_fun(cur->right, 2), dp_fun(cur->left, 2) + dp_fun(cur->right, 0), dp_fun(cur->left, 2) + dp_fun(cur->right, 2)});
            }
            else
            {
                dp[nd][st] = min({dp_fun(cur, 2), dp_fun(cur->left, 2) + dp_fun(cur->right, 0), dp_fun(cur->left, 0) + dp_fun(cur->right, 2), dp_fun(cur->left, 2) + dp_fun(cur->right, 2)});
            }
        }
        return dp[nd][st];
    }

    void adres(TreeNode* cur, int &cnt)
    {
        if(cur == NULL)
        {
            return;
        }
        mpr[cur] = cnt;
        cnt++;

        adres(cur->left, cnt);
        adres(cur->right, cnt);
    }
};