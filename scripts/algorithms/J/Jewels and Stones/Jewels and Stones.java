// Runtime: 3 ms (Top 31.57%) | Memory: 42.7 MB (Top 19.07%)
class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        HashSet<Character> hs=new HashSet<>();
        int count=0;
        for(int i=0;i<jewels.length();i++)
        {
            hs.add(jewels.charAt(i));
        }
        for(int i=0;i<stones.length();i++)
        {
            if(hs.contains(stones.charAt(i)))
                count++;
        }
        return count;
    }
}