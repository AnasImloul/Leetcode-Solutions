// Runtime: 867 ms (Top 5.20%) | Memory: 119.6 MB (Top 40.27%)
class TreeAncestor {
public:
    //go up by only powers of two
    vector<vector<int>> lift ;
    TreeAncestor(int n, vector<int>& parent) {
        lift.resize(n,vector<int>(21,-1)) ;
        //every node's first ancestor is parent itself
        for(int i = 0 ; i < n ; ++i ) lift[i][0] = parent[i] ;

        for(int i = 0 ; i < n ; ++i ){
            for(int j = 1 ; j <= 20 ; ++j ){
                if(lift[i][j-1] == -1) continue ;
                lift[i][j] = lift[lift[i][j-1]][j-1] ;
            }
        }
    }

    int getKthAncestor(int node, int k) {

        for(int i = 0 ; i <= 20 ; ++i ){
            if(k & (1 << i)){
                node = lift[node][i] ;
                if(node == -1) break;
            }
        }
        return node ;
    }
};