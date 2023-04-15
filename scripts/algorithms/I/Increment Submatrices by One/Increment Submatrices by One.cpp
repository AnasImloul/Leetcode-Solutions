class Solution {
public:
    int size;
    void update(int a,int b,int x,int y,vector<vector<int>> &mat){
        mat[a][b] += 1;
        if(x+1<size){
            mat[x+1][b] -= 1;
        }
        if(x+1 < size && y+1 < size){
            mat[x+1][y+1] += 1;
        }
        if(y+1 < size){
            mat[a][y+1] -= 1;
        }
    }
    
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n,vector<int>(n,0));
        size = n;
        for(auto i : queries){
            update(i[0],i[1],i[2],i[3],mat);
        }
        // column prefix sum
        for(int i=0;i<size;i++){
            for(int j=1;j<size;j++){
                mat[i][j] += mat[i][j-1];
            }
        }
        // row prefix sum
        for(int i=0;i<size;i++){
            for(int j=1;j<size;j++){
                mat[j][i] += mat[j-1][i];
            }
        }
        return mat;
    }
};