// Runtime: 68 ms (Top 73.46%) | Memory: 43.2 MB (Top 88.65%)
class Solution {
    public List<Integer> findSubstring(String s, String[] words) {

        HashMap<String, Integer> input = new HashMap<>();
        int ID = 1;
        HashMap<Integer, Integer> count = new HashMap<>();
        for(String word: words) {
            if(!input.containsKey(word))
                input.put(word, ID++);
            int id = input.get(word);
            count.put(id,count.getOrDefault(id,0)+1);

        }
        int len = s.length();
        int wordLen = words[0].length();
        int numWords = words.length;
        int windowLen = wordLen*numWords;
        int lastIndex = s.length()-windowLen;

        int curWordId[] = new int[len];
        String cur = " "+s.substring(0,wordLen-1);

        //Change to int array
        for(int i = 0; i< (len-wordLen+1); i++) {
            cur = cur.substring(1, cur.length())+s.charAt(i+wordLen-1);
            if(input.containsKey(cur)){
                curWordId[i] = input.get(cur);
            } else {
                curWordId[i] = -1;
            }
        }
        List<Integer> res = new ArrayList<>();

        //compare using int make it faster 30 times in each comparison
        for(int i = 0; i<= lastIndex; i++) {

            HashMap<Integer, Integer> winMap = new HashMap<>();
            for(int j = 0; j < windowLen && curWordId[i] != -1; j+=wordLen) {

                int candidate = curWordId[j+i];

                if(!count.containsKey(candidate))
                    break;
                else{
                    winMap.put(candidate, winMap.getOrDefault(candidate, 0)+1);
                }
                if(winMap.get(candidate) > count.get(candidate))
                    break;

                if(j == (windowLen - wordLen) && winMap.size() == count.size()){
                    res.add(i);

                }

            }
        }

        return res;
    }
}