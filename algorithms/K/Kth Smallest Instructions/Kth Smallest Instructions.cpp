class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int n=destination[0]+1,m=destination[1]+1;
        
        //this code is straight forward it calculate and stores no. ways to go to destination from i,j
        vector<vector<int>> ways(n,vector<int> (m));
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1||j==m-1){
                    ways[i][j]=1; continue;
                }
                ways[i][j]=ways[i][j+1]+ways[i+1][j];
            }
        }
		 
		
		// with the help of above table ans can be generated
		//suppose we are at (i, j)   we need to decide whether to go Horizontal or Vertical
	
        string ans="";
        
        int i=0,j=0;
        while(i<n-1&&j<m-1){
		    // if k is less than no of ways to go from selecting horizontal path
             if(k<=ways[i][j+1]){
                ans=ans+'H';j++; 
             }
			 // else we chose vertical for greater k
            else{
                k=k-ways[i][j+1];
                i++;
                ans=ans+'V';
            }
            
         }
         while(j++<m-1) ans=ans+'H';
         while(i++<n-1) ans=ans+'V';
        
        return ans;
        
    }
};
