class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        int count = 1;
        Set<String> words = new HashSet<>(wordList);
        Queue<String> q = new LinkedList<String>();
        q.add(beginWord);
        
        while(!q.isEmpty()) {
            int size = q.size();
            
            while(size-- > 0) {
                String word = q.poll();
                char[] chList = word.toCharArray();
                
                for(int i=0; i<word.length(); i++) {
                    char tmp = chList[i];
                    
                    for(char c='a'; c<='z'; c++) {
                        chList[i] = c;
                        String newWord = new String(chList);
                        
                        if(words.contains(newWord)) {
                            if(newWord.equals(endWord)) {
                                return count + 1;
                            }
                            q.add(newWord);
                            words.remove(newWord);
                        }
                    }
                    
                    chList[i] = tmp;
                }
            }
            
            count++;
        }
        
        return 0;
    }
}
