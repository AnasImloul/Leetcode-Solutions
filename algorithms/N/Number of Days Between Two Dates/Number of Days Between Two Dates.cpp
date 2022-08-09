class Solution
{
public:
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool isLeap(int y)
    {
        return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
    }
    int calc(string s)
    {
        int y = stoi(s.substr(0, 4));
        int m = stoi(s.substr(5, 2));
        int d = stoi(s.substr(8));
        for (int i = 1971; i < y; i++)
            d += isLeap(i) ? 366 : 365;
        d += accumulate(begin(days), begin(days) + m - 1, 0);
        d += (m > 2 && isLeap(y)) ? 1 : 0;
        return d;
    }
    int daysBetweenDates(string date1, string date2)
    {
        int ans = abs(calc(date2) - calc(date1));
        return ans;
    }
};
