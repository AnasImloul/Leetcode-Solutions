// Runtime: 22 ms (Top 29.21%) | Memory: 9.9 MB (Top 41.59%)
class Solution {
public:
    /*
    There are two cases for the tree structure to be invalid.
    1) A node having two parents;
    2) A circle exists

    If there are both invalid conditions, which means there is a node which has 2 parents and there is also a circle even after we invalid edgeB.
    In this case, we have to return edgeA. only in this way can we avoid both double parents and circle for the tree.
    */

    int find(vector<int>& par, int n){
        if(par[n]==n || par[n]<0) return n;
        par[n] = find(par, par[n]);
        return par[n];
    }

    void findSpecialEdge(vector<vector<int>>& edges, vector<int>& edgeA, vector<int>& edgeB){
        int len = edges.size();
        vector<int>par(len+1, 0);
        for(vector<int> e : edges){
            int p =e[0], c=e[1];
            if(par[c]){
                edgeA = {par[c], c};
                edgeB = e;
                return;
            }else{
                par[c] = p;
            }
        }
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int len = edges.size();
        vector<int>parent(len+1, 0);
        for(int i=0; i<=len; i++) parent[i]=i;

        vector<int>edgeA={}; // 1st candidate
        vector<int>edgeB={}; // 2nd candidate
        findSpecialEdge(edges, edgeA, edgeB);

        for(vector<int> e : edges){
            int n1 = e[0];
            int n2 = e[1];
            if(edgeB.size()>0 && (edgeB[0]==n1 && edgeB[1]==n2)){ // invalidate edgeB
                continue;
            }
            int p1 = find(parent, n1);
            int p2 = find(parent, n2);
            if(p1==p2){ // circle found
                if(edgeB.size()>0){
                    return edgeA;
                }else{
                    return e;
                }
            } else{
                parent[p2] = p1;
            }
        }
        return edgeB;
    }
};