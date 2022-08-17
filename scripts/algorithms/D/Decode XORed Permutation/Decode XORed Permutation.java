class Solution {
    public int[] decode(int[] encoded) {
        int n = encoded.length+1, all = 0;
        for(int i = 1; i <= n; ++i){//a^b^c^d^e^f^g^h^i
            all ^= i;
        }
        int x = 0;
        for(int v : encoded){//a^b  b^c  c^d  d^e e^f f^g g^h h^i = a^i
            x ^= v;
        }
        int mid = all^x; //a^b^c^d^e^f^g^h^i ^ a^i = b^c^d^e^f^g^h
        for(int i = 1, j = encoded.length-2; i < j;i += 2, j -= 2){
        //(b^c^d^e^f^g^h) ^ (b^c ^ g^h ^ d^e ^ e^f) = e
            mid ^= encoded[i]^encoded[j];
        }
        int[] ans = new int[n];
        ans[n/2] = mid;
        //a    b    c    d   e   f   g   h   i
        //a^b  b^c  c^d  d^e e^f f^g g^h h^i
        for(int i = n/2+1; i < n; ++i){
            ans[i] = encoded[i-1]^ans[i-1];
        }
        for(int i = n/2-1; i >= 0; --i){
            ans[i] = encoded[i]^ans[i+1];
        }
        return ans;
    }
}
