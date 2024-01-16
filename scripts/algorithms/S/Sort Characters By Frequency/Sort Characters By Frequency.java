// Runtime: 12 ms (Top 83.68%) | Memory: 45.80 MB (Top 20.05%)

class Solution {
    public String frequencySort(String s) {
        int len = s.length();
        HashMap<Integer,HashSet<Character>> map = new HashMap();       
        HashMap<Character,Integer> freqMap = new HashMap();
        
        for(int idx = 0;idx<len;idx++){
            char ch = s.charAt(idx);
            freqMap.put(ch,freqMap.getOrDefault(ch,0)+1);
        }
        
        int maxFreq = 0 , minFreq = s.length();
        
        for(char ch : freqMap.keySet()){
            HashSet<Character> set = map.getOrDefault(freqMap.get(ch),new HashSet());
            set.add(ch);
            map.put(freqMap.get(ch),set);
            maxFreq = Math.max(maxFreq , freqMap.get(ch));
            minFreq = Math.min(minFreq,freqMap.get(ch));
        }
        
        StringBuilder ansStr = new StringBuilder();
        
        for(int freq = maxFreq;freq>=minFreq;freq--){
            if(map.containsKey(freq)){
                HashSet<Character> set = map.get(freq);
                for(char ch : set){
                    int temp = freq;
                    while(temp>0){
                        ansStr.append(ch);
                        temp--;
                    }
                }
            }
        }
        
        return ansStr.toString();
    }
}
