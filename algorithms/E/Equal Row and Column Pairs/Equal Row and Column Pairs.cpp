class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
        // Number to store the count of equal pairs.
        int ans = 0;
        map<vector<int>, int> mp;
        // Storing each row int he map
        for (int i = 0; i < grid.size(); i++)
            mp[grid[i]]++;
        
        for (int i = 0; i < grid[0].size(); i++)
        {
            vector<int> v;
            // extracting column in a vector.
            for (int j = 0; j < grid.size(); j++)
                v.push_back(grid[j][i]);
            // Add the number of times that column appeared as a row.
            ans += mp[v];
        }
        // Return the number of count
        return ans;
    }
};
