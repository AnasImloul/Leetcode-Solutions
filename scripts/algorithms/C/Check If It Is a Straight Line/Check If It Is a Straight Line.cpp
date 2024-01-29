// Runtime: 4 ms (Top 82.49%) | Memory: 13.10 MB (Top 6.08%)

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int dx = (coordinates[1][1] - coordinates[0][1]);
        int dy = (coordinates[1][0] - coordinates[0][0]);
        for(int i=2; i<coordinates.size(); i++)
        {
            if(dx*(coordinates[i][0] - coordinates[1][0]) != dy*(coordinates[i][1] - coordinates[1][1]))
                return false;
        }
        return true;
    }
};

