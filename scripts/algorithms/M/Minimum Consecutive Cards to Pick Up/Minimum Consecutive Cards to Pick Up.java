// Runtime: 51 ms (Top 92.02%) | Memory: 61 MB (Top 90.10%)

class Solution
{
    public int minimumCardPickup(int[] cards)
    {
        Map<Integer,Integer> map = new HashMap<>();
        int min = Integer.MAX_VALUE;
        for(int i = 0; i < cards.length; i++)
        {
            if(map.containsKey(cards[i]))
                min = Math.min(i-map.get(cards[i])+1,min); // Check if the difference in indices is smaller than minimum
            map.put(cards[i],i); // Update the last found index of the card
        }
        return min == Integer.MAX_VALUE?-1:min; // Repetition found or not
    }
}