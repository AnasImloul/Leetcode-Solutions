// Runtime: 23 ms (Top 55.73%) | Memory: 44.3 MB (Top 45.07%)

class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {

        HashMap<String, Integer> hm = new HashMap<>();
        String[] words = paragraph.replaceAll("[!?',;.]"," ").toLowerCase().split("\\s+");
        for(int i=0; i<words.length; i++)
        {
            if(hm.containsKey(words[i]))
                hm.replace(words[i], hm.get(words[i]), hm.get(words[i])+1);
            else
                hm.put(words[i], 1);
        }

        for(int i=0; i< banned.length; i++)
            if(hm.containsKey(banned[i]))
                 hm.remove(banned[i]);

        return Collections.max(hm.entrySet(), Map.Entry.comparingByValue()).getKey();
    }
}
