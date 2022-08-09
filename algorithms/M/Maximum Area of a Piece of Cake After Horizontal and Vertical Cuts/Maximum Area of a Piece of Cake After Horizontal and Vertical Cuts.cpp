class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int mod = 1e9 + 7;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        // cout << 1;
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        // cout << 1;
        int prev = 0;
        int vert = INT_MIN, hori = INT_MIN;
        for(int i = 0; i < verticalCuts.size(); i++)
        {
            if(vert < verticalCuts[i]-prev)
                vert = verticalCuts[i]-prev;
            prev = verticalCuts[i];
        }
        //cout << 1;
        prev = 0;
        for(int i = 0; i < horizontalCuts.size(); i++)
        {
            if(hori < horizontalCuts[i]-prev)
                hori = horizontalCuts[i]-prev;
            prev = horizontalCuts[i];
        }
        return ((long long)vert*hori) % mod;
    }
};

