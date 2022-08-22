// Runtime: 361 ms (Top 82.03%) | Memory: 22.1 MB (Top 38.96%)
/ Standard DSU Class
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

    // Directly getting parents of u and v
    // To avoid finding parent multiple times
    void unionBySize(int parU, int parV) {

        if(size[parU] < size[parV]) {
            size[parV] += size[parU];
            parent[parU] = parV;
        }
        else {
            size[parU] += size[parV];
            parent[parV] = parU;
        }
    }
};

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {

        DSU dsu(n);

        vector<bool> successful;

        for(auto& request : requests) {

            int u = request[0], v = request[1];

            int parU = dsu.findParent(u), parV = dsu.findParent(v);

            bool flag = true;

            if(parU != parV) {

                // Check if current friend requested is restricted or not.
                for(auto& restriction : restrictions) {
                    int restricted_U = restriction[0], restricted_V = restriction[1];

                    int restricted_parU = dsu.findParent(restricted_U);
                    int restricted_parV = dsu.findParent(restricted_V);

                    if((parU == restricted_parU && parV == restricted_parV) || (parU == restricted_parV && parV == restricted_parU)) {
                        flag = false;
                        break;
                    }
                }

                // Union u and v by passing parents
                // Since it is already calculated above
                if(flag) {
                    dsu.unionBySize(parU, parV);
                }
            }

            successful.push_back(flag);
        }

        return successful;
    }
};