class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        int ver[n][m]; // to store lenght of continuous 1's vertically
        int hor[n][m]; // to store lenght of continuous 1's horizontally
		
		// fill vertical table
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                if(g[i][j]==1){
                    if(i==n-1) ver[i][j]=1;
                    else ver[i][j]=ver[i+1][j]+1;
                }
                else ver[i][j]=0;
            }
        }
        
		// fill horizontal table
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(g[i][j]==1){
                    if(j==m-1) hor[i][j]=1;
                    else hor[i][j]=hor[i][j+1]+1;
                }
                else hor[i][j]=0;
            }
        }
        
		// Iterate through the all i and j and find best solution
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!g[i][j]) continue;
                int temp=1;
                int k=min(hor[i][j],ver[i][j]);
                for(int p=1;p<k;p++){
                    int mn = min(hor[i+p][j],ver[i][j+p]);
                    if(mn>=p+1) temp=p+1;
                }
                ans=max(ans,temp);
            }
        }
        ans*=ans;
        return ans;
        
    }
};