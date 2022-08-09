class Solution {
    public double knightProbability(int n, int k, int row, int column) {
        double [][]curr=new double[n][n];
        double [][]next=new double[n][n];
        
        curr[row][column]=1;
        
        int [][]dir={{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
        for(int p=1;p<=k;p++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(curr[i][j]!=0){
                        
                        for(int d=0;d<8;d++){
                            int ni=i+dir[d][0];
                            int nj=j+dir[d][1];
                            
                            if(ni<0 || nj<0 || ni>=n || nj>=n){
                                continue;
                            }
                            
                            next[ni][nj]+=curr[i][j]/8.0;
                        }
                    }
                }
            }
            
            curr=next;
            next=new double[n][n];
        }
        
        double sum=0.0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum+=curr[i][j];
            }
        }
        
        return sum;
    }
}
