class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        //get max for every Column
        vector<int> maxfromcol(n,INT_MIN);
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                maxfromcol[j]=max(maxfromcol[j],grid[i][j]);
            }
        }
        int cost=0;
        for(int i=0;i<n;i++){
            //find maximum in ithrow
            int mx=INT_MIN;
            for(int j=0;j<n;j++){
                mx=max(mx,grid[i][j]);   
            }
            cout<<mx<<endl;
            //update every element in ith row with min of max of ith row and max of jth col
            for(int j=0;j<n;j++){
                int temp=grid[i][j];
                grid[i][j]=min(mx,maxfromcol[j]);
                cost+=grid[i][j]-temp;
            }
        }
        return cost;
    }
};
