class Solution
{
public:
    const string strs[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    string dayOfTheWeek(int day, int month, int year)
    {
        return strs[compute(day, month, year)];
    }
    int compute(int d, int m, int y)
    {
        int w;
        if (m == 1 || m == 2)
        {
            m += 12, y--;
        }
        w = (d + (2 * m) + (3 * (m + 1) / 5) + y + (y / 4) - (y / 100) + (y / 400) + 1) % 7;
        return w;
    }
};