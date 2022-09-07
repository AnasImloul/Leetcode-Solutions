// Runtime: 1065 ms (Top 34.96%) | Memory: 112.1 MB (Top 53.20%)
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();

        vector<int> coordinates;
        vector<vector<int>> prefixXOR(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) prefixXOR[i][j] = matrix[0][0];
                else if (i == 0 && j != 0) prefixXOR[i][j] = prefixXOR[i][j-1] ^ matrix[i][j];
                else if (i != 0 && j == 0) prefixXOR[i][j] = prefixXOR[i-1][j] ^ matrix[i][j];
                else prefixXOR[i][j] = prefixXOR[i-1][j] ^ prefixXOR[i][j-1] ^ prefixXOR[i-1][j-1] ^ matrix[i][j];
            }
        }

        priority_queue<int, vector<int>, greater<int>> heap;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (heap.size() == k) {
                    if (prefixXOR[i][j] > heap.top()) {
                        heap.pop();
                        heap.push(prefixXOR[i][j]);
                    }
                }
                else heap.push(prefixXOR[i][j]);
            }
        }
        return heap.top();
    }
};