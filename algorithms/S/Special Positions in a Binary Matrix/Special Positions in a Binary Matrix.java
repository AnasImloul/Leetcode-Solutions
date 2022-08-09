class Solution {
    public int numSpecial(int[][] mat) {
      int count=0;
        for(int i=0;i<mat.length;i++){
            for(int j=0;j<mat[0].length;j++){
                if(mat[i][j]==1){
                    int flag=0;
                    for(int k=0;k<mat.length;k++){
                        if(mat[k][j]!=0 && k!=i){
                            flag=1;break;
                        }
                    }
                    if(flag==1) continue;
                    for(int k=0;k<mat[0].length;k++){
                        if(mat[i][k]!=0 && k!=j){
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0) count++;
                }
            }
        }
        return count;
    }
}