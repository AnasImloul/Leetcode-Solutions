class Solution {
    class UnionFind 
    {
        vector<int> parent, rank;
        public:
        int count = 0;
        UnionFind(int n)
        {
            count = n;
            parent.assign(n, 0);
            rank.assign(n, 0);
            for(int i=0;i<n;i++)
            {
                parent[i] = i;
            }
        }
        int find(int p)
        {
            while(p!=parent[p])
            {
                parent[p] = parent[parent[p]];
                p = parent[p];
            }
            return p;
        }
        bool Union(int p, int q)
        {
            int rootp = find(p);
            int rootq = find(q);
            if(rootp == rootq)
                return false;
            else if(rank[rootp] < rank[rootq])
            {
                parent[rootp] = rootq;
                rank[rootq]++;
                count--;
                return true;
            }
            else
            {
                parent[rootq] = rootp;
                rank[rootp]++;
                count--;
                return true;
            }
        }
    };
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        UnionFind uf(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1])
                    uf.Union(i,j);
            }
        }

        return n - uf.count;
    }
};
