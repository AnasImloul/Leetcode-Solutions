// Runtime: 0 ms (Top 100.00%) | Memory: 41.6 MB (Top 33.75%)
class Solution {
    public String bestHand(int[] ranks, char[] suits) {
    int max = 0;
    int card = 0;
    char ch = suits[0];
    int[] arr = new int[14];
    for(int i = 0; i < 5; i++){
        arr[ranks[i]]++;
        max = Math.max(max,arr[ranks[i]]);
        if(suits[i] == ch) card++;
    }
        if(card == 5) return "Flush";
     return max >= 3 ? "Three of a Kind":(max == 2 ? "Pair" : "High Card");
    }
}