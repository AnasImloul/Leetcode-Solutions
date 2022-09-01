// Runtime: 467 ms (Top 5.00%) | Memory: 46 MB (Top 21.15%)
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();

        // Determining the number of columns
        int cols = n / rows;
        vector<vector<char>> mat(rows, vector<char>(cols, ' '));
        int i = 0, j = 0;
        int k = 0;

        string ans = "";

        // Filling the matrix using encodedText
        // Row wise
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                mat[i][j] = encodedText[k++];
            }
        }

        // Only the upper triangular part of the matrix will
        // contain characters of the originalText
        // so, this loop traverses that area
        for(int k = 0; k < n - (rows * (rows - 1)) / 2; k++) {
            // i, j are the two pointers for tracking rows and columns
            ans.push_back(mat[i++][j++]);

            // If any boundary is hit, then column pointer is subtracted
            // by row_pointer - 1
            // and row pointer is reset to 0
            if(i == rows || j == cols) {
                j -= (i - 1);
                i = 0;
            }
        }

        // Removing all trailing spaces
        while(ans.back() == ' ')
            ans.pop_back();

        return ans;
    }
};