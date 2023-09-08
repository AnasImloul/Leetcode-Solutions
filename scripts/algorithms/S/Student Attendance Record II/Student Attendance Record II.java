// Runtime: 343 ms (Top 29.4%) | Memory: 78.58 MB (Top 12.2%)

class Solution {
    int mod=1000000000+7;
    public int checkRecord(int n) {
        int[][][] cache=new int[n+1][2][3];
        for(int i=0; i<=n; i++){
            for(int j=0; j<2; j++){
                for(int k=0; k<3; k++)cache[i][j][k]=-1;
            }
        }
        return populate(n, 0, 1, 2, cache);
    }
    public int populate(int n, int ptr, int aCount, int lCount, int[][][] cache){
        if(ptr>=n)return 1;
        if(cache[ptr][aCount][lCount]!=-1)return cache[ptr][aCount][lCount];
        long count=0;
        // Late
        if(lCount>0){
            count=populate(n, ptr+1, aCount, lCount-1, cache)%mod;
        }
        // Present
        count=(count+populate(n, ptr+1, aCount, 2, cache))%mod;
        // Absent
        if(aCount==1)count=(count+populate(n, ptr+1, aCount-1, 2, cache))%mod;
        cache[ptr][aCount][lCount]=(int)(count%mod);
        return cache[ptr][aCount][lCount];
    }
}