class Solution {
    public int wordCount(String[] startWords, String[] targetWords) {
        int n = startWords.length;
        int count = 0;
        Set<String> set = new HashSet<>();
        
        //1. store lexicographically sorted letters of startword in set
        for(String start: startWords){
            char[] sAr = start.toCharArray();
            Arrays.sort(sAr);
            set.add(new String(sAr));
        }
        int m = targetWords.length;
        boolean ans = false;
        for(int i = 0; i < m; i++){
            //2. sort lexicographically letters of targetword and store in new string s
            char[] tAr = targetWords[i].toCharArray();
            Arrays.sort(tAr);
            int k = tAr.length;
            String s = String.valueOf(tAr);
            
            ans = false;
            for(int j = 0; j < k; j++){
                //3. make a new string by omitting one letter from word and check if it is present in set than increase count value
                String str = s.substring(0,j) + s.substring(j+1);
                if(set.contains(str)){
                    count++;
                    break;
                }
            }
        }
        return count;    
    }
    
}
