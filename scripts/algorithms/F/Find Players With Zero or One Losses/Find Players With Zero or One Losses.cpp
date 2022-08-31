// Runtime: 954 ms (Top 69.51%) | Memory: 160.9 MB (Top 95.44%)
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> umap;
        vector<vector<int>> result(2);
        for(int i=0;i<matches.size();i++)
        {
            umap[matches[i][1]]++;
        }
        for(auto i=umap.begin();i!=umap.end();i++)
        {
            if(i->second==1)
            {
                result[1].push_back(i->first);
            }
        }
        for(int i=0;i<matches.size();i++)
        {
            if(umap[matches[i][0]]==0)
            {
                result[0].push_back(matches[i][0]);
                umap[matches[i][0]]=1;
            }
        }

        sort(result[0].begin(),result[0].end());

        sort(result[1].begin(),result[1].end());

        return result;
    }
};