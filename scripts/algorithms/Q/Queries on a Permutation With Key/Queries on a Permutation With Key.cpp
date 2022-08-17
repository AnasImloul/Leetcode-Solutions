class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        
        vector<int> p;

        for(int i=0; i<m; i++) p.push_back(m-i);
        
        for(int i=0; i<queries.size(); i++)
        {
            auto it = find(p.begin(), p.end(), queries[i]);
            int j = it - p.begin();
            int tmp = p[j];
            p.erase(it);
            p.push_back(tmp);
            queries[i] = m-j-1;
        }
        return queries;
    }
};
