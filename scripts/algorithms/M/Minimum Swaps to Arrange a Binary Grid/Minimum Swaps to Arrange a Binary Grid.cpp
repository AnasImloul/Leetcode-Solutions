// Runtime: 84 ms (Top 67.40%) | Memory: 25.8 MB (Top 15.42%)
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {

        int n = grid.size();
        vector<int> mr(n,0);
        vector<int> br(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    mr[i] = j;
            }
        }
        br = mr;
        sort(mr.begin(),mr.end());
        for(int i=0;i<n;i++)
            if(mr[i]>i)
                return -1;
        int count = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(br[i]>i){
                    swap(br[i],br[j]);
                    count++;
                }
            }
        }
        return count;
    }
};