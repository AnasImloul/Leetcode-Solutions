class Solution { 
    
    public List<Integer> findAnagrams(String s, String p) {
        int fullMatchCount = p.length();
        Map<Character, Integer> anagramMap = new HashMap<>();
        
        for (Character c : p.toCharArray())
            anagramMap.put(c, anagramMap.getOrDefault(c, 0) + 1);
        
        List<Integer> result = new ArrayList<>();
        int left = 0, right = 0, currentMatchCount = 0;
        Map<Character, Integer> currentAnagramMap = new HashMap<>();
        while (right < s.length()) {
            char c = s.charAt(right);
            if (anagramMap.get(c) == null) {
                currentAnagramMap = new HashMap<>();
                right++;
                left = right;
                currentMatchCount = 0;
                continue;
            }
            currentAnagramMap.put(c, currentAnagramMap.getOrDefault(c, 0) + 1);
            currentMatchCount++;
            
            if (currentAnagramMap.get(c) > anagramMap.get(c)) {
                char leftC = s.charAt(left);
                while (leftC != c) {
                    currentAnagramMap.put(leftC, currentAnagramMap.get(leftC) - 1);
                    left++;
                    leftC = s.charAt(left);
                    currentMatchCount--;
                }
                left++;
                currentAnagramMap.put(c, currentAnagramMap.get(c) - 1);
                currentMatchCount--;
            }
            
            if (currentMatchCount == fullMatchCount)
                result.add(left);
            
            right++;
        }
        return result;
    }
}
