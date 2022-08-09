class Solution {
    public int distributeCandies(int[] candyType) {
        Set<Integer> set = new HashSet<>();
        for (int type : candyType) set.add(type);
        return Math.min(set.size(), candyType.length / 2);
    }
}
