// Runtime: 5 ms (Top 44.14%) | Memory: 40.7 MB (Top 83.77%)
class Solution {
    public int arrangeCoins(int n) {
        long s =0; long e = n;
        while (s <= e) {
         long mid = s +(e-s)/2;
            long coin = mid *( mid +1)/2;
            if(coin > n){
                 e = mid -1;
            } else if (coin < n){
                s = mid +1;
            } else return (int) mid;
        }
        return (int)e;
    }
}