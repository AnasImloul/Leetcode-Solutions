// Runtime: 20 ms (Top 16.65%) | Memory: 47.4 MB (Top 24.65%)
class Solution {
     Map<String,Boolean>map= new HashMap<>();
    public boolean wordBreak(String s, List<String> wordDict) {

       if(wordDict.contains(s)){
           return true;
       }
        if(map.containsKey(s)){
           return map.get(s);
        }
        for(int i=0;i<s.length();++i){
            String left=s.substring(0,i);
            if(wordDict.contains(left) && wordBreak(s.substring(i),wordDict)){
                map.put(s,true);
                return true;
            }
        }
        map.put(s,false);
        return false;
    }
}