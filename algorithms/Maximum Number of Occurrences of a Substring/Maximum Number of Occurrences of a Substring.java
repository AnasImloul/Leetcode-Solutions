class Solution {
    public int maxFreq(String s, int maxLetters, int minSize, int maxSize) {
        Map<String,Integer> count = new HashMap<>();
        int ans = 0;
        int n = s.length();
        
        for(int i=0;i+minSize-1<n;i++){
            String y = s.substring(i,i+minSize);
            count.put(y,count.getOrDefault(y,0)+1);

            int unique = uniqueCharactersInString(y);
            if(unique<=maxLetters){
                ans = Math.max(ans,count.get(y));
            }
        }
        //System.out.println(count);
        return ans;
    }
    int uniqueCharactersInString(String y){
        Set<Character> hs = new HashSet<>();
        for(int j=0;j<y.length();j++) 
            hs.add(y.charAt(j));
        return hs.size();
    }
}
