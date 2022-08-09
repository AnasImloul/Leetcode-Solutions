class Solution {
    public int countTriples(int n) {
        int c = 0;
        for(int i=1 ; i<=n ; i++){
            for(int j=i+1 ; j<=n ; j++){
                int sq = ( i * i) + ( j * j);
                int r = (int) Math.sqrt(sq);
                if( r*r == sq && r <= n )
                    c += 2;
            }
        }
        return c;
    }
}
