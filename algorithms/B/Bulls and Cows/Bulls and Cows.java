class Solution {
    public String getHint(String secret, String guess) {
        int arr[] = new int[10], bulls = 0, cows = 0;
        for (int i = 0; i < secret.length(); i++) {
            char sec = secret.charAt(i);
            char gue = guess.charAt(i); 
            if (sec == gue) bulls++;
            else {
                if (arr[sec - '0'] < 0) cows++;
                if (arr[gue - '0'] > 0) cows++;
                arr[sec - '0']++;
                arr[gue - '0']--;
            }
        }
        return new StringBuilder(String.valueOf(bulls)).append("A").append(cows).append("B").toString();
    }
}
