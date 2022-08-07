class Solution {
    public boolean checkInclusion(String s1, String s2) {
        if(s1.length() > s2.length()) {
            return false;
        }
        
        int[]s1Count = new int[26];
        int[]s2Count = new int[26];
        
        for(int i = 0; i < s1.length(); i++) {
            char c = s1.charAt(i);
            char s = s2.charAt(i);
            s1Count[c - 'a'] += 1;
            s2Count[s - 'a'] += 1;
        }
        
        int matches = 0;
        
        for(int i = 0; i < 26;i++) {
            if(s1Count[i] == s2Count[i]) {
                matches+=1;
            }
        }
        
        int left = 0;
        for(int right = s1.length(); right < s2.length();right++) {
            if(matches == 26) {
                return true;
            }
            
            int index = s2.charAt(right) - 'a';
            s2Count[index] += 1;
            if(s1Count[index] == s2Count[index]) {
                matches += 1;
            }
            else if(s1Count[index] + 1 == s2Count[index]) {
                matches -= 1;
            }
            
            index = s2.charAt(left) - 'a';
            s2Count[index] -= 1;
            if(s1Count[index] == s2Count[index]) {
                matches += 1;
            }
            else if(s1Count[index] - 1 == s2Count[index]) {
                matches -= 1;
            }
            left += 1;
        }
        
        if(matches == 26) {
            return true;
        }
        
        return false;
    }
}
