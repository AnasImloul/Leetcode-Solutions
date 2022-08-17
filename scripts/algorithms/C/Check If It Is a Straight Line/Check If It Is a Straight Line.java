class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
        int x1=coordinates[0][0];
        int y1=coordinates[0][1];
        
        int x2=coordinates[1][0];
        int y2=coordinates[1][1];
        
        float slope;
        if(x2-x1 == 0)
        {
            slope=Integer.MAX_VALUE;
        }
        else
        {
            slope=(y2-y1)/(float)(x2-x1);
        }
        for(int i=0;i<coordinates.length;i++)
        {
            for(int j=0;j<2;j++)
            {
                if(slope==Integer.MAX_VALUE)
                {
                    if(coordinates[i][0]!=x1)
                        return false;
                }
                else
                {
                    int y=coordinates[i][1];
                    int x=coordinates[i][0];
                    if((float)(y-y1) != slope*(x-x1))
                        return false;
                }
                    
            }
        }
        return true;
    }
}
