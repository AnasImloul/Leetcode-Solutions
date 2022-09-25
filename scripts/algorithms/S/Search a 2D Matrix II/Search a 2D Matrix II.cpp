// Runtime: 548 ms (Top 8.60%) | Memory: 14.8 MB (Top 88.19%)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();++i)
        {
            int s=0,e=matrix[0].size()-1;
            while(s<=e)
            {
                int mid=(s+e)/2;
                if(matrix[i][mid]>target)
                {
                    e=mid-1;
                }
                else if(matrix[i][mid]<target)
                {
                    s=mid+1;
                }
                else
                {
                    return true;
                }
            }
        }
        return false;
    }
};