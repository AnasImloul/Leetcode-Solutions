// Runtime: 167 ms (Top 87.54%) | Memory: 18 MB (Top 34.01%)
class Solution {
    vector<bool> visited;
    vector<vector<int>> pc, adj; // pc is the parent child edge in our dfs
    vector<vector<bool>> childs; // 2D array to store that i is a parent of j
    vector<int> child_xor, nums, par; // child_xor to store result of xors of a child node and par is a gloable array to track the parents of a node in dfs

    int dfs(int i) {
        int ans = nums[i];
        visited[i] = true;

        for (int p: par) childs[p][i] = true; // Defining this node as the child of all its parents

        par.push_back(i);

        for (int child: adj[i])
            if (!visited[child]) {
                pc.push_back({i, child});
                ans ^= dfs(child); // Recurcively calculating xors
            }

        par.pop_back();

        return child_xor[i] = ans;
    }
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        // Initialising gloable variables
        int n = nums.size(), ans = INT_MAX;
        visited = vector<bool>(n);
        pc = vector<vector<int>>();
        adj = vector<vector<int>>(n);
        child_xor = vector<int>(n, 0);
        childs = vector<vector<bool>>(n, vector<bool>(n, false));
        this->nums = nums;
        par = vector<int>();

        // Creating an adjacency matrix
        for (vector<int> &edge: edges) adj[edge[0]].push_back(edge[1]), adj[edge[1]].push_back(edge[0]);

        dfs(0);

        for (int i = 0; i < pc.size(); i++)
            for (int j = i + 1; j < pc.size(); j++) { // removing an edge i and j
                int a = pc[i][1], b = pc[j][1]; // node that will come below when you delete an edge i and j
                int xa = child_xor[a], xb = child_xor[b], xc = child_xor[0];

                if (childs[a][b])
                    xc ^= xa, xa ^= xb;
                else
                    xc ^= xa, xc ^= xb;

                ans = min(max(xa, max(xb, xc)) - min(xa, min(xb, xc)), ans);
            }

        return ans;
    }
};