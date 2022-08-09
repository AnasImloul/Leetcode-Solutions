class Solution {
    public int countPalindromicSubsequence(String s) {
        
        int n = s.length();
        
        char[] chArr = s.toCharArray();
        
        int[] firstOcc = new int[26];
        int[] lastOcc = new int[26];
        
        Arrays.fill(firstOcc, -1);
        Arrays.fill(lastOcc, -1);
        
        for(int i = 0; i < n; i++){
            
            char ch = chArr[i];
            
            if(firstOcc[ch - 'a'] == -1){
                firstOcc[ch - 'a'] = i;
            }
            
            lastOcc[ch - 'a'] = i;
        }
        
        int ans = 0, count = 0;
        
        boolean[] visited;
        
		// check for each character ( start or end of palindrome )
        for(int i = 0; i < 26; i++){
            
            int si = firstOcc[i]; // si - starting index
            int ei = lastOcc[i]; // ei - ending index
            
            visited = new boolean[26];
            
            count = 0;
            
			// check for unique charcters ( middle of palindrome )
            for(int j = si + 1; j < ei; j++){
                
                if(!visited[chArr[j] - 'a']){
                    visited[chArr[j] - 'a'] = true;
                    count++;
                }
            }
            
            ans += count;
        }
        
        return ans;
    }
}
