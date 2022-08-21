// Runtime: 698 ms (Top 5.47%) | Memory: 145 MB (Top 5.47%)

class Solution {
    public int numSpecialEquivGroups(String[] words) {
        if(words.length == 0 || words.length == 1) return words.length;

        // To store group sizes
        HashMap<String, Integer> hashmap = new HashMap<>();

        // To mark the strings already part of some groups
        boolean[] isGrouped = new boolean[words.length];

        for(int index = 0; index < words.length; index++) {
            if(isGrouped[index]) continue; // Already grouped
            String word = words[index];
            for(int j = index + 1; j < words.length; j++) {
                if(isGrouped[j]) continue; // Already grouped
                String string = words[j];

                // The idea is to store count of characters on even and odd indices
                // It is done by incrementing counts of characters in both even and odd maps respectively
                // Then compare the two strings by reducing the same count in both even and odd maps
                // If both the maps are empty at last, the two strings for a group
                HashMap<Character, Integer> evens = new HashMap<>();
                HashMap<Character, Integer> odds = new HashMap<>();
                boolean isSpecialEquivalent = true;

                for(int i = 0; i < word.length(); i++) {
                    if(i % 2 == 0) {
                        evens.put(word.charAt(i), evens.getOrDefault(word.charAt(i), 0) + 1);
                    } else {
                        odds.put(word.charAt(i), odds.getOrDefault(word.charAt(i), 0) + 1);
                    }
                }

                for(int i = 0; i < string.length(); i++) {
                    char character = string.charAt(i);
                    if(i % 2 == 0) {
                        if(!evens.containsKey(character)) {
                            isSpecialEquivalent = false;
                            break;
                        }

                        evens.put(character, evens.get(character) - 1);
                        if(evens.get(character) == 0) evens.remove(character);
                    } else {
                        if(!odds.containsKey(character)) {
                            isSpecialEquivalent = false;
                            break;
                        }

                        odds.put(character, odds.get(character) - 1);
                        if(odds.get(character) == 0) odds.remove(character);
                    }
                }

                if(isSpecialEquivalent) {
                    hashmap.put(word, hashmap.getOrDefault(word, 0) + 1);
                    isGrouped[j] = true;
                }
            }

            // If no group is formed, the word alone forms a group of size 1
            if(!hashmap.containsKey(word)) hashmap.put(word, 1);
        }

        return hashmap.size();
    }
}