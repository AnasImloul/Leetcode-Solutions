// Runtime: 634 ms (Top 19.62%) | Memory: 166 MB (Top 12.21%)
class Solution {
public:

    bool similar(string s1,string s2)
    {
        int n=s1.size();
        int i=0,j=n-1;
       int missMatch=0;
        for(i=0;i<n;i++)
        {
            if(s1[i]!=s2[i] and ++missMatch>2)return 0;
        }
        return 1;
    }

    void dfs(string x,unordered_map<string,vector<string>>&adj,unordered_set<string>&visited)
    {
        visited.insert(x);
        for(auto nbr:adj[x])
        {
            if(visited.find(nbr)==visited.end())
            {

                dfs(nbr,adj,visited);
            }
        }
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string,vector<string>>adj;
        for(int i=0;i<n;i++)
        {
            string s1 = strs[i];
            for(int j=i+1;j<n;j++)
            {
                string s2 = strs[j];
                if(similar(s1,s2))
                {
                    adj[s1].push_back(s2);
                    adj[s2].push_back(s1);

                }
            }

        }

        int count=0;
        unordered_set<string>visited;
        for(auto x:strs)
        {
            if(visited.find(x)==visited.end())
            {
                //cout<<x<<endl;
                dfs(x,adj,visited);
                count++;
            }
        }
        return count;//(strs[0],strs[2]);

    }
};