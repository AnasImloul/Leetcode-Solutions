// Runtime: 6 ms (Top 66.6%) | Memory: 43.77 MB (Top 64.6%)

class Solution {
    public String shortestCompletingWord(String licensePlate, String[] words) {
        //Store count of letters in LicensePlate
        int[] licensePlateCount = new int[26];
        
        //To store all words which meet the criteria
        ArrayList<String> res = new ArrayList<>();
        //To find min length word that meets the criteria
        int min = Integer.MAX_VALUE;
        
        //Add char count for each char in LicensePlate
        for(Character c:licensePlate.toCharArray()) {
            if(isChar(c)) {
                licensePlateCount[Character.toLowerCase(c) - 'a']++;
            }
        }
        
        //Add char count for each word in words
        for(String word : words) {
            int[] wordCharCount = new int[26];
            boolean flag = true;
            
            for(Character c:word.toCharArray()) {
                wordCharCount[Character.toLowerCase(c) - 'a']++;
            }
            
            //Eliminate words that don't satisfy the criteria
            for(int i = 0; i<26;i++) {
                if(licensePlateCount[i] > wordCharCount[i]) flag = false;
            }
            
            //Add words satisfying criteria to res and calculate min word length
            if(flag) {
                res.add(word);
                if(word.length() < min) min = word.length();
            }
        }
        
        //Return 1st word in array meeting all criteria
        for(int i = 0; i < res.size();i++) {
            if(res.get(i).length() == min) return res.get(i);
        }
        
        //If not found, return -1 (or whatever interviewer expects)
        return "-1";
    }
    
    private boolean isChar(Character c) {
        if((c >='a' && c <='z') ||
           (c>='A' && c<='Z')) return true;
        
        return false;
    }
}