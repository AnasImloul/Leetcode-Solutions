class Solution {
	List<String> res = new ArrayList<>();
	String s;
	int index = 0;
	Set<String> set = new HashSet<>();
    public List<String> wordBreak(String s, List<String> wordDict) {
        this.s = s;
		for (String word: wordDict) set.add(word);
		backtrack("");
		return res;
    }
	public void backtrack(String sentence) {
	    if (index == s.length()) {
	        res.add(sentence.trim());
	        return;
        }
        int indexCopy = index;
        for (int i = index + 1; i <= s.length(); i++) {
	        String str = s.substring(index, i);
	        if (set.contains(str)) {
	            index = i;
	            backtrack(sentence + " " + str);
	            index = indexCopy;
            }
        }
        return;
    }
}
