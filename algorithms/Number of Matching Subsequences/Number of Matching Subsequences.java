class Solution {
    public int numMatchingSubseq(String s, String[] words) {
        int count = 0;
        Map<String, Integer> map = new HashMap<>();
        for(String word : words){
            if(!map.containsKey(word)){
                map.put(word, 1);
            }
            else{
                map.put(word, map.get(word)+1);
            }
        }
        for(String word : map.keySet()){
            if(isSeq(word, s)){
                count += map.get(word);
            }
        }
        return count;
    }
    public boolean isSeq(String s1, String s2){
        int s1ind = 0;
        int s2ind = 0;
        int counter = 0;
        if(s1.length() > s2.length()){
            return false;
        }
        while(s1ind < s1.length() && s2ind < s2.length()){
            if(s1.charAt(s1ind) == s2.charAt(s2ind)){
                counter++;
                s1ind++;
                s2ind++;
            }
            else{
                s2ind++;
            }
        }
        return counter == s1.length();
    }
}
