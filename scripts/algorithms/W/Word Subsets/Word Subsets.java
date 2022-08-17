class Solution {
    public List<String> wordSubsets(String[] words1, String[] words2) {
        List<String> answer = new ArrayList<>();
        int[] countB = new int[26];
        for(String word2: words2) {
            int[] temp = counter(word2);
            for(int i=0;i<26;++i) {
                countB[i] = Math.max(countB[i], temp[i]);
            }
        }
        for(String word1: words1) {
            if(isUniversal(counter(word1), countB)) {
                answer.add(word1);
            }
        }
        return answer;
    }
    
    private int[] counter(String s) {
        int[] count = new int[26];
        for(char c : s.toCharArray()) {
            ++count[c - 'a'];
        }
        return count;
    }
    
    private boolean isUniversal(int[] countA, int[] countB) {
        for(int i=0;i<26;++i) {
            if(countA[i] < countB[i]){
                return false;
            }
        }
        return true;
    }
}
