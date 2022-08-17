class Solution {
    public boolean makeEqual(String[] words) {
        
        HashMap<Character, Integer> map = new HashMap<>();
        
        for(String str : words){
            
            for(int i=0; i<str.length(); i++){
                char ch = str.charAt(i);
                
                map.put(ch, map.getOrDefault(ch, 0) + 1);
            }
            
        }
        
        for(Character key : map.keySet()){
            
            int freq = map.get(key);
            if(freq % words.length!=0){
                return false;
            }
        }
        
        return true;
    }
}
