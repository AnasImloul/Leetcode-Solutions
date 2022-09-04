// Runtime: 15 ms (Top 73.10%) | Memory: 54.7 MB (Top 46.20%)
class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        Set<Character> allowedSet = new HashSet<>();
        for(int i=0;i<allowed.length();i++){
            allowedSet.add(allowed.charAt(i));
        }

        int count = 0;
        for(String word: words){
            if(isConsistent(allowedSet, word)) count++;
        }

        return count;
    }

    boolean isConsistent(Set<Character> allowedSet, String word){
        for (int i = 0; i < word.length(); i++){
            if(!allowedSet.contains(word.charAt(i))) return false;
        }
        return true;
    }
}