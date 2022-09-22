// Runtime: 755 ms (Top 45.61%) | Memory: 71.2 MB (Top 85.38%)
class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
    int n;
public:
    DisjointSet(int size) {
        n = size;
        parent.resize(size, 0);
        rank.resize(size, 0);
        for (int i = 0; i < size; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool merge(int x, int y) {
        int gX = find(x);
        int gY = find(y);
        if (gX == gY) return false;
        if (rank[gX] > rank[gY]) parent[gY] = gX;
        else if (rank[gX] < rank[gY]) parent[gX] = gY;
        else {
            parent[gY] = gX;
            rank[gX]++;
        }
        return true;
    }
    void reset() {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
};
class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> answer(m, vector<int>(n, 1));

        // mp:(sorted) value to positions
        map<int, vector<pair<int, int>>> mp;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mp[matrix[i][j]].push_back(make_pair(i, j));
            }
        }

        vector<int> rowMax(m, 0);
        vector<int> colMax(n, 0);
        DisjointSet* disjointSet = new DisjointSet(m + n);
        vector<vector<pair<int, int>>> group2positions(m + n);
        for (auto& element : mp) {
            disjointSet->reset();
            group2positions.clear();
            group2positions.resize(m + n);

            // grouping positions with the same value by col and row
            for (auto& [x, y] : element.second) {
                disjointSet->merge(x, m + y);
            }
            // allocating the grouping results
            for (auto& [x, y] : element.second) {
                group2positions[disjointSet->find(x)].push_back(make_pair(x, y));
            }

            // for each group, assign the ranking
            for (auto& group : group2positions) {
                int rank = 1;
                // rank should be the max among members in group
                for (auto& [x, y] : group) {
                    rank = max(rank, max(rowMax[x], colMax[y]) + 1);
                }
                // update the answer and max rank in row and col
                for (auto& [x, y] : group) {
                    answer[x][y] = rank;
                    rowMax[x] = rank;
                    colMax[y] = rank;
                }
            }
        }
        return answer;
    }
};