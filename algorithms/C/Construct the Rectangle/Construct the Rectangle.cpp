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
