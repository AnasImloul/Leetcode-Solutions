// Runtime: 52 ms (Top 93.64%) | Memory: 30.70 MB (Top 71.83%)

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0)
                    q.push({i,j});
                else
                    mat[i][j]=-1;
            }
        }
        int length=0;
        int dirx[]={1,-1,0,0};
        int diry[]={0,0,1,-1};
        while(!q.empty()){
            int size=q.size();
            length++;
           while(size--){
               auto f=q.front();
               q.pop();
               int s=f.first;
               int end=f.second;
               for(int i=0;i<4;i++){
                   int r=s+dirx[i];
                   int c=end+diry[i];
                   if(r<0 || c<0 || r==mat.size() || c==mat[0].size() || mat[r][c]!=-1)
                      continue;
                   mat[r][c]=length;
                   q.push({r,c});
               }
           }
        }
        return mat;
    }
};
