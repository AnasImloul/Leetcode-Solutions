// Runtime: 7 ms (Top 97.98%) | Memory: 45.20 MB (Top 9.52%)

class Solution {
    public int maxVowels(String s, int k) {
        int n = s.length();
        int maxVowels = 0;
        int count = 0;

        int[] vowels = new int[128];
        vowels['a'] = 1;
        vowels['e'] = 1;
        vowels['i'] = 1;
        vowels['o'] = 1;
        vowels['u'] = 1;

        for (int i = 0; i < k; i++) {
            count += vowels[s.charAt(i)];
        }

        maxVowels = count;
        for (int i = k; i < n; i++) {
            count += vowels[s.charAt(i)] - vowels[s.charAt(i - k)];
            maxVowels = Math.max(maxVowels, count);
            //System.out.println(Arrays.toString(vowels));
            if (maxVowels == k) {
                return maxVowels; 
            }
        }
        return maxVowels;
    }
}

