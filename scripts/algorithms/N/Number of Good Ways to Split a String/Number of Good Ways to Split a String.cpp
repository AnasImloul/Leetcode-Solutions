// Runtime: 24 ms (Top 88.67%) | Memory: 17.6 MB (Top 8.95%)
class Solution {
public:
    int numSplits(string s) {
        int dist = 0;
        vector<int> v1;
        vector<int> v2;
        unordered_set<char> se;
        unordered_set<char> b;

        for(int i=0; i<s.size(); i++)
        {
            if(se.find(s[i]) == se.end())
            {
                se.insert(s[i]);
                dist++;
            }
            v1.push_back(dist);
        }

        dist = 0;

        for(int i=s.size()-1; i>=0; i--)
        {
            if(b.find(s[i]) == b.end())
            {
                b.insert(s[i]);
                dist++;
            }
            v2.push_back(dist);
        }

        dist = 0;

        for(int i=0; i<v2.size()-1; i++)
        {
            if(v1[i] == v2[s.size()-i-2]) dist++;
        }

        return dist;
    }
};