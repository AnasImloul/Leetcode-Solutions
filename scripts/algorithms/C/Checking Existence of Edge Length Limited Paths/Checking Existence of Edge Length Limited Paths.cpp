// Runtime: 390 ms (Top 98.27%) | Memory: 111.20 MB (Top 59.25%)

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int length, vector<vector<int>>& adjList, vector<vector<int>>& queries) {
        vector<int> parent(length);
        vector<int> rank(length);
        vector<int> weight(length);
        for (int i = 0; i < length ; i++) parent[i] = i;

        sort(adjList.begin(), adjList.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        for (vector<int>& edge : adjList) unionByRank(edge[0], edge[1], edge[2], parent, rank, weight);

        vector<bool> answer;
        for (vector<int>& query : queries)
            answer.push_back(isConnectedAndWithinLimit(query[0], query[1], query[2], parent, weight));

        return answer;
    }

    bool isConnectedAndWithinLimit(int p, int q, int limit, vector<int>& parent, vector<int>& weight) {
        return find(p, limit, parent, weight) == find(q, limit, parent, weight);
    }

    int find(int x, int limit, vector<int>& parent, vector<int>& weight) {
        while (x != parent[x]) {
            if (weight[x] >= limit) {
                break;
            }
            x = parent[x];
        }
        return x;
    }

    void unionByRank(int x, int y, int limit, vector<int>& parent, vector<int>& rank, vector<int>& weight) {
        int x_ref = find(x, INT_MAX, parent, weight);
        int y_ref = find(y, INT_MAX, parent, weight);
        if (x_ref != y_ref) {
            if (rank[x_ref] < rank[y_ref]) {
                parent[x_ref] = y_ref;
                weight[x_ref] = limit;
            } else {
                parent[y_ref] = x_ref;
                weight[y_ref] = limit;
                if (rank[x_ref] == rank[y_ref]) {
                    rank[x_ref]++;
                }
            }
        }
    }
};
