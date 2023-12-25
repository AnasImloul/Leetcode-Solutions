// Runtime: 28 ms (Top 16.33%) | Memory: 18.00 MB (Top 6.11%)

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end()); // sort the children's greed factors in non-decreasing order
        sort(s.begin(), s.end()); // sort the cookie sizes in non-decreasing order
        int contentChildren = 0;
        int i = 0; // pointer to the current child's greed factor
        int j = 0; // pointer to the current cookie size
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) { // if the current cookie can satisfy the current child's greed factor
                contentChildren++;
                i++;
            }
            j++;
        }
        return contentChildren;
    }
};
