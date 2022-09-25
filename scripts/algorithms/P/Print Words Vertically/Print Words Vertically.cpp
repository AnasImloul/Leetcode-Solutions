// Runtime: 0 ms (Top 100.00%) | Memory: 6.4 MB (Top 78.82%)
class Solution {
public:
    vector<string> printVertically(string s) {

        int row = 0, col = 0;

        stringstream sso(s);
        string buffer;

        while (sso >> buffer)
        {
            row++;
            col = max((int)buffer.size(),col);
        }

        vector<vector<char>> matrix(row, vector<char>(col,' '));

        sso = stringstream(s);

        int i = 0;
        while (sso >> buffer)
        {
            for (int j = 0; j < buffer.size(); j++)
                matrix[i][j] = buffer[j];
            i++;
        }

        vector<string> res;
        for (int j = 0; j < col; j++)
        {
            string item;
            for (int i = 0; i < row; i++)
                item.push_back(matrix[i][j]);

            for (int i = item.size()-1; i >= 0; i--)
            {
                if (item[i] != ' ')
                {
                    item.erase(item.begin()+i+1,item.end());
                    break;
                }
            }
            res.push_back(item);
        }

        return res;
    }
};