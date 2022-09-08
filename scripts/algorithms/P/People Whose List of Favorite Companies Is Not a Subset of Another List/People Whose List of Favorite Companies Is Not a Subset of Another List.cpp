// Runtime: 2231 ms (Top 12.50%) | Memory: 55 MB (Top 76.79%)
/*
 * author: deytulsi18
 * problem: https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/
 * time complexity: O(n*n*m)
 * auxiliary space: O(1)
 * language: cpp
 */
class Solution {
public:
    bool isSubset(vector<string> &b, vector<string> &a)
    {
       return (includes(a.begin(), a.end(),
                  b.begin(), b.end()));
    }
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {

        int n = favoriteCompanies.size();
        vector<int> res;

        for (auto &i : favoriteCompanies)
        sort(begin(i), end(i));

        for (int i = 0; i < n; i++)
        {
            bool isValid = true;

            for (int j = 0; j < n; j++)
                if (i != j)
                    if (isSubset(favoriteCompanies[i], favoriteCompanies[j]))
                    {
                        isValid = false;
                        break;
                    }

            if (isValid)
                res.emplace_back(i);
        }

        return res;
    }
};;
