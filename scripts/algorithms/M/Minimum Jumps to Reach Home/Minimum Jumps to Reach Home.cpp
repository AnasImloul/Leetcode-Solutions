class Solution
{
public:
    typedef pair<int, bool> pi;
    int minimumJumps(vector<int> &forbidden, int a, int b, int x)
    {
        set<int> st(forbidden.begin(), forbidden.end());
        vector<vector<int>> vis(2, vector<int>(10000, 0));
        vis[0][0] = 1;
        vis[1][0] = 1;
        queue<pi> q;
        q.push({0, true});
        int ans = 0;
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                int curr = q.front().first;
                bool canJumpBackward = q.front().second;
                q.pop();
                if (curr == x)
                    return ans;
                int p1 = curr + a;
                int p2 = curr - b;
                if (p1 < 10000 && vis[0][p1] == 0 && st.find(p1) == st.end())
                {
                    q.push({p1, true});
                    vis[0][p1] = 1;
                }
                if (p2 >= 0 && vis[1][p2] == 0 && st.find(p2) == st.end() && canJumpBackward == true)
                {
                    q.push({p2, false});
                    vis[1][p2] = 1;
                }
            }
            ans++;
        }
        return -1;
    }
};