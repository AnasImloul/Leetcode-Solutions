class DSU {
public:
    vector<int>Parent;
    vector<int>Rank;
    DSU(int n) {
        Parent.resize(n);
        Rank.resize(n, 0);
        for(int i = 0; i < n; i++) Parent[i] = i;
    }

    int Find(int x) {
        return Parent[x] = Parent[x] == x? x : Find(Parent[x]);
    }

    void Union(int a, int b) {
        a = Find(a);
        b = Find(b);
        if(Rank[a] == Rank[b]) Rank[a]++;
        if(Rank[a] > Rank[b]){
            Parent[b] = a;
        }
        else {
            Parent[a] = b;
        }
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& q) {
        int nq = q.size();
        for(int i = 0; i < nq; i++) {
            q[i].push_back(i);
        }
        sort(begin(q), end(q), [&](auto const& a, auto const& b) {
          return a[2] < b[2];
        });
        sort(begin(edgeList), end(edgeList), [&](auto const& a, auto const& b) {
          return a[2] < b[2];
        });
        vector<bool>ans(nq, 0);
        int i = 0;
        DSU dsu(n);
        for(int j = 0; j < nq; j++) {
          while(i < edgeList.size() && edgeList[i][2] < q[j][2]) {
            dsu.Union(edgeList[i][0], edgeList[i][1]);
            i++;
          }
          if(dsu.Find(q[j][0]) == dsu.Find(q[j][1])) ans[q[j][3]] = 1;
        }
        return ans;
    }
};