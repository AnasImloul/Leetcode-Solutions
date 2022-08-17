class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0]) return a[0] > b[0];
        return a[1] < b[1];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), cmp);

        int res = 0, mx = INT_MIN;
        for (auto p : properties) {
            if (mx > p[1]) res++;
            else mx = p[1];
        }
        return res;
    }
};
