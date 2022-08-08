// X of a Kind in a Deck of Cards
// Leetcode problem : https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/

class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        int[] count = new int[10000];
        for(int i : deck)
            count[i]++;
        int gcd = 0;
        for(int i : count)
            if(i != 0)
                gcd = gcd == 0 ? i : gcd(gcd, i);
        return gcd >= 2;       
    }
    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
