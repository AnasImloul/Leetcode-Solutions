// Runtime: 436 ms (Top 17.70%) | Memory: 66.6 MB (Top 47.85%)
// DSU Class Template
class DSU {
    vector<int> parent, size;
public:

    DSU(int n) {
        for(int i=0; i<=n; i++) {
            parent.push_back(i);
            size.push_back(1);
        }
    }

    int findParent(int num) {
        if(parent[num] == num) return num;
        return parent[num] = findParent(parent[num]);
    }

    void unionBySize(int u, int v) {
        int parU = findParent(u);
        int parV = findParent(v);

        if(parU == parV) return;

        if(size[parU] < size[parV]) {
            parent[parU] = parV;
            size[parV] += size[parU];
        }
        else {
            parent[parV] = parU;
            size[parU] += size[parV];
        }
    }
};

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {

        DSU dsu(n);

        // Make connections with its multiple
        for(int i=threshold+1; i<=n; i++) {
            int j = 1;
            while(i*j <= n) {
                dsu.unionBySize(i, i*j);
                j++;
            }
        }

        vector<bool> res;
        for(auto& query : queries) {
            int u = query[0];
            int v = query[1];

            // Check if both cities belong to same component or not
            if(dsu.findParent(u) == dsu.findParent(v)) res.push_back(true);
            else res.push_back(false);
        }

        return res;
    }
};