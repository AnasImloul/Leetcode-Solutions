class Solution {
    public boolean isTransformable(String s, String t) {
        if (!equal(s, t)) return false;
        int[] countS = new int[10];
        int[] countT = new int[10];
        int[][] prev = new int[10][10];
        int[][] after = new int[10][10];
        
        for (int i = 0; i < s.length(); i++) {
            int s1 = s.charAt(i) - '0';
            int t1 = t.charAt(i) - '0';
            countS[s1]++;
            countT[t1]++;
            
			// This step is to calculate how many digit less than s1/t1 occur before time i
			// Store the frequency pair into 2-d array
            for (int j = 0; j < s1; j++) {
                if (countS[j] == 0) continue;
                prev[j][s1] += countS[j];

            }
            
            for (int j = 0; j < t1; j++) {
                if (countT[j] == 0) continue;    
                after[j][t1] += countT[j];
            }
            
        }
        
        for (int i = 0; i <= 8; i++) {
            for (int j = i + 1; j <= 9; j++) {
                if (prev[i][j] == 0) continue;
				// Check if any ascending pair's frequency has been reduced after modified.
                if (after[i][j] < prev[i][j]) return false;
            }
        }
        
        return true;
    }
    
	// Judge whether the two strings has the same digits
    public boolean equal(String s, String t) {
        char[] sc = s.toCharArray();
        char[] tc = t.toCharArray();
        Arrays.sort(sc);
        Arrays.sort(tc);
        
        for (int i = 0; i < s.length(); i++) {
            if (sc[i] != tc[i]) return false;
        }
        
        return true;
    }
}
