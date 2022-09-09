// Runtime: 25 ms (Top 11.09%) | Memory: 14.2 MB (Top 34.39%)
class Solution {
public:
    vector<vector<int>> paths = {{0,1},{0,-1},{-1,0},{1,0}};
    bool check(int i,int j , int n, int m){
        if(i>=n or i<0 or j>=m or j<0) return false;
        return true;
    }
    void solve(vector<vector<int>> &image, int sr, int sc, int color, int orig){
        int n = image.size(), m = image[0].size();
        image[sr][sc] = color;
        for(int i=0;i<4;i++){
            int new_sr = paths[i][0] + sr;
            int new_sc = paths[i][1] + sc;
            if(check(new_sr,new_sc,n,m)==true and image[new_sr][new_sc]==orig){
                solve(image, new_sr, new_sc, color,orig);
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color==image[sr][sc]) return image;
        int orig = image[sr][sc];
        solve(image, sr,sc,color, orig);
        return image;
    }
};