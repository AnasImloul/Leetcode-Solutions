// Runtime: 14 ms (Top 27.1%) | Memory: 44.54 MB (Top 34.2%)

class Solution {
    public int minCharacters(String a, String b) {
        int[] aCount = new int[26];
        int aMax = 0;
        for (int i = 0; i < a.length(); i++) {
            aCount[a.charAt(i) - 'a']++;
            aMax = Math.max(aMax, aCount[a.charAt(i) - 'a']);
        }
        
        int[] bCount = new int[26];
        int bMax = 0;
        for (int i = 0; i < b.length(); i++) {
            bCount[b.charAt(i) - 'a']++;
            bMax = Math.max(bMax, bCount[b.charAt(i) - 'a']);
        }
        int condition3 = a.length() - aMax + b.length() - bMax;
        
        int globalMin = condition3;
        
        int aTillCurrent = 0;
        int bTillCurrent = 0;
        for (int i = 0; i < 25; i++) {
            aTillCurrent += aCount[i];
            bTillCurrent += bCount[i];
            globalMin = Math.min(globalMin, bTillCurrent + a.length() - aTillCurrent);
            globalMin = Math.min(globalMin, aTillCurrent + b.length() - bTillCurrent);
        }
        
        
        
        return globalMin;
    }
}