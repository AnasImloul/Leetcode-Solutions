// Runtime: 0 ms (Top 100.00%) | Memory: 6.1 MB (Top 33.37%)
class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        int sq = sqrt(area);
        while (sq > 1)
        {
            if (area % sq == 0)
                break;
            sq--;
        }
        return {area / sq, sq};
    }
};