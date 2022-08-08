class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        map<int, vector<string>> m;
        vector<vector<string>> res;
        for (int i = 0; i < products.size(); i++)
        {
            int j = 0;
            while (products[i][j] == searchWord[j] && j < searchWord.size())
            {
                if (m.count(j) == 0)
                {
                    vector<string> v;
                    v.push_back(products[i]);
                    m.insert(make_pair(j, v));
                }
                else
                {
                    m[j].push_back(products[i]);
                }
                j++;
            }
        }
        for (int i = 0; i < searchWord.size(); i++)
        {
            if (i < m.size())
            {
                sort(m[i].begin(), m[i].end());
                int a;
                if (3 <= m[i].size())
                {
                    a = 3;
                }
                else
                {
                    a = m[i].size();
                }
                m[i].resize(a);
                res.push_back(m[i]);
            }
            else
            {
                res.push_back({});
            }
        }
        return res;
    }
};