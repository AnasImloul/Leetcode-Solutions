// Runtime: 22 ms (Top 16.67%) | Memory: 44.5 MB (Top 21.67%)
class Solution {
    public int numDifferentIntegers(String word) {
        String[] arr = word.replaceAll("[a-zA-Z]", " ").split("\\s+");
        Set<String> set = new HashSet<String>();

        for (String str : arr) {
            if (!str.isEmpty())
                set.add(String.valueOf(str.replaceAll("^0*","")));
        }

        return set.size();
    }
}