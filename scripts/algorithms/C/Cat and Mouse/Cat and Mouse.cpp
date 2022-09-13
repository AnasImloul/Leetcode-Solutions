// Runtime: 134 ms (Top 75.00%) | Memory: 19.8 MB (Top 54.50%)
class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<vector<int>> dp[2];
        vector<vector<int>> outdegree[2];
        queue<vector<int>> q; // q of {turn, mouse position, cat position} for topological sort

        dp[0] = vector<vector<int>>(N, vector<int>(N));
        dp[1] = vector<vector<int>>(N, vector<int>(N));
        outdegree[0] = vector<vector<int>>(N, vector<int>(N));
        outdegree[1] = vector<vector<int>>(N, vector<int>(N));

        // init dp and queue
        for (int j = 0; j < N; ++j) {
            dp[0][0][j] = dp[1][0][j] = 1;
            q.push({0, 0, j});
            q.push({1, 0, j});
        }
        for (int j = 1; j < N; ++j) {
            dp[0][j][j] = dp[1][j][j] = 2;
            q.push({0, j, j});
            q.push({1, j, j});
        }
        // init outdegree
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j < N; ++j) {
                outdegree[0][i][j] = graph[i].size();
                outdegree[1][i][j] = graph[j].size();
            }
        }
        for (auto &v : graph[0]) {
            for (int i = 0; i < N; ++i) {
                outdegree[1][i][v]--;
            }
        }
        // run the topological sort from queue
        while (q.size()) {
            auto turn = q.front()[0];
            auto mouse = q.front()[1];
            auto cat = q.front()[2];
            q.pop();

            if (turn == 0 && mouse == 1 && cat == 2) {
                // the result has been inferenced
                break;
            }

            if (turn == 0) { // mouse's turn
                // v is the prev position of cat
                for (auto &v : graph[cat]) {
                    if (v == 0) {
                        continue;
                    }

                    if (dp[1][mouse][v] > 0) {
                        continue;
                    }

                    if (dp[turn][mouse][cat] == 2) {
                        // cat wants to move from v to `cat` position, and thus cat wins
                        dp[1][mouse][v] = 2;
                        q.push({1, mouse, v});
                        continue;
                    }

                    outdegree[1][mouse][v]--;
                    if (outdegree[1][mouse][v] == 0) {
                        dp[1][mouse][v] = 1;
                        q.push({1, mouse, v});
                    }
                }
            } else { // cat's turn
                // v is the prev position of mouse
                for (auto &v : graph[mouse]) {
                    if (dp[0][v][cat] > 0) {
                        continue;
                    }

                    if (dp[turn][mouse][cat] == 1) {
                        // mouse wants to move from v to `mouse` position and thus mouse wins
                        dp[0][v][cat] = 1;
                        q.push({0, v, cat});
                        continue;
                    }

                    outdegree[0][v][cat]--;
                    if (outdegree[0][v][cat] == 0) {
                        dp[0][v][cat] = 2;
                        q.push({0, v, cat});
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};