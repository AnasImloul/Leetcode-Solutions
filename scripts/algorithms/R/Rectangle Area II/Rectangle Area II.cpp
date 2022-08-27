// Runtime: 18 ms (Top 56.25%) | Memory: 9.3 MB (Top 68.36%)
struct Point
{
    int X;
    int delta;
};

class Solution
{
public:
    int rectangleArea(vector<vector<int>>& rectangles)
    {
        map<int, vector<Point>> lines; // y -> array of Points
        for (auto&r : rectangles)
        {
            auto x1 = r[0];
            auto y1 = r[1];
            auto x2 = r[2];
            auto y2 = r[3];

            lines[y1].push_back(Point {x1, +1});
            lines[y1].push_back(Point {x2, -1});
            lines[y2].push_back(Point {x1, -1});
            lines[y2].push_back(Point {x2, +1});
        }

        long area = 0;
        int prevy = 0;
        int length = 0;

        map<int, int> scanline; // x -> delta
        for (const auto& [y, points] : lines)
        {
            area += (y - prevy) * (long)length;

            // Update scanline for new y: add new rectanhgles,
            // remove old
            for (auto point : points)
            {
                auto xdelta = scanline.find(point.X);
                if (xdelta != end(scanline))
                {
                    xdelta->second += point.delta;
                    if (xdelta->second == 0)
                        scanline.erase(xdelta);
                }
                else
                    scanline[point.X] = point.delta;
            }

            // For current y-line calc the length of
            // intersection with rectangles
            int startX = -1;
            int rectCount = 0;
            length = 0;
            for (const auto& [x, delta] : scanline)
            {
                int oldcount = rectCount;
                rectCount += delta;
                if (oldcount == 0)
                    startX = x;
                else if (rectCount == 0)
                    length += x - startX;
            }

            if (rectCount > 0)
                length += scanline.rbegin()->first - startX;

            prevy = y;
        }

        return area % (1000000007);
    }
};