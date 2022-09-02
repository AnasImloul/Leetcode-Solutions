// Runtime: 309 ms (Top 15.91%) | Memory: 46.8 MB (Top 48.36%)
class Solution {
public:

    int dfs(int node,vector<int> &answer,vector<int> adjList[],vector<int>& quiet)
    {
        if(answer[node]==-1)
        {
            answer[node] = node;
            for(int child:adjList[node])
            {
                int cand = dfs(child,answer,adjList,quiet);
                if(quiet[cand]<quiet[answer[node]])
                    answer[node] = cand;
            }
        }

        return answer[node];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {

        int n = quiet.size();

        vector<int> adjList[n];

        for(auto x:richer)
        {
            int v = x[0];
            int u = x[1];
            adjList[u].push_back(v);
        }

        vector<int> answer(n,-1);

        for(int node =0;node<n;node++)
        {
            dfs(node,answer,adjList,quiet);
        }

        return answer;
    }
};